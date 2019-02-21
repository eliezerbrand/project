#pragma once
#include "Controller.h"
#include <string.h>
#include <fstream>
#include <sstream>
#include "General.h"
#include "Dictionary.h"
#include "Help.h"
#include <SFML/Audio.hpp>
#include <vector>

class Menu
{
public:

	Menu();

	void run();

	void gameSelection();

	void drawMenu();

	void drawLevels();

	void readFileRecorde();

	void eventHandleMenu(sf::Event & event);

	void eventHandleLevel(sf::Event & event);

	void eventHandlePlay();

	std::wstring intToString(const int num);

	void recordes();

private:
	Controller m_controller;

	Dictionary m_dictionary;

	Help m_help;

	sf::RenderWindow m_window;
	sf::Music m_music;
	sf::RenderWindow m_windowN_Level;
	sf::Sprite m_background;
	sf::Sprite m_gameName;
	sf::Sprite m_dictKind[DICT_KIND];
	sf::Text numOfLevel;
	sf::Sprite m_level[NUM_OF_LEVELS];
	sf::Sprite m_nextLevelTxt;
	sf::Sprite m_againLevelTxt;
	sf::CircleShape m_options[MAX_OF_BUTTUNS];
	sf::CircleShape m_backToMenu;
	sf::CircleShape m_backToMenu2;
	sf::CircleShape m_nextLevel;
	sf::CircleShape m_returnLevel;
	sf::Font m_font;
	sf::Text m_text;
	sf::Texture m_texture[6];
	sf::Texture m_textureDict[DICT_KIND];

	bool chiceGame;
	bool m_statusPlay;
	bool m_statusSound;
	int m_numLevel;
};



