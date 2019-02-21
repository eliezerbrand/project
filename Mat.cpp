#include "Mat.h"
#include <algorithm>
#include "General.h"

//***************************************************************************//
//**							start	
//***************************************************************************//
void Mat::start(std::vector<std::wstring> &words)
{
	if (words.size() == 0)
		return;

	m_mat.clear();
	int level = (int)words[(words.size()) / 2 ].length();
	float indentation = 0.5f * (level - 2.f);
	for (int i = 0; i < words.size(); i++)
		m_mat.push_back(Word(words[i]));
	
	int i = 0;
	sf::Vector2f rectSize = sf::Vector2f((float)MAT_WIDTH / level, (float)MAT_HEIGHT / level);
	std::for_each(m_mat.begin(), m_mat.end(), [&i, &rectSize, &indentation](Word & word)
	{
		word.setSizeAndPos(rectSize, sf::Vector2f(
			(float)MAT_POS_WIDTH + (abs(indentation) * rectSize.x), (float)MAT_POS_HEIGHT + (float)(i * rectSize.y + i * SPASE)));
		indentation -= 0.5;
		i++;
	});
}

//***************************************************************************//
//**							draw	
//***************************************************************************//
void Mat::draw(sf::RenderWindow & window)
{
	std::for_each(m_mat.begin(), m_mat.end(), [&window](Word & word){word.draw(window);});
}

//***************************************************************************//
//**							found	
//***************************************************************************//
bool Mat::found(const std::wstring & checkWord)
{
	bool found = false;

	std::for_each(m_mat.begin(), m_mat.end(),
		[&](Word &word)
	{
		if (word.compare(checkWord))
			found = true;
	});
	return found;
}

//***************************************************************************//
//**							isPermutation	
//***************************************************************************//
bool Mat::isPermutation(const std::wstring & checkWord) const
{
	bool permutation = false;

	std::for_each(m_mat.begin(), m_mat.end(),
		[&](const Word &word)
	{
		if (word.isPermutation(checkWord))
			permutation = true;
	});
	return permutation;
}

//***************************************************************************//
//**							foundAll	
//***************************************************************************//
bool Mat::foundAll() const
{
	bool foundAll = true;
	std::for_each(m_mat.begin(), m_mat.end(),
		[&](const Word &word)
	{
		if (!word.isFound())
			foundAll = false;
	});
	return foundAll;
}

//***************************************************************************//
//**							hint	
//***************************************************************************//
bool Mat::hint()
{
	if (!m_mat[m_mat.size() / 2].isFound())
	{
		m_mat[m_mat.size() / 2].hint();
		return true;
	}

	for (int i = m_mat.size() / 2 + 1, j = m_mat.size() / 2 - 1; i < m_mat.size(), j >= 0; i++, j--)
	{
		if (!m_mat[i].isFound())
		{
			m_mat[i].hint();
			return true;
		}
		if (!m_mat[j].isFound())
		{
			m_mat[j].hint();
			return true;
		}
				
	}

	return false;
}
