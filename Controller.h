#pragma once
#include "Board.h"
#include "Dictionary.h"
#include <vector>
#include <string>
#include "Toolbar.h"
#include "Keyboard.h"
#include <SFML/Audio.hpp>

class Controller
{
public:
	Controller();
	void run(const Dictionary &dictionary, const int &level);
	bool eventHandle(const Dictionary &dictionary, sf::Event &event);
	bool findWord(const Dictionary &dictionary, const int len, std::vector<std::wstring>& mat);
	bool findWords(const Dictionary &dictionary, const int len, std::wstring word1, std::wstring word2, std::vector<std::wstring>& mat);
	void compare(const Dictionary &dictionary, const std::wstring &word);
	void setVisible(const bool visible);
	int getScore() const;

private:
	// Holding the object that holds all the objects on the board.
	Board m_board;

	Toolbar m_toolbar;

	Keyboard m_keyboard;

	sf::RenderWindow m_window;

	words m_foundWords;

	sf::SoundBuffer m_buffer[2];

	sf::Sound m_music[2];

	sf::Texture m_texture;

	sf::Sprite m_background;
};

