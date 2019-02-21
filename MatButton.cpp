#include "MatButton.h"

//***************************************************************************//
//**							MatButton	
//***************************************************************************//
MatButton::MatButton()
	:m_found(false)
{
	m_font.loadFromFile(paths[pFont]);
}

//***************************************************************************//
//**							drawTxt	
//***************************************************************************//
void MatButton::drawTxt(sf::RenderWindow & window)
{
	if(m_found)
		window.draw(m_text);
}

//***************************************************************************//
//**							setSizeAndPos	
//***************************************************************************//
void MatButton::setSizeAndPos(const double size, const sf::Vector2f & pos)
{
	setPosition(pos);
	m_text.setPosition(pos);

	setTxt(m_text, sf::Color::Blue, size, m_font, m_text.getString(),
		sf::Vector2f(pos.x + size / 4.f, pos.y - size / 4.f), sf::Color(0,164,41,200));
}

//***************************************************************************//
//**							setLetter	
//***************************************************************************//
void MatButton::setLetter(const std::wstring & letter)
{
	m_text.setString(letter);
}

//***************************************************************************//
//**							getLetter	
//***************************************************************************//
std::wstring MatButton::getLetter() const
{
	return m_text.getString();
}

//***************************************************************************//
//**							found	
//***************************************************************************//
void MatButton::found()
{
	m_found = true;
}

//***************************************************************************//
//**							isFound	
//***************************************************************************//
bool MatButton::isFound() const
{
	return m_found;
}