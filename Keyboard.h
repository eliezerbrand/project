#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "KeyButton.h"
#include "Dictionary.h"

class Controller;

class Keyboard
{
public:
	void eventHandle(Controller &controller, const Dictionary &dictionary, sf::RenderWindow &window, sf::Event & event);
	void start(const std::wstring &letters);
	void draw(sf::RenderWindow &window);
	void mixButtons();

private:
	std::vector<KeyButton> m_keyboard;
	sf::Text m_inputText;
	sf::Font m_font;
	std::wstring m_input;
	sf::Texture m_texture1;
	sf::Texture m_texture2;
	sf::RectangleShape m_pan;
	sf::CircleShape m_mixButton;
};

