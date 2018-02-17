// W32Warmup-2.cpp : Defines the entry point for the console application.
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
		result += tolower(s.at(i), loc);

	return result;
}

string toUpper(const string& s)
{
	string result;
	locale loc;

	for (unsigned int i = 0; i < s.length(); ++i)
		result += toupper(s.at(i), loc);

	return result;
}

/*
Given a string and a non-negative int n, return a larger string
that is n copies of the original string.
stringTimes("Hi", 2) == "HiHi"
stringTimes("Hi", 3) == "HiHiHi"
stringTimes("Hi", 1) == "Hi"
*/
string stringTimes(string str, int n)
{
	string sb;

	for (unsigned int i = 0; i < n; i++)
		sb += str;

	return sb;
}

/*
Given a string and a non-negative int n,
we'll say that the front of the string is the first 3 chars,
or whatever is there if the string is less than length() 3.
Return n copies of the front;

frontTimes("Chocolate", 2) == "ChoCho"
frontTimes("Chocolate", 3) == "ChoChoCho"
frontTimes("Abc", 3) == "AbcAbcAbc"
*/
string frontTimes(string str, int n)
{
	string sb;
	int len = str.length();
	int m = min(len, 3);
	string front = str.substr(0, m);

	for (unsigned int i = 0; i < n; i++) {
		sb += front;
	}

	return sb;
}


/*
Count the number of "xx" in the given string.
We'll say that overlapping is allowed, so "xxx" contains 2.
countXX("abcxx") == 1
countXX("xxx") == 2
countXX("xxxx") == 3
*/
int countXX(string str)
{
	int count = 0;

	for (unsigned int i = 1; i < str.length(); i++)
		if (str[i] == 'x' && str[i - 1] == 'x')
			count++;

	return count;
}

/*
Given a string, return true if the first instance of "x" in the string
is immediately followed by another "x".
doubleX("axxbb") == true
doubleX("axaxx") == false
doubleX("xxxxx") == true
*/
bool doubleX(string str)
{
	string lowerCaseStr = toLower(str);

	for (unsigned int i = 1; i < lowerCaseStr.length(); i++)
		if (lowerCaseStr[i - 1] == 'x')
			if (lowerCaseStr[i] == 'x')
				return true;
			else
				return false;

	return false;
}

/*
Given a string, return a new string made of every other char starting
with the first, so "Hello" yields "Hlo".

stringBits("Hello") == "Hlo"
stringBits("Hi") == "H"
stringBits("Heeololeo") == "Hello"
*/

string stringBits(string str)
{
	string sb;

	for (unsigned int i = 0; i < str.length(); i += 2)
		sb += str[i];
		
	return sb;
}

/*
Given a non-empty string like "Code" return a string like "CCoCodCode".

stringSplosion("Code") == "CCoCodCode"
stringSplosion("abc") == "aababc"
stringSplosion("ab") == "aab"
*/
string stringSplosion(string str)
{
	string sb;
	for (unsigned int i = 0; i < str.length(); i++)
		sb += str.substr(0, i + 1);

	return sb;
}
/*

Given a string, return a version where all the "x" have been removed.
Except an "x" at the very start or end should not be removed.

stringX("xxHxix") == "xHix"
stringX("abxxxcd") == "abcd"
stringX("xabxxxcdx") == "xabcdx"
*/
string stringX(string str)
{
	regex r("[xX]");
	string noX = regex_replace(str.substr(1, str.length() - 2), r, "");
	return str[0] + noX + str[str.length() - 1];
}

/*
Given a string, return a string made of the chars at
indexes 0,1, 4,5, 8,9 ... so "kittens" yields "kien".

altPairs("kitten") == "kien"
altPairs("Chocolate") == "Chole"
altPairs("CodingHorror") == "Congrr
*/
string altPairs(string str)
{
	string sb;
	unsigned int len = str.length();

	for (unsigned int i = 0; i < len; i += 4)
	{
		sb += str[i];
		if (i < str.length() - 1)
			sb += str[i + 1];
	}

	return sb;
}

