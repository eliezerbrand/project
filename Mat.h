#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Word.h"

class Mat
{
public:
	void start(std::vector<std::wstring> &words);
	void draw(sf::RenderWindow &window);
	bool found(const std::wstring &word);
	bool isPermutation(const std::wstring &word) const;
	bool foundAll() const;
	bool hint();

private:
	std::vector<Word> m_mat;
};

