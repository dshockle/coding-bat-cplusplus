// W32string-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <locale>
#include <regex>
#include <string>
#include <vector>

using namespace std;

string toLower(const string& s)
{
	string result;

	locale loc;
	for (unsigned int i = 0; i < s.length(); ++i)
	{
		result += tolower(s.at(i), loc);
	}

	return result;
}

string toUpper(const string& s)
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
Given a string, if the string begins with "red" or "blue" return that color string,
otherwise return the empty string.

seeColor("redxx") == "red"
seeColor("xxred") == ""
seeColor("blueTimes") == "blue"
*/
string seeColor(string str)
{
	if (toLower(str).compare(0, 3, "red") == 0)
		return "red";
	else if (toLower(str).compare(0, 4, "blue") == 0)
		return "blue";
	else
		return "";
}


/*
Given a string, return true if the first 2 chars in the string also appear at
the end of the string, such as with "edited".

frontAgain("edited") == true
frontAgain("edit") == false
frontAgain("ed") == true
*/
bool frontAgain(string str)
{
	if (str.empty() || str.length() < 2)
		return false;
	else
		return str.compare(0, 2, str.substr(str.length() - 2)) == 0;
}

/*
Given two strings, append them together and return the result.
However, if the strings are different lengths, omit chars
from the longer string so it is the same length as the
shorter string. So "Hello" and "Hi" yield "loHi".
The strings may be any length including empty.

minCat("Hello", "Hi") == "loHi"
minCat("Hello", "java") == "ellojava"
minCat("java", "Hello") == "javaello"
*/
string minCat(string a, string b)
{
	if (a.length() > b.length())
		return a.substr(a.length() - b.length()) + b;
	else if (a.length() < b.length())
		return a + b.substr(b.length() - a.length());
	else
		return a + b;
}

/*
Given a string, return a new string made of n copies of the first n chars.
If there are fewer than n chars, use whatever is there.

extraFront("Hello", 3) == "HelHelHel"
extraFront("ab", 2) == "abab"
extraFront("H", 3) == "HHH"
*/
string extraFront(string str, int n)
{
	string front = str.substr(0, n);
	string result = "";

	for (unsigned int i = 0; i < n; i++) {
		result += front;
	}

	return result;
}

/*

Given a string, if a length 2 substring appears at both its beginning
and end, return a string without the substring at the beginning,
so "HelloHe" yields "lloHe". The substring may overlap with itself,
so "Hi" yields "". Otherwise, return the original string unchanged.

without2("HelloHe") == "lloHe"
without2("HelloHi") == "HelloHi"
without2("Hi") == ""
*/
string without2(string str)
{
	if (str.empty())
		return "";
	else if (str.length() >= 2 && str.substr(0, 2).compare(str.substr(str.length() - 2)) == 0)
		return str.substr(2);
	else
		return str;

}

/*
Given a string, return a version without the first 2 chars.
Except keep the first char if it is 'a' and keep the second
char if it is 'b'. The string may be any length(). Harder than it looks.

deFront("Hello") == "llo"
deFront("java") == "va"
deFront("away") == "aay"
*/
string deFront(string str)
{
	string sb;
	if (str.length() > 0 && str[0] == 'a')
		sb += str[0];
	if (str.length() > 1 && str[1] == 'b')
		sb += str[1];
	if (str.length() > 2)
		sb += str.substr(2);
	return sb;
}

/*
Given a string and a second "word" string, we'll say that the word matches
the string if it appears at the front of the string, except its first char
does not need to match exactly. On a match, return the front of the string,
or otherwise return the empty string. So, so with the string "hippo"
the word "hi" returns "hi" and "xip" returns "hip". The word will be at
least length() 1.

startWord("hippo", "hi") == "hi"
startWord("hippo", "xip") == "hip"
startWord("hippo", "z") == "h"
*/
string startWord(string str, string word)
{
	if (str.empty() || word.empty() || str.length() < word.length())
		return "";

	int len = word.length();
	string s = str.substr(1, len - 1);
	string w = word.substr(1, len - 1);

	if (s.compare(w) == 0)
		return str.substr(0, len);
	else
		return "";
}