/*
Suppose the string "yak" is unlucky.
Given a string, return a version where all the "yak" are removed,
but the "a" can be any char. The "yak" strings will not overlap.

stringYak("yakpak") == "pak"
stringYak("pakyak") == "pak"
stringYak("yak123ya") == "123ya"
*/
string stringYak(string str)
{
	regex r("y.k");
	return regex_replace(str, r, "");
}

/*

Given an array of ints, we'll say that a triple is a value appearing 3 times
in a row in the array. Return true if the array does not contain any triples.

noTriples({1, 1, 2, 2, 1}) == true
noTriples({1, 1, 2, 2, 2, 1}) == false
noTriples({1, 1, 1, 2, 2, 2, 1}) == false
*/
bool noTriples(vector<int> nums)
{
	int len = nums.size();
	for (unsigned int i = 2; i < len; i++)
		if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2])
			return false;

	return true;
}


int main()
{
	cout << boolalpha;
	cout << ("stringTimes");
	cout << boolalpha << (stringTimes("Hi", 2) == "HiHi") << endl;
	cout << boolalpha << (stringTimes("Hi", 3) == "HiHiHi") << endl;
	cout << boolalpha << (stringTimes("Hi", 1) == "Hi") << endl;

	cout << ("frontTimes") << endl;
	cout << boolalpha << (frontTimes("Chocolate", 2) == "ChoCho") << endl;
	cout << boolalpha << (frontTimes("Chocolate", 3) == "ChoChoCho") << endl;
	cout << boolalpha << (frontTimes("Abc", 3) == "AbcAbcAbc") << endl;

	cout << ("countXX") << endl;
	cout << boolalpha << (countXX("abcxx") == 1) << endl;
	cout << boolalpha << (countXX("xxx") == 2) << endl;
	cout << boolalpha << (countXX("xxxx") == 3) << endl;

	cout << ("doubleX") << endl;
	cout << boolalpha << (doubleX("axXbb") == true) << endl;
	cout << boolalpha << (doubleX("axaxx") == false) << endl;
	cout << boolalpha << (doubleX("Xxxxx") == true) << endl;

	cout << ("stringBits") << endl;
	cout << boolalpha << (stringBits("Hello") == "Hlo") << endl;
	cout << boolalpha << (stringBits("Hi") == "H") << endl;
	cout << boolalpha << (stringBits("Heeololeo") == "Hello") << endl;

	cout << ("stringSplosion") << endl;
	cout << boolalpha << (stringSplosion("Code") == "CCoCodCode") << endl;
	cout << boolalpha << (stringSplosion("abc") == "aababc") << endl;
	cout << boolalpha << (stringSplosion("ab") == "aab") << endl;

	cout << ("stringX") << endl;
	cout << boolalpha << (stringX("xxHxix") == "xHix") << endl;
	cout << boolalpha << (stringX("abxxxcd") == "abcd") << endl;
	cout << boolalpha << (stringX("xabxxxcdx") == "xabcdx") << endl;

	cout << ("altPairs") << endl;
	cout << boolalpha << (altPairs("kitten") == "kien") << endl;
	cout << boolalpha << (altPairs("Chocolate") == "Chole") << endl;
	cout << boolalpha << (altPairs("CodingHorror") == "Congrr") << endl;

	cout << ("stringYak") << endl;
	cout << boolalpha << (stringYak("yakpak") == "pak") << endl;
	cout << boolalpha << (stringYak("pakyak") == "pak") << endl;
	cout << boolalpha << (stringYak("yak123ya") == "123ya") << endl;

	cout << ("noTriples") << endl;
	cout << boolalpha << (noTriples( { 1, 1, 2, 2, 1}) == true) << endl;
	cout << boolalpha << (noTriples( { 1, 1, 2, 2, 2, 1}) == false) << endl;
	cout << boolalpha << (noTriples( { 1, 1, 1, 2, 2, 2, 1}) == false) << endl;

	cout << "press any key to exit" << endl;
	
	return 0;
}

