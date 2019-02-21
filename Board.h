#pragma once
#include "Mat.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Board
{
public:
	void start(std::vector<std::wstring> &words, const int level);
	void draw(sf::RenderWindow & window);
	Mat& getMat();

private:
	Mat m_mat;
};

