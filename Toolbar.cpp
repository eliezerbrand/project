#include "Toolbar.h"

//***************************************************************************//
//**							Toolbar	
//***************************************************************************//
Toolbar::Toolbar()
	:m_diamonds(0), m_score(0)
{
	m_texture[0].loadFromFile(paths[pDiamond], sf::IntRect(0, 0, 284, 284));
	m_diamond.setTexture(&m_texture[0]);
	m_diamond.setRadius(BUTTON_SIZE);
	m_diamond.setPos(sf::Vector2f(10.f, KEY_CENTER.y - KEY_RADIUS));
	m_diamond.setSizeText(32);
	m_diamond.setPosText(sf::Vector2f(BUTTON_SIZE, KEY_CENTER.y - KEY_RADIUS - 20));
	m_diamond.setOutColor(sf::Color::Transparent);

	m_texture[1].loadFromFile(paths[pHint], sf::IntRect(0, 0, 284, 284));
	m_hint.setTexture(&m_texture[1]);
	m_hint.setRadius(BUTTON_SIZE);
	m_hint.setPosition(sf::Vector2f(W_WIDTH - BUTTON_SIZE*2-10, KEY_CENTER.y - KEY_RADIUS));

	m_font.loadFromFile(paths[pFont]);
	setTxt(m_text, sf::Color(0, 164, 41, 200), 50, m_font, L"", sf::Vector2f(), sf::Color::Blue);
}

//***************************************************************************//
//**							increaseDiamonds	
//***************************************************************************//
void Toolbar::increaseDiamonds()
{
	m_diamonds++;
}

//***************************************************************************//
//**							draw	
//***************************************************************************//
void Toolbar::draw(sf::RenderWindow & window)
{
	window.draw(m_diamond);
	m_text.setString(std::to_wstring(m_score) + L" דוקינ");
	m_text.setPosition(KEY_CENTER.x - m_text.getGlobalBounds().width / 2, 2);
	m_diamond.setLetter(std::to_wstring(m_diamonds));
	m_diamond.drawTxt(window);
	window.draw(m_text);
	window.draw(m_hint);
}

//***************************************************************************//
//**							eventHandle	
//***************************************************************************//
void Toolbar::eventHandle(Board & board, sf::Event & event)
{
	if (m_hint.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
		if (m_diamonds)
		{
			if(board.getMat().hint())
				m_diamonds--;
		}
}

//***************************************************************************//
//**							addScore	
//***************************************************************************//
void Toolbar::addScore(const int score)
{
	m_score += score;
}

//***************************************************************************//
//**							getScore	
//***************************************************************************//
int Toolbar::getScore() const
{
	return m_score;
}