/*
Given a string, if the first or last chars are 'x', return the string
without those 'x' chars, and otherwise return the string unchanged.

withoutX("xHix") == "Hi"
withoutX("xHi") == "Hi"
withoutX("Hxix") == "Hxi"
*/
string withoutX(string str)
{
	bool hasX = false;
	string sb;

	if (str.length() > 0){
		char first = str[0];
		if (first != 'x' && first != 'X')
			sb += str[0];
		else
			hasX = true;
	}

	if (str.length() > 2)
		sb += str.substr(1, str.length() - 2);

	if (str.length() > 1) {
		char last = str[str.length() - 1];
		if (last != 'x' && last != 'X')
			sb +=str[str.length() - 1];
		else
			hasX = true;
	}

	if (hasX)
		return sb;
	else
		return str;
}

/*
Given a string, if one or both of the first 2 chars is 'x', return
the string without those 'x' chars, and otherwise return the string
unchanged. This is a little harder than it looks.

withoutX2("xHi") == "Hi"
withoutX2("Hxi") == "Hi"
withoutX2("Hi") == "Hi"
*/
string withoutX2(string str)
{
	string sb;

	if (str.length() > 0 && str[0] != 'x' && str[0] != 'X')
		sb += str[0];

	if (str.length() > 1 && str[1] != 'x' && str[0] != 'X')
		sb += str[1];

	if (str.length() > 2)
		sb += str.substr(2);

	return sb;
}


int main()
{
	cout << boolalpha;
	cout << ("seeColor") << endl;
	cout << boolalpha << (seeColor("redxx") == "red") << endl;
	cout << boolalpha << (seeColor("xxred") == "") << endl;
	cout << boolalpha << (seeColor("blueTimes") == "blue") << endl;

	cout << ("frontAgain") << endl;
	cout << boolalpha << (frontAgain("edited") == true) << endl;
	cout << boolalpha << (frontAgain("edit") == false) << endl;
	cout << boolalpha << (frontAgain("ed") == true) << endl;
	
	cout << ("minCat") << endl;
	cout << boolalpha << (minCat("Hello", "Hi") == "loHi") << endl;
	cout << boolalpha << (minCat("Hello", "java") == "ellojava") << endl;
	cout << boolalpha << (minCat("java", "Hello") == "javaello") << endl;

	cout << ("extraFront") << endl;
	cout << boolalpha << (extraFront("Hello", 3) == "HelHelHel") << endl;
	cout << boolalpha << (extraFront("ab", 2) == "abab") << endl;
	cout << boolalpha << (extraFront("H", 3) == "HHH") << endl;
	
	cout << ("without2") << endl;
	cout << boolalpha << (without2("HelloHe") == "lloHe") << endl;
	cout << boolalpha << (without2("HelloHi") == "HelloHi") << endl;
	cout << boolalpha << (without2("") == "") << endl;
	cout << boolalpha << (without2("H") == "H") << endl;
	cout << boolalpha << (without2("Hi") == "") << endl;

	cout << ("deFront") << endl;
	cout << boolalpha << (deFront("Hello") == "llo") << endl;
	cout << boolalpha << (deFront("java") == "va") << endl;
	cout << boolalpha << (deFront("away") == "aay") << endl;
	
	cout << ("startWord") << endl;
	cout << boolalpha << (startWord("hippo", "hi") == "hi") << endl;
	cout << boolalpha << (startWord("hippo", "xip") == "hip") << endl;
	cout << boolalpha << (startWord("hippo", "z") == "h") << endl;
	
	cout << ("withoutX") << endl;
	cout << boolalpha << (withoutX("xHix") == "Hi") << endl;
	cout << boolalpha << (withoutX("xHi") == "Hi") << endl;
	cout << boolalpha << (withoutX("Hxix") == "Hxi") << endl;
	cout << boolalpha << (withoutX("HixHi") == "HixHi") << endl;

	cout << ("withoutX2") << endl;
	cout << boolalpha << (withoutX2("xHi") == "Hi") << endl;
	cout << boolalpha << (withoutX2("Hxi") == "Hi") << endl;
	cout << boolalpha << (withoutX2("Hi") == "Hi") << endl;
	
     
	return 0;
}

