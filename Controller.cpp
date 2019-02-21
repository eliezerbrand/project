#include "Controller.h"
#include <iostream>

//***************************************************************************//
//**							Controller	
//***************************************************************************//
Controller::Controller()
{
	m_foundWords.clear();

	m_window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), L"תשחץ מילים",
		sf::Style::Titlebar | sf::Style::Close);
	m_window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - W_WIDTH / 2, 0));
	m_window.setVisible(false);

	m_buffer[0].loadFromFile(paths[pWsound]);
	m_music[0].setBuffer(m_buffer[0]);
	m_buffer[1].loadFromFile(paths[pCsound]);
	m_music[1].setBuffer(m_buffer[1]);

	m_texture.loadFromFile(paths[pBack], sf::IntRect(0, 0, W_WIDTH, W_HEIGHT));
	m_background.setTexture(m_texture);
}

//***************************************************************************//
//**							run	
//***************************************************************************//
void Controller::run(const Dictionary &dictionary, const int &level)
{
	m_window.setVisible(true);

	std::vector<std::wstring> mat;
	findWord(dictionary, level, mat);
	std::vector<std::wstring> sortMat;
	for (int i = 0; i <= mat.size(); i += 2)
		sortMat.push_back(mat[i]);
	for (int i = (int)mat.size() -2; i > 0; i -= 2)
		sortMat.push_back(mat[i]);

	if (mat.size() == 0)
		return;
	m_keyboard.start(sortMat[(sortMat.size()) / 2]);
	m_board.start(sortMat, level);

	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.draw(m_background);
		m_board.draw(m_window);
		m_keyboard.draw(m_window);
		m_toolbar.draw(m_window);
		m_window.display();
		if (m_board.getMat().foundAll())
			break;

		sf::Event event;
		if (eventHandle(dictionary, event))
			return;
	}

	m_toolbar.addScore(50);
	sf::sleep(sf::seconds(1));
}

//***************************************************************************//
//**							eventHandle	
//***************************************************************************//
bool Controller::eventHandle(const Dictionary &dictionary, sf::Event &event)
{
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.setVisible(false);
			return true;
		}
		if (event.type == sf::Event::MouseButtonPressed)
			m_toolbar.eventHandle(m_board, event);

		m_keyboard.eventHandle(*this, dictionary, m_window, event);
	}
	return false;
}

//***************************************************************************//
//**							findWord	
//***************************************************************************//
bool Controller::findWord(const Dictionary &dictionary, const int len, std::vector<std::wstring>& mat)
{
	std::wstring word;

	do
	{
		word = dictionary.randWord(len);
	} while (!findWords(dictionary, len, word, word, mat));

	mat.push_back(word);
	return true;
}

//***************************************************************************//
//**							findWords	
//***************************************************************************//
bool Controller::findWords(const Dictionary &dictionary, const int len, std::wstring word1, std::wstring word2, std::vector<std::wstring>& mat)
{
	std::wstring w1, w2;
	if(len == 2)
		return true;

	for (int i = 0;i < len; i++)
	{
		if (!dictionary.search(w1))
		{
			w1 = L"";
			std::sort(word1.begin(), word1.end());
		}
		w2 = L"";
		std::sort(word2.begin(), word2.end());

		if (!dictionary.search(w1))
			for (int j = 0; j < len; j++)
			{
				if (i == j)
					continue;
				w1 += word1[j];
			}

		for (int j = 0; j < len; j++)
		{
			if (i == j)
				continue;
			w2 += word2[j];
		}

		do
		{
			if (dictionary.search(w1))
				break;
		} while (std::next_permutation(w1.begin(), w1.end()));

		if (!dictionary.search(w1))
			continue;

		do
		{
			if (w2 == w1)
				continue;
			if (dictionary.search(w2))
				break;
		} while (std::next_permutation(w2.begin(), w2.end()));

		if (w2 == w1 || !dictionary.search(w2))
			continue;

		if (findWords(dictionary, len - 1, w1, w2, mat))
		{
			mat.push_back(w1);
			mat.push_back(w2);
			return true;
		}
	}
	return false;
}

//***************************************************************************//
//**							compare	
//***************************************************************************//
void Controller::compare(const Dictionary &dictionary, const std::wstring & word)
{
	if (!m_board.getMat().found(word))
	{
		if (dictionary.search(word) && m_foundWords.find(word) == m_foundWords.end())
		{
			m_foundWords.insert(word);
			m_toolbar.increaseDiamonds();
		}
	}
	else if(m_foundWords.find(word) == m_foundWords.end())
	{
		m_foundWords.insert(word);
		m_toolbar.addScore(10);
		m_music[1].play();
	}
}

//***************************************************************************//
//**							setVisible	
//***************************************************************************//
void Controller::setVisible(const bool visible)
{
	m_window.setVisible(visible);
}

//***************************************************************************//
//**							getScore	
//***************************************************************************//
int Controller::getScore() const
{
	return m_toolbar.getScore();
}
