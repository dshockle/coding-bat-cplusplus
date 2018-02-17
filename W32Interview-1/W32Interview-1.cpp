// W32Interview-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
Helper function
*/
string mapString(map<char, int> m)
{
	string sb;
	std::map<char, int>::iterator mit;

	for (mit = m.begin(); mit != m.end(); ++mit) {
		sb += mit->first;
		sb += " => ";
		sb += to_string(mit->second);
		sb += "\n";
	}

	return sb;
}

string mapString(map<string, int> counts)
{
	string sb;
	std::map<string, int>::iterator it;

	for (it = counts.begin(); it != counts.end(); ++it)
		sb += it->first + " => " + to_string(it->second) + "\n";

	return sb;
}

/*
cout << ("isPalindrome");
cout << ("Is it a palindrome ignoring punctuation and case.");
cout << boolalpha << (isPalindrome("A man, a plan, a canal: panama!") == true);
*/
bool isPalindrome(string word)
{
	string sb;

	for (char ch : word)
	{
		if (isalnum(ch))
			sb += tolower(ch);
	}

	for (unsigned int i = 0; i < sb.length() / 2; i++)
		if (sb[i] != sb[sb.length() - 1 - i])
			return false;

	return true;
}

/*
cout << ("countLetters");
cout << ("Count times each letter appears in string");
cout << boolalpha << (countLetters("The quick brown fox jumped over the lazy dogs."));
*/
string countLetters(string sentence)
{
	map<char, int> letterCounts;
	//car.insert(pair<string, string>("Smith", "Ford"));

	for(char ch : sentence)
	{
		if (isalnum(ch))
		{
			char c = tolower(ch);

			if (letterCounts.find(c) != letterCounts.end())
				letterCounts[c] = letterCounts[c] + 1;
			else
				letterCounts.insert(std::pair<char, int>(c, 1));
		}
	}

	return mapString(letterCounts);
}

/*
cout << ("countWords");
cout << ("Count times each word appears in string");
cout << boolalpha << (countWords("This is fun and this is easy"));
*/
string countWords(string sentence)
{
	map<string, int> counts;
	std::map<string, int>::iterator it;
	char split_char = ' ';

	// split sentence into vector
	std::istringstream split(sentence);
	std::vector<string> tokens;
	for (string each; std::getline(split, each, split_char); tokens.push_back(each));
	
	// put words into map
	for (string word : tokens) {
		it = counts.find(word);
		if (it != counts.end()) {
			counts[word] = counts[word] + 1;
		}
		else {
			counts.insert(it, std::pair<string, int>(word, 1));
		}
	}

	return mapString(counts);
}


int main()
{
	cout << ("isPalindrome") << endl;
	cout << boolalpha << (isPalindrome("A man, a plan, a canal: Panama!") == true) << endl;

	cout << ("countLetters") << endl;
	cout << boolalpha << (countLetters("The quick brown fox jumped over the lazy dogs.")) << endl;

	cout << ("countWords") << endl;
	cout << boolalpha << (countWords("This is fun and this is easy")) << endl;

    // 
	return 0;
}

