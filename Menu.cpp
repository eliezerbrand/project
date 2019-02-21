#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//***************************************************************************//
//**							C - tor	
//***************************************************************************//
Menu::Menu()
	:m_statusPlay(false), m_statusSound(true), chiceGame(false)
{
	m_music.openFromFile(paths[pMusic]);
	m_music.setVolume(50);         // reduce the volume
	m_music.setLoop(true);         // make it loop		
	m_music.play();

	m_font.loadFromFile(paths[pFont]);
	m_text.setString(L"50 דוקינ");
	setTxt(m_text, sf::Color::Green, 50, m_font, L"50 דוקינ",
		sf::Vector2f(KEY_CENTER.x -80, 2), sf::Color::Blue);

	m_window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), L"תשחץ מילים",
		sf::Style::Titlebar | sf::Style::Close);
	m_window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - W_WIDTH / 2, 0));

	m_windowN_Level.create(sf::VideoMode(W_WIDTH, W_HEIGHT / 4), L"מעבר שלב",
		sf::Style::Titlebar);
	m_windowN_Level.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - W_WIDTH / 2, sf::VideoMode::getDesktopMode().height / 3 - (W_HEIGHT / 4) / 3));


	m_texture[0].loadFromFile(paths[pBack], sf::IntRect(0, 0, W_WIDTH, W_HEIGHT));
	m_background.setTexture(m_texture[0]);

	m_texture[1].loadFromFile(paths[pPlay], sf::IntRect(0, 0, 284, 284));
	m_nextLevel.setTexture(&m_texture[1]);
	m_nextLevel.setPosition(sf::Vector2f(m_windowN_Level.getSize().x - BUTTON_SIZE * 3, m_windowN_Level.getSize().y - BUTTON_SIZE * 2));
	m_nextLevel.setRadius(BUTTON_SIZE);

	m_texture[2].loadFromFile(paths[pAgain], sf::IntRect(0, 0, 225, 225));
	m_returnLevel.setTexture(&m_texture[2]);
	m_returnLevel.setPosition(sf::Vector2f(BUTTON_SIZE, m_windowN_Level.getSize().y - BUTTON_SIZE * 2));
	m_returnLevel.setRadius(BUTTON_SIZE);

	m_texture[3].loadFromFile(paths[pMenu], sf::IntRect(0, 0, 284, 284));
	m_backToMenu2.setTexture(&m_texture[3]);
	m_backToMenu2.setPosition(sf::Vector2f(BUTTON_SIZE, BUTTON_SIZE / 2));
	m_backToMenu2.setRadius(BUTTON_SIZE);

	m_texture[4].loadFromFile(paths[pNextLevel], sf::IntRect(0, 0, 246, 41));
	m_nextLevelTxt.setTexture(m_texture[4]);
	m_nextLevelTxt.setPosition(sf::Vector2f(m_nextLevel.getPosition().x - 20, m_nextLevel.getPosition().y - 25));
	m_nextLevelTxt.setScale(0.5, 0.5);

	m_texture[5].loadFromFile(paths[pSameLevel], sf::IntRect(0, 0, 160, 79));
	m_againLevelTxt.setTexture(m_texture[5]);
	m_againLevelTxt.setPosition(sf::Vector2f(m_returnLevel.getPosition().x, m_returnLevel.getPosition().y - 40));
	m_againLevelTxt.setScale(0.5, 0.5);

	for (int i = 0; i < DICT_KIND; i++)
	{
		m_textureDict[i].loadFromFile(paths[pChoiceGame1 + i], sf::IntRect(0, 0, 497, 131));
		m_dictKind[i].setTexture(m_textureDict[i]);
		m_dictKind[i].setPosition(sf::Vector2f(W_WIDTH / 2 - m_dictKind[i].getGlobalBounds().width / 2,
			W_HEIGHT / 2 - m_dictKind[i].getGlobalBounds().height + i * (m_dictKind[i].getGlobalBounds().height + 10)));
	}
}

