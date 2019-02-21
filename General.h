#pragma once
#include <string>
#include <SFML/Graphics.hpp>

const int UNICODE_CHAR = 1264;
const int NUM_OF_LEVELS = 5;

////////////////////////////////////////////
const int DICT_KIND = 2;

const std::string pathFile[DICT_KIND] = {
	"bible.txt",
	"dictionary-h.txt",
};
////////////////////////////////////////////

////////////////////////////////////////////
// The width of the board.
const int W_WIDTH = 600;
// The height of the board.
const int W_HEIGHT = sf::VideoMode::getDesktopMode().height - 120;
////////////////////////////////////////////

////////////////////////////////////////////
const int MAT_WIDTH = 300;
const int MAT_HEIGHT = 300;

const int MAT_POS_WIDTH = W_WIDTH / 2 - MAT_WIDTH / 2;
const int MAT_POS_HEIGHT = 70;

const double SPASE = 4.6;

const int BUTTON_SIZE = 40;
////////////////////////////////////////////

////////////////////////////////////////////
const sf::Vector2f KEY_CENTER(W_WIDTH / 2.f, W_HEIGHT - 180.f);
const int KEY_RADIUS = 100;
const float KEY_SIZE = 30;
////////////////////////////////////////////

////////////////////////////////////////////
enum ButtunType { buttunPlay, buttunRecord, buttunSound, buttunHelp, MAX_OF_BUTTUNS };
enum Paths {pFont, pBack, pMenu, pName, pPlay, pRecord, pSound, pHelp, pLevel, pPan, pRotate,
	pBackToGame, pNotSound, pHint, pWsound, pCsound, pAgain, pDiamond, pChoiceGame1, pChoiceGame2,
	pMusic, pRecordes, pNextLevel, pSameLevel, pPicRecorde, pHelpTxt};
////////////////////////////////////////////

////////////////////////////////////////////
const std::string paths[26] = {
	"resources/font/arial.ttf",
	"resources/picture/background.jpg",
	"resources/picture/menu.png",
	"resources/picture/gameName.png",
	"resources/picture/play.png",
	"resources/picture/record.png",
	"resources/picture/sound.png",
	"resources/picture/help.png",
	"resources/picture/level.png",
	"resources/picture/pan.png",
	"resources/picture/rotate.png",
	"resources/picture/backToGame.png",
	"resources/picture/notSound.png",
	"resources/picture/hint.png",
	"resources/sounds/wrong-answer.wav",
	"resources/sounds/correct-answer.wav",
	"resources/picture/again.png",
	"resources/picture/diamond.png",
	"resources/picture/choiceGame1.png",
	"resources/picture/choiceGame2.png",
	"resources/sounds/music.ogg",
	"resources/recordes.txt",
	"resources/picture/nextLevel.png",
	"resources/picture/sameLevel.png",	
	"resources/picture/rec.png",
	"resources/picture/helpTxt.png",
};
////////////////////////////////////////////

////////////////////////////////////////////
void setTxt(sf::Text &text, const sf::Color &color, const double &size, const sf::Font &font,
	const std::wstring &string, const sf::Vector2f &pos, const sf::Color &outColor);

bool contain(sf::CircleShape sprite, sf::Event & event);

bool contain(sf::Sprite sprite, sf::Event & event);
////////////////////////////////////////////