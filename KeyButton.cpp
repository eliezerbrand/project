#include "KeyButton.h"

//***************************************************************************//
//**							KeyButton	
//***************************************************************************//
KeyButton::KeyButton()
	:m_pressed(false)
{
	m_font.loadFromFile(paths[pFont]);
}

//***************************************************************************//
//**							drawTxt	
//***************************************************************************//
void KeyButton::drawTxt(sf::RenderWindow & window)
{
	window.draw(m_text);
}

//***************************************************************************//
//**							setPos	
//***************************************************************************//
void KeyButton::setPos(const sf::Vector2f & pos)
{
	setPosition(pos);
	m_text.setPosition(pos);

	setTxt(m_text, sf::Color::Blue, KEY_SIZE * 2, m_font, m_text.getString(),
		sf::Vector2f(getPosition().x + KEY_SIZE / 2, getPosition().y - KEY_SIZE /2), sf::Color::Blue);
}

//***************************************************************************//
//**							setLetter	
//***************************************************************************//
void KeyButton::setLetter(const std::wstring & letter)
{
	m_text.setString(letter);
}

//***************************************************************************//
//**							getLetter	
//***************************************************************************//
std::wstring KeyButton::getLetter() const
{
	return m_text.getString();
}

//***************************************************************************//
//**							setPressed	
//***************************************************************************//
void KeyButton::setPressed(const bool & pressed)
{
	sf::Color color = (pressed) ? sf::Color::Red : sf::Color::Blue;
	
	m_text.setFillColor(color);
	m_pressed = pressed;
}

//***************************************************************************//
//**							isPressed	
//***************************************************************************//
bool KeyButton::isPressed() const
{
	return m_pressed;
}

//***************************************************************************//
//**							setSizeText	
//***************************************************************************//
void KeyButton::setSizeText(const double & size)
{
	m_text.setCharacterSize(size);
}

//***************************************************************************//
//**							setPosText	
//***************************************************************************//
void KeyButton::setPosText(const sf::Vector2f & pos)
{
	m_text.setPosition(pos);
}

//***************************************************************************//
//**							setOutColor	
//***************************************************************************//
void KeyButton::setOutColor(const sf::Color & color)
{
	m_text.setOutlineColor(color);
}