//***************************************************************************//
//**							run	
//***************************************************************************//
void Menu::run()
{
	m_windowN_Level.clear();
	m_windowN_Level.draw(m_nextLevel);
	m_windowN_Level.draw(m_backToMenu2);
	m_windowN_Level.setVisible(false);

	while (m_window.isOpen())
	{
		sf::Event event;
		m_window.clear();
		
		m_window.draw(m_background);

		if (!m_statusPlay)
		{
			drawMenu();
			eventHandleMenu(event);
		}
		else
		{
			drawLevels();
			eventHandleLevel(event);
		}

		m_window.display();
	}

	recordes();
}

//***************************************************************************//
//**							gameSelection	
//***************************************************************************//
void Menu::gameSelection()
{
	while (m_window.isOpen())
	{
		sf::Event event;
		m_window.clear();

		m_window.draw(m_background);
		for (int i = 0; i < DICT_KIND; i++)
		{
			m_window.draw(m_dictKind[i]);
		}
	
		while (m_window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				m_window.close();
			else if(event.type == sf::Event::MouseButtonPressed)
				for (int i = 0; i < DICT_KIND; i++)
					if (contain(m_dictKind[i], event))
					{
						m_dictionary.readFile(pathFile[i]);
						chiceGame = true;
						return;
					}
		}
		m_window.display();
	}
}

//***************************************************************************//
//**							drawMenu	
//***************************************************************************//
void Menu::drawMenu()
{
	sf::Texture texture[5];
	sf::Vector2f position[4];

	texture[0].loadFromFile(paths[pName], sf::IntRect(0, 0, 506, 138));
	m_gameName.setTexture(texture[0]);
	m_gameName.setPosition(W_WIDTH / 2 - m_gameName.getGlobalBounds().width / 2, 50);
	m_window.draw(m_gameName);

	for (int i = 0; i < 4; i++)
	{
		if(m_statusSound == false && pPlay - i == buttunSound)
			texture[i].loadFromFile(paths[12], sf::IntRect(0, 0, 285, 285));
		else
			texture[i].loadFromFile(paths[i + pPlay], sf::IntRect(0, 0, 285, 285));
		m_options[i].setTexture(&texture[i]);
		position[i] = sf::Vector2f(i * 130.f, (W_HEIGHT / 4.f) * 3.f);
		m_options[buttunPlay + i].setRadius(BUTTON_SIZE);
	}

	m_options[buttunPlay].setRadius(BUTTON_SIZE*4);
	position[buttunPlay] = sf::Vector2f(W_WIDTH / 2.f - m_options[0].getGlobalBounds().width / 2.f, W_HEIGHT / 3.f);

	for (int i = 0; i < 4; i++)
	{
		m_options[i].setPosition(position[i]);
		m_window.draw(m_options[i]);
	}
}

//***************************************************************************//
//**							drawLevels	
//***************************************************************************//
void Menu::drawLevels()
{
	sf::Texture texture;

	texture.loadFromFile(paths[pLevel], sf::IntRect(0, 0, 506, 138));

	// Load the text font
	sf::Font font;
	font.loadFromFile(paths[pFont]);

	std::wstring numLevel;

	float place = (float)W_HEIGHT / NUM_OF_LEVELS;

	for (int i = 0; i < NUM_OF_LEVELS; i++)
	{
		numLevel = intToString(i + 1);

		m_level[i].setTexture(texture);
		m_level[i].setScale(4.f / NUM_OF_LEVELS, 4.f / NUM_OF_LEVELS);
		m_level[i].setPosition(W_WIDTH / 2 - m_level[i].getGlobalBounds().width / 2, i * place + 30);

		setTxt(numOfLevel, sf::Color::Black, 200 / NUM_OF_LEVELS, font,
			numLevel += L"  ה מ ר  ", sf::Vector2f(W_WIDTH / 2 - numOfLevel.getGlobalBounds().width / 2 +10,
				m_level[i].getPosition().y +  m_level[i].getGlobalBounds().height/2 - numOfLevel.getCharacterSize() / 2), sf::Color::White);

		m_window.draw(m_level[i]);
		m_window.draw(numOfLevel);
	}

	texture.loadFromFile(paths[pMenu], sf::IntRect(0, 0, 285, 285));
	m_backToMenu.setTexture(&texture);
	m_backToMenu.setRadius(BUTTON_SIZE);
	m_backToMenu.setPosition(20, 20);
	m_window.draw(m_backToMenu);
}

