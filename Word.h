#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "General.h"
#include "MatButton.h"

class Word
{
public:
	Word(const std::wstring &word);
	void draw(sf::RenderWindow &window);
	void setSizeAndPos(const sf::Vector2f& size, const sf::Vector2f& pos);
	bool compare(const std::wstring &word);
	bool isPermutation(const std::wstring &word) const;
	bool isFound() const;
	void hint();

private:
	std::wstring m_word;
	std::vector<MatButton> m_rects;
	bool m_foundWord;
	int m_transparency;

	sf::SoundBuffer m_buffer;

	sf::Sound m_music;
};

