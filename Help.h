#pragma once
#include "General.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Help
{
public:
	Help();
	void run();
	void draw();
	void runRecorde(const std::vector<std::string>& record);
	void drawRecorde(const std::vector<std::string>& record);
	bool eventHandle(sf::Event & event);

private:
	sf::RenderWindow m_window;
	sf::Sprite m_background;
	sf::Texture m_texture[5];
	sf::Sprite m_picRecorde;
	sf::Sprite m_help;
	sf::Sprite m_back;
};