//***************************************************************************//
//**							readFile	
//***************************************************************************//
void Menu::readFileRecorde()
{
	std::string line;
	std::ifstream myFile(paths[pRecordes]);

	std::vector <std::string> record;

	while (std::getline(myFile, line))
	{
		if (line.empty())
			continue;

		record.push_back(line);
	}

	m_help.runRecorde(record);

	myFile.close();
}

//***************************************************************************//
//**							eventHandleMenu	
//***************************************************************************//
void Menu::eventHandleMenu(sf::Event & event)
{
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::MouseButtonPressed:
		{
			if (contain(m_options[buttunPlay], event))
			{
				if(!chiceGame)
					gameSelection();
				m_statusPlay = true;
			}
			else if (contain(m_options[buttunRecord], event))
			{
				m_window.setVisible(false);
				readFileRecorde();
				m_window.setVisible(true);
			}
			else if (contain(m_options[buttunSound], event))
			{
				if (m_statusSound)
				{
					m_statusSound = false;
					m_music.stop();
				}
				else
				{
					m_statusSound = true;
					m_music.play();
				}
			}
			else if (contain(m_options[buttunHelp], event))
			{
				m_window.setVisible(false);
				m_help.run();
				m_window.setVisible(true);
			}
			break;
		}
		default:
			break;
		}
	}
}

//***************************************************************************//
//**							eventHandleLevel	
//***************************************************************************//
void Menu::eventHandleLevel(sf::Event & event)
{
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::MouseButtonPressed:
		{
			for (int i = 0; i < NUM_OF_LEVELS; i++)
			{
				if (contain(m_level[i], event))
				{
					m_numLevel = i + 3;
					m_window.setVisible(false);
					m_controller.run(m_dictionary, m_numLevel);
					eventHandlePlay();
					m_window.setVisible(true);
				}
			}
			if (contain(m_backToMenu, event))
				m_statusPlay = false;
		}
		default:
			break;
		}
	}
}

//***************************************************************************//
//**							eventHandlePlay	
//***************************************************************************//
void Menu::eventHandlePlay()
{
	m_windowN_Level.setVisible(true);

	while (true)
	{
		sf::Event event;
		m_windowN_Level.clear();
		m_windowN_Level.draw(m_background);
		m_windowN_Level.draw(m_text);
		m_windowN_Level.draw(m_backToMenu2);
		m_windowN_Level.draw(m_nextLevel);
		m_windowN_Level.draw(m_returnLevel);
		m_windowN_Level.draw(m_nextLevelTxt);
		m_windowN_Level.draw(m_againLevelTxt);
		m_windowN_Level.display();

		while (m_windowN_Level.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_windowN_Level.close();
				return;
			case sf::Event::MouseButtonPressed:
				if (contain(m_backToMenu2, event))
				{
					m_windowN_Level.setVisible(false);
					m_controller.setVisible(false);
					return;
				}
				if (contain(m_nextLevel, event))
				{
					m_windowN_Level.setVisible(false);
					m_controller.run(m_dictionary, ++m_numLevel);
					m_windowN_Level.setVisible(true);
				}
				if(contain(m_returnLevel, event))
				{
					m_windowN_Level.setVisible(false);
					m_controller.run(m_dictionary, m_numLevel);
					m_windowN_Level.setVisible(true);
				}
				break;
			}
		}
	}
}

//***************************************************************************//
//**						intToString	
//***************************************************************************//
std::wstring Menu::intToString(const int num)
{
	std::wostringstream oString;
	oString << num;
	return oString.str();
}
//***************************************************************************//
//**						recordes	
//***************************************************************************//
void Menu::recordes()
{
	std::fstream myFile;
	std::string line;
	std::vector<std::string> recordes;

	myFile.open(paths[pRecordes], std::ios::in);
	while (std::getline(myFile, line))
		recordes.push_back(line);

	for (int i = 0; i < recordes.size(); i++)
		if (m_controller.getScore() > std::stoi(recordes[i]))
		{
			for (int j = recordes.size() - 1; j >= i+1; j--)
				recordes[j] = recordes[j - 1];

			recordes[i] = std::to_string(m_controller.getScore());
			break;
		}
			
	myFile.close();
	myFile.open(paths[pRecordes], std::ios::out);
	for (const auto & score : recordes)
		myFile << score << std::endl;

	myFile.close();
}
