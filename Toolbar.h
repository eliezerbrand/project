#pragma once
#include "KeyButton.h"
#include "General.h"
#include "Board.h"

class Toolbar
{
public:
	Toolbar();

	void increaseDiamonds();
	void draw(sf::RenderWindow &window);
	void eventHandle(Board &dictionary, sf::Event &event);
	void addScore(const int score);
	int getScore() const;

private:
	int m_diamonds;
	KeyButton m_diamond;
	sf::CircleShape m_hint;
	sf::Texture m_texture[2];
	sf::Font m_font;
	sf::Text m_text;
	int m_score;
};

