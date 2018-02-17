// W32String-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <locale>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
Helper method
*/
string str_tolower(const string& s)
{
	string result;

	locale loc;
	for (unsigned int i = 0; i < s.length(); ++i)
	{
		result += tolower(s.at(i), loc);
	}

	return result;
}

/*
Helper method
*/
string str_toupper(const string& s)
{
	string result;

	locale loc;
	for (unsigned int i = 0; i < s.length(); ++i)
	{
		result += toupper(s.at(i), loc);
	}

	return result;
}

/*
Helper method
*/
int countSubstring(const std::string& str, const std::string& sub)
{
	if (sub.length() == 0) return 0;
	int count = 0;
	// use offset + sub.length() for non-overlapping
	for (size_t offset = str.find(sub); offset != std::string::npos; offset = str.find(sub, offset + 1)) 
		++count;

	return count;
}

/*
Helper method
*/
vector<size_t> findsubs(const std::string& str, const std::string& sub)
{
	vector<size_t> positions;
	size_t pos = str.find(sub, 0);

	while (pos != string::npos)
	{
		positions.push_back(pos);
		pos = str.find(sub, pos + 1);
	}

	return positions;
}

/*
Helper method
*/
std::vector<std::string> split(const string& input, const string& regex) {
	// passing -1 as the submatch index parameter performs splitting
	std::regex re(regex);
	std::sregex_token_iterator
		first{ input.begin(), input.end(), re, -1 },
		last;
	return{ first, last };
}

/*
Given a string, count the number of words ending in 'y' or 'z' -- so
the 'y' in "heavy" and the 'z' in "fez" count, but not the 'y' in "yellow"
(not case sensitive). We'll say that a y or z is at the end of a word if
there is not an alphabetic letter immediately following it.

countYZ("Why ask why? Indeed, why ask why!") → 4
countYZ("day fez") → 2
countYZ("day fyyyz") → 2
*/
int countYZ(string str)
{
	int count = 0;

	for (int i = 1; i <= str.length(); i++) {
		if (i == str.length() || !isalpha(str[i]))
			if (isalpha(str[i-1]))
				if (str[i - 1] == 'y' || str[i - 1] == 'z')
					count++;
	}

	return count;
}

/*
Given two strings, original and remove, return a version of the original string
where all instances of the remove string have been removed (not case sensitive).
You may assume that the remove string is length 1 or more.
Remove only non-overlapping instances, so with "xxx" removing "xx" leaves "x".

withoutString("Hello there", "llo") → "He there"
withoutString("Hello there", "e") → "Hllo thr"
withoutString("Hello there", "x") → "Hello there"
*/
string withoutString(string original, string remove)
{
	string ori = str_tolower(original);
	string rem = str_tolower(remove);
	int rlen = rem.length();
	int pos = original.length() - 1;

	while (pos >= 0) {
		pos = ori.rfind(rem, pos);
		if (pos != ori.npos)
			original.replace(pos, rlen, "");
		pos -= rlen;
	}

	return original;
}

/*
Given a string, return true if the number of appearances of "first" anywhere
in the string is equal to the number of appearances of "second" anywhere in
the string (case sensitive).

equalIsNot("This is not.", "is", "not") → false
equalIsNot("This is not not.", "is", "not") → true
equalIsNot("Note the notice isn't.", "is", "not") → true
*/
bool equalIsNot(string text, string first, string second)
{
	std::regex r(first);
	int firstCount = (text.length() - regex_replace(text, r, "").length()) / first.length();

	r = regex(second);
	int secondCount = (text.length() - regex_replace(text, r, "").length()) / second.length();

	return firstCount == secondCount;
}

/*
Given a string, return true if the number of appearances of "first" anywhere
in the string is equal to the number of appearances of "second" anywhere in
the string (case sensitive).

equalIsNot("This is not.", "is", "not") → false
equalIsNot("This is not not.", "is", "not") → true
equalIsNot("Note the notice isn't.", "is", "not") → true
*/
bool equalIsNot2(string text, string first, string second)
{
	return countSubstring(text, first) == countSubstring(text, second);
}

