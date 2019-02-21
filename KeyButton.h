#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "General.h"

class KeyButton :
	public sf::CircleShape
{
public:
	KeyButton();

	void drawTxt(sf::RenderWindow &window);
	void setPos(const sf::Vector2f &pos);
	void setLetter(const std::wstring &letter);
	std::wstring getLetter() const;
	void setPressed(const bool &ressed);
	bool isPressed() const;
	void setSizeText(const double &size);
	void setPosText(const sf::Vector2f & pos);
	void setOutColor(const sf::Color &color);

private:
	sf::Font m_font;
	sf::Text m_text;
	bool m_pressed;
};

