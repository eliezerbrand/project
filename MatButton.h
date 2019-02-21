#pragma once
#include <SFML/Graphics.hpp>
#include "General.h"

class MatButton
	: public sf::RectangleShape
{
public:
	MatButton();

	void drawTxt(sf::RenderWindow &window);
	void setSizeAndPos(const double size, const sf::Vector2f & pos);
	void setLetter(const std::wstring &letter);
	std::wstring getLetter() const;
	void found();
	bool isFound() const;

private:
	sf::Font m_font;
	sf::Text m_text;
	bool m_found;
};

