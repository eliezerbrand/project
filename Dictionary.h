#pragma once
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <string>
#include <fstream>
#include "General.h"

using words = std::unordered_set<std::wstring>;
using dict = std::unordered_map<size_t, words>;

class Dictionary
{
public:
	bool readFile(std::string);
	bool search(const std::wstring &word) const;
	std::wstring randWord(const int len) const;
	wchar_t finalLetters(const wchar_t & letter) const;

private:
	dict m_dict;
};

