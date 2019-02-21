#include "General.h"

//***************************************************************************//
//**							setTxt	
//***************************************************************************//
void setTxt(sf::Text &text, const sf::Color &color, const double &size, const sf::Font &font,
	const std::wstring &string, const sf::Vector2f &pos, const sf::Color &outColor)
{
	text.setFont(font);
	text.setCharacterSize((int)size);
	text.setFillColor(color);
	text.setString(string);
	text.setPosition(pos);
	text.setOutlineColor(outColor);
	text.setOutlineThickness(2);
	text.setStyle(sf::Text::Bold);
}

//***************************************************************************//
//**							contain	
//***************************************************************************//
bool contain(sf::CircleShape circle, sf::Event & event)
{
	if (circle.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
		return true;

	return false;
}

//***************************************************************************//
//**							contain	
//***************************************************************************//
bool contain(sf::Sprite sprite, sf::Event & event)
{
	if (sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
		return true;

	return false;
}