#include "Help.h"

//***************************************************************************//
//**							Help	
//***************************************************************************//
Help::Help()
{
	m_window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), L"תשחץ מילים",
		sf::Style::Titlebar | sf::Style::Close);
	m_window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - W_WIDTH / 2, 0));
	m_window.setVisible(false);

	m_texture[0].loadFromFile(paths[pBack], sf::IntRect(0, 0, W_WIDTH, W_HEIGHT));
	m_background.setTexture(m_texture[0]);

	m_texture[1].loadFromFile(paths[pBackToGame], sf::IntRect(0, 0, 506, 138));
	m_back.setTexture(m_texture[1]);
	m_back.setPosition(W_WIDTH / 2 - m_back.getGlobalBounds().width / 2, W_HEIGHT - 190);

	m_texture[2].loadFromFile(paths[pPicRecorde], sf::IntRect(0, 0, 407, 472));
	m_picRecorde.setTexture(m_texture[2]);
	m_picRecorde.setScale(0.5, 0.5);
	m_picRecorde.setPosition(W_WIDTH / 2 - m_picRecorde.getGlobalBounds().width / 2, 20);

	m_texture[3].loadFromFile(paths[pPicRecorde], sf::IntRect(0, 0, 407, 472));
	m_picRecorde.setTexture(m_texture[3]);
	m_picRecorde.setScale(0.5, 0.5);
	m_picRecorde.setPosition(W_WIDTH / 2 - m_picRecorde.getGlobalBounds().width / 2, 20);

	m_texture[4].loadFromFile(paths[pHelpTxt], sf::IntRect(0, 0, 530, 747));
	m_help.setTexture(m_texture[4]);
	m_help.setPosition(W_WIDTH / 2 - m_help.getGlobalBounds().width / 2, 25);
}

//***************************************************************************//
//**							run	
//***************************************************************************//
void Help::run()
{
	m_window.setVisible(true);

	while (m_window.isOpen())
	{
		sf::Event event;
		m_window.clear();
	
		m_window.draw(m_background);
	
		draw();
		if (eventHandle(event))
			break;
		
		m_window.display();
	}

	m_window.clear();
}

//***************************************************************************//
//**							draw	
//***************************************************************************//
void Help::draw()
{
	m_window.draw(m_back);
	m_window.draw(m_help);
}

//***************************************************************************//
//**							recorde	
//***************************************************************************//
void Help::runRecorde(const std::vector<std::string>& record)
{
	m_window.setVisible(true);

	while (m_window.isOpen())
	{
		sf::Event event;
		m_window.clear();

		drawRecorde(record);
		if (eventHandle(event))
			break;

		m_window.display();
	}

	m_window.clear();
}

//***************************************************************************//
//**							drawRecorde	
//***************************************************************************//
void Help::drawRecorde(const std::vector<std::string>& record)
{	
	sf::Font font;
	font.loadFromFile(paths[pFont]);

	std::vector<sf::Text> text;
	sf::Text temp;

	m_window.draw(m_background);
	m_window.draw(m_back);
	m_window.draw(m_picRecorde);

	int  i = 0;
	for (auto const & rec : record)
	{
		std::wstring strTmp(rec.begin(), rec.end());
		temp.setString(strTmp);
		setTxt(temp, sf::Color::Black, 70, font, strTmp,
			sf::Vector2f(W_WIDTH / 2 - temp.getGlobalBounds().width / 2, 300 + i * 83), sf::Color::Transparent);
		temp.setPosition(sf::Vector2f(W_WIDTH/2 - temp.getGlobalBounds().width/2 , 300 + i * 83));
		text.push_back(temp);

		i++;
	}

	for(auto const & txt : text)
		m_window.draw(txt);
}

//***************************************************************************//
//**							eventHandle	
//***************************************************************************//
bool Help::eventHandle(sf::Event & event)
{
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.setVisible(false);
			return true;
		case sf::Event::MouseButtonPressed:
		{
			if (contain(m_back, event))
			{
				m_window.setVisible(false);
				return true;
			}
			break;
		}
		default:
			break;
		}
	}
	return false;
}