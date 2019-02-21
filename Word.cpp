#include "Word.h"
#include <algorithm>

//***************************************************************************//
//**							Word	
//***************************************************************************//
Word::Word(const std::wstring & word)
	: m_word(word), m_rects(word.length()), m_foundWord(false), m_transparency(0)
{
	m_buffer.loadFromFile(paths[pCsound]);
	m_music.setBuffer(m_buffer);
}

//***************************************************************************//
//**							draw	
//***************************************************************************//
void Word::draw(sf::RenderWindow & window)
{
	std::for_each(m_rects.begin(), m_rects.end(), [&](MatButton & rect)
	{
		window.draw(rect);
		rect.drawTxt(window);
	});
}

//***************************************************************************//
//**							setSizeAndPos	
//***************************************************************************//
void Word::setSizeAndPos(const sf::Vector2f & size, const sf::Vector2f & pos)
{
	int i = 0;
	int j = (int)m_word.size() - 1;
	std::for_each(m_rects.begin(), m_rects.end(), [&](MatButton & rect)
	{
		rect.setLetter({ m_word[j] });
		rect.setSizeAndPos(size.x, sf::Vector2f( pos.x + i * size.x, pos.y ));
		rect.setSize(size);
		rect.setOutlineThickness(2.3f);
		rect.setOutlineColor(sf::Color(0, 164, 41, 200));

		i++;
		j--;
	});
}

//***************************************************************************//
//**							compare	
//***************************************************************************//
bool Word::compare(const std::wstring & word)
{
	if (m_word == word)
	{
		m_foundWord = true;
		std::for_each(m_rects.begin(), m_rects.end(), [&](MatButton & rect){rect.found();});
		return true;
	}
	return false;
}

//***************************************************************************//
//**							isPermutation	
//***************************************************************************//
bool Word::isPermutation(const std::wstring & word) const
{
	if (word.length() != m_word.length())
		return false;

	return std::is_permutation(word.begin(), word.end(), m_word.begin());
}

//***************************************************************************//
//**							isFound	
//***************************************************************************//
bool Word::isFound() const
{
	return m_foundWord;
}

//***************************************************************************//
//**							hint	
//***************************************************************************//
void Word::hint()
{
	int i = m_rects.size() -1;
	while (i  >=0 && m_rects[i].isFound()) { i--; }
	if (i < m_rects.size())
		m_rects[i].found();
	if (i == 0)
	{
		m_foundWord = true;
		m_music.play();
	}
}