/*
We'll say that a lowercase 'g' in a string is "happy" if there is another 'g'
immediately to its left or right. Return true if all the g's in the given string
are happy.

gHappy("xxggxx", 'g') → true
gHappy("xxgxx", 'g') → false
gHappy("xxggyygxx", 'g') → false
*/
bool gHappy(string str, char g)
{
	for (unsigned int i = 0; i < str.length(); i++)
		if (str[i] == g)
			if ((i > 0 && str[i - 1] != g)
				&& (i < str.length() - 1 && str[i + 1] != g))
				return false;

	return true;
}

/*

We'll say that a "triple" in a string is a char appearing three times in a row.
Return the number of triples in the given string. The triples may overlap.

countTriple("abcXXXabc") → 1
countTriple("xxxabyyyycd") → 3
countTriple("a") → 0
*/
int countTriple(string str)
{
	int count = 0;

	for (unsigned int i = 2; i < str.length(); i++)
		if (str[i] == str[i - 1] && str[i] == str[i - 2])
			count++;

	return count;
}

/*
Given a string, return the sum of the digits 0-9 that appear in the string,
ignoring all other characters. Return 0 if there are no digits in the string.

sumDigits("aa1bc2d3") → 6
sumDigits("aa11b33") → 8
sumDigits("Chocolate") → 0
*/
int sumDigits(string str)
{
	int sum = 0;

	for(char c : str)
		if (isdigit(c))
			sum += (int)c - '0';

	return sum;
}

/*
Given a string, return the longest substring that appears at both the beginning and end
of the string without overlapping. For example, sameEnds("abXab") is "ab".

sameEnds("abXYab") → "ab"
sameEnds("xx") → "x"
sameEnds("xxx") → "x"
*/
string sameEnds(string str)
{
	int len = str.length() / 2;
	do
	{
		if (str.substr(0, len) == str.substr(str.length() - len))
			return str.substr(0, len);
		len--;
	} while (len > 0);

	return "";
}

/*
Given a string, look for a mirror image (backwards) string at both the beginning
and end of the given string. In other words, zero or more characters at the very
begining of the given string, and at the very end of the string in reverse order
(possibly overlapping). For example, the string "abXYZba" has the mirror end "ab".

mirrorEnds("abXYZba") → "ab"
mirrorEnds("abca") → "a"
mirrorEnds("aba") → "aba"
mirrorEnds("dog") → ""
*/
string mirrorEnds(string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
		if (str[i] != str[str.length() - 1 - i])
			return str.substr(0, i);

	return str;
}

/*
Given a string, return the length of the largest "block" in the string.
A block is a run of adjacent chars that are the same.

maxBlock("hoopla") → 2
maxBlock("abbCCCddBBBxx") → 3
maxBlock("") → 0
maxBlock("aaaa") → 4
*/
int maxBlock(string str)
{
	int max = 0;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		int block = 0;
		for (unsigned int j = i; j < str.length(); j++)
		{
			if (str[i] != str[j])
				break;
			else
				block = 1 + j - i;
		}
		if (block > max)
			max = block;
	}
	return max;
}

/*
Given a string, return the sum of the numbers appearing in the string,
ignoring all other characters. A number is a series of 1 or more digit
chars in a row.

sumNumbers("abc123xyz") → 123
sumNumbers("aa11b33") → 44
sumNumbers("7 11") → 18
*/
int sumNumbers(string str)
{
	vector<string> words = split(str, "[^0-9]");
	int sum = 0;

	for (string word : words)
		if (!word.empty())
			sum += std::stoi(word);

	return sum;
}

/*
Given a string, return a string where every appearance of the lowercase word "is"
has been replaced with "is not". The word "is" should not be immediately preceeded
or followed by a letter -- so for example the "is" in "this" does not count.

notReplace("is test") → "is not test"
notReplace("is-is") → "is not-is not"
notReplace("This is right") → "This is not right"
*/
string notReplace(string str)
{
	if (str == "is")
		return "is not";

	if (str.length() < 3)
		return str;

	string result;

	for (int i = 0; i < str.length(); i++) {
		bool found = (i < str.length() - 1 && str[i] == 'i' && str[i + 1] == 's');
		bool before = (i <= 0 || !isalpha(str[i - 1]));
		bool after = (i >= str.length() - 2 || !isalpha(str[i + 2]));

		if ( found && before && after) {
			result += "is not";
			i++;
		}
		else
			result += str[i];
	}

	return result;
}

