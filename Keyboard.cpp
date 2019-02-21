#include "Keyboard.h"
#include <algorithm>
#include "General.h"
#include <math.h>
#include <iostream>
#include <random>
#include "Controller.h"

//***************************************************************************//
//**							eventHandle	
//***************************************************************************//
void Keyboard::eventHandle(Controller &controller, const Dictionary &dictionary, sf::RenderWindow &window, sf::Event & event)
{
	static bool pressed = false;

	switch (event.type)
	{
	case sf::Event::EventType::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Button::Left)
		{
			pressed = true;

			if (m_mixButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				mixButtons();
		}
		break;
	case sf::Event::EventType::MouseButtonReleased:
		if (pressed && event.mouseButton.button == sf::Mouse::Button::Left)
		{
			controller.compare(dictionary, m_input);
			m_input = L"";
			pressed = false;
			std::for_each(m_keyboard.begin(), m_keyboard.end(),[&](KeyButton &button){button.setPressed(false);});
		}
		break;
	}

	if (pressed)
	{
		std::for_each(m_keyboard.begin(), m_keyboard.end(),
			[&](KeyButton &button)
		{
			if (!button.isPressed() && button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				button.setPressed(true);
				m_input += button.getLetter();
			}
		});
	}
}

//***************************************************************************//
//**							start	
//***************************************************************************//
void Keyboard::start(const std::wstring & letters)
{
	m_texture1.loadFromFile(paths[pRotate], sf::IntRect(0, 0, 284, 284));
	m_mixButton.setTexture(&m_texture1);
	m_mixButton.setRadius(BUTTON_SIZE);
	m_mixButton.setPosition(10, W_HEIGHT -m_mixButton.getRadius() * 2 -10);

	m_texture2.loadFromFile(paths[pPan]);
	m_pan.setTexture(&m_texture2);
	m_pan.setSize(sf::Vector2f(KEY_RADIUS * 3.1, KEY_RADIUS * 3.1));
	m_pan.setPosition(sf::Vector2f(W_WIDTH /2.f - m_pan.getSize().x /2.f, KEY_CENTER.y - m_pan.getSize().y / 2.4f));

	m_font.loadFromFile(paths[pFont]);
	setTxt(m_inputText, sf::Color::Blue, KEY_SIZE * 1.5, m_font, m_input, sf::Vector2f(), sf::Color::Red);

	float different = ((2.f * std::acos(-1)) / letters.length());
	float degree = 0.f;

	m_keyboard.resize(letters.length() , KeyButton());

	int i = 0;
	std::for_each(m_keyboard.begin(), m_keyboard.end(),
		[&](KeyButton &rect)
	{
		rect.setLetter({ letters[i] });
		rect.setRadius(KEY_SIZE);
		rect.setPos({ KEY_CENTER.x + std::cos(degree) * KEY_RADIUS - (KEY_SIZE),
			KEY_CENTER.y + std::sin(degree) * KEY_RADIUS });

		i++;
		degree += different;
	});
	mixButtons();
}

//***************************************************************************//
//**							draw	
//***************************************************************************//
void Keyboard::draw(sf::RenderWindow & window)
{
	window.draw(m_pan);

	std::for_each(m_keyboard.begin(), m_keyboard.end(), [&window](KeyButton &rect){rect.drawTxt(window);});

	window.draw(m_mixButton);
	std::wstring temp(m_input);
	std::reverse(temp.begin(), temp.end());
	m_inputText.setString(temp);
	m_inputText.setPosition(KEY_CENTER.x - m_inputText.getGlobalBounds().width /2, m_pan.getPosition().y - 50);
	window.draw(m_inputText);
}

//***************************************************************************//
//**							mixButtons	
//***************************************************************************//
void Keyboard::mixButtons()
{
	int i = 0;
	std::vector<std::wstring> chars;
	std::for_each(m_keyboard.begin(), m_keyboard.end(), [&chars](const KeyButton &button) {chars.push_back(button.getLetter()); });
	std::random_shuffle(chars.begin(), chars.end());
	std::for_each(m_keyboard.begin(), m_keyboard.end(), [&chars, &i](KeyButton &text) {text.setLetter(chars[i]); i++; });
}
