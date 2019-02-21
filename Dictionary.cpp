#include "Dictionary.h"
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>

//***************************************************************************//
//**							readFile	
//***************************************************************************//
bool Dictionary::readFile(std::string path)
{
	std::wstring line;
	std::wifstream myFile(path);

	while(std::getline(myFile , line))
	{
		if (line.empty() || line.length() < 2)
			continue;

		std::for_each(line.begin(), line.end(), [](wchar_t &ch) {ch += UNICODE_CHAR; });
		line[line.length() -1] = finalLetters(line[line.length() -1]);
		m_dict[line.length()].insert(words::value_type(line));
	}

	myFile.close();
	return 0;
}

//***************************************************************************//
//**							search	
//***************************************************************************//
bool Dictionary::search(const std::wstring & searchWord) const
{
	if (m_dict.find(searchWord.length()) == m_dict.end())
		return false;

	return m_dict.at(searchWord.length()).find(searchWord) != m_dict.at(searchWord.length()).end();
}

//***************************************************************************//
//**							randWord	
//***************************************************************************//
std::wstring Dictionary::randWord(const int len) const
{
	int index = rand() % m_dict.at(len).size();
	words::iterator it = m_dict.at(len).begin();

	for (int i = 0; i < index; i++)
		it++;

	return *it;
	
}

//***************************************************************************//
//**							finalLetters	
//***************************************************************************//
wchar_t Dictionary::finalLetters(const wchar_t & letter) const
{
	switch (letter)
	{
	case L'ך':
		return L'כ';
		break;
	case L'ם':
		return L'מ';
		break;
	case L'ן':
		return L'נ';
		break;
	case L'ף':
		return L'פ';
		break;
	case L'ץ':
		return L'צ';
		break;
	default:
		break;
	}
	return letter;
}