int main()
{

	cout << boolalpha << ("countYZ") << endl;
	cout << boolalpha << (countYZ("Why ask why? Indeed, why ask why!") == 4) << endl;
	cout << boolalpha << (countYZ("day fez") == 2) << endl;
	cout << boolalpha << (countYZ("day fyyyz") == 2) << endl;

	cout << boolalpha << ("withoutString") << endl;
	cout << boolalpha << (withoutString("Hello there", "llo") == "He there") << endl;
	cout << boolalpha << (withoutString("Hello there", "E") == "Hllo thr") << endl;
	cout << boolalpha << (withoutString("Hello there", "X") == "Hello there") << endl;

	cout << boolalpha << ("equalIsNot") << endl;
	cout << boolalpha << (equalIsNot("This is not", "is", "not") == false) << endl;
	cout << boolalpha << (equalIsNot("This is not not", "is", "not") == true) << endl;
	cout << boolalpha << (equalIsNot("Note the notice isn't.", "is", "not") == true) << endl;

	cout << boolalpha << ("equalIsNot2") << endl;
	cout << boolalpha << (equalIsNot2("This is not", "is", "not") == false) << endl;
	cout << boolalpha << (equalIsNot2("This is not not", "is", "not") == true) << endl;
	cout << boolalpha << (equalIsNot2("Note the notice isn't.", "is", "not") == true) << endl;

	cout << boolalpha << ("gHappy") << endl;
	cout << boolalpha << (gHappy("xxggxx", 'g') == true) << endl;
	cout << boolalpha << (gHappy("xxgxx", 'g') == false) << endl;
	cout << boolalpha << (gHappy("xxggyygxx", 'g') == false) << endl;

	cout << boolalpha << ("countTriple") << endl;
	cout << boolalpha << (countTriple("abcXXXabc") == 1) << endl;
	cout << boolalpha << (countTriple("xxxabyyyycd") == 3) << endl;
	cout << boolalpha << (countTriple("a") == 0) << endl;

	cout << boolalpha << ("sumDigits") << endl;
	cout << boolalpha << (sumDigits("aa1bc2d3") == 6) << endl;
	cout << boolalpha << (sumDigits("aa11b33") == 8) << endl;
	cout << boolalpha << (sumDigits("Chocolate") == 0) << endl;

	cout << boolalpha << ("sameEnds") << endl;
	cout << boolalpha << (sameEnds("abXYab") == "ab") << endl;
	cout << boolalpha << (sameEnds("xx") == "x") << endl;
	cout << boolalpha << (sameEnds("xxx") == "x") << endl;

	cout << boolalpha << ("mirrorEnds") << endl;
	cout << boolalpha << (mirrorEnds("abXYZba") == "ab") << endl;
	cout << boolalpha << (mirrorEnds("abca") == "a") << endl;
	cout << boolalpha << (mirrorEnds("aba") == "aba") << endl;
	cout << boolalpha << (mirrorEnds("dog") == "") << endl;

	cout << boolalpha << ("maxBlock") << endl;
	cout << boolalpha << (maxBlock("hoopla") == 2) << endl;
	cout << boolalpha << (maxBlock("abbCCCddBBBxx") == 3) << endl;
	cout << boolalpha << (maxBlock("") == 0) << endl;
	cout << boolalpha << (maxBlock("aaaa") == 4) << endl;

	cout << boolalpha << ("sumNumbers") << endl;
	cout << boolalpha << (sumNumbers("abc123xyz") == 123) << endl;
	cout << boolalpha << (sumNumbers("aa11b33") == 44) << endl;
	cout << boolalpha << (sumNumbers("7 11") == 18) << endl;

	cout << boolalpha << ("notReplace") << endl;
	cout << boolalpha << (notReplace("is test") == "is not test") << endl;
	cout << boolalpha << (notReplace("is-is") == "is not-is not") << endl;
	cout << boolalpha << (notReplace("This is right") == "This is not right") << endl;

	return 0;
}

