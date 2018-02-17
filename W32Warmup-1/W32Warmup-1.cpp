// W32Warmup-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <locale>
#include <string>
using namespace std;
#include <locale>

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
The parameter weekday is true if it is a weekday, and the parameter vacation
is true if we are on vacation. We sleep in if it is not a weekday or we're on
vacation. Return true if we sleep in.

sleepIn(false, false) == true
sleepIn(true, false) == false
sleepIn(false, true) == true
*/

bool sleepIn(bool weekday, bool vacation)
{
	return !weekday || vacation;
}

/*
We have two monkeys, a and b, and the parameters aSmile and bSmile indicate
if each is smiling. We are in trouble if they are both smiling or if neither
of them is smiling. Return true if we are in trouble.

monkeyTrouble(true, true) == true
monkeyTrouble(false, false) == true
monkeyTrouble(true, false) == false
*/
bool monkeyTrouble(bool aSmile, bool bSmile)
{
	return aSmile == bSmile;
}

/*
Given two int values, return their sum. Unless the two values are the same,
then return double their sum.

sumDouble(1, 2) == 3
sumDouble(3, 2) == 5
sumDouble(2, 2) == 8
*/
int sumDouble(int a, int b)
{
	if (a == b)
		return 2 * (a + b);
	else
		return a + b;
}

/*
Given 2 int values, return whichever value is nearest to the value 10, or
return 0 in the event of a tie.

close10(8, 13) == 8
close10(13, 8) == 8
close10(13, 7) == 0
*/
int close10(int a, int b)
{
	int a10 = abs(a - 10);
	int b10 = abs(b - 10);

	if (a10 == b10)
		return 0;
	else if (a10 < b10)
		return a;
	else 
		return b;
}

/*
Return true if the given string contains between min and max 'c' chars.

stringC("Hello", 'e', 1, 3) == true
stringC("Everyone", 'e', 1, 3) == true
stringC("Heelele", 'e', 1, 3) == false
*/
bool stringC(string str, char c, int min, int max)
{
	int count = 0;
	char target = tolower(c);

	if (!str.empty())
		for(char ch : str)
			if (tolower(ch) == target) 
				count++;

	return count >= min && count <= max;
}


/*
Given two non-negative int values, return true if they have the same last digit,
such as with 27 and 57.

lastDigit(7, 17) == true
lastDigit(6, 17) == false
lastDigit(3, 113) == true
*/
bool lastDigit(int a, int b)
{
	return a % 10 == b % 10;
}

/*
Given a string, return a new string where the last 'num' chars are
now in upper case. If the string has less than 'num' chars,
uppercase whatever is there.

endUp("Hello", 3) == "HeLLO"
endUp("hi there", 3) == "hi thERE"
endUp("hi", 3) == "HI"
*/
string endUp(string str, int num)
{
	unsigned int n = num;
	if (num <= 0 || str.length() == 0)
		return str;
	else if (str.length() > n)
	{
		string front = str.substr(0, str.length() - n);
		string back = str.substr(str.length() - n);
		return front + toUpper(back);
	}
	else
		return toUpper(str);
}

/*
Given a non-empty string and an int N, return the string made starting
with char 0, and then every Nth char of the string.
So if N is 3, use char 0, 3, 6, ... and so on. N is 1 or more.

everyNth("Miracle", 2) == "Mrce"
everyNth("abcdefg", 2) == "aceg"
everyNth("abcdefg", 3) == "adg"
*/
string everyNth(string str, int n)
{
	string sb;

	for (unsigned int i = 0; i < str.length(); i += n)
		sb += str[i];

	return sb;
}

int main()
{
	cout << boolalpha;
	cout << ("sleepIn") << endl;
	cout << boolalpha << (sleepIn(false, false) == true) << endl;
	cout << boolalpha << (sleepIn(true, false) == false) << endl;
	cout << boolalpha << (sleepIn(false, true) == true) << endl;

	cout << ("monkeyTrouble") << endl;
	cout << boolalpha << (monkeyTrouble(true, true) == true) << endl;
	cout << boolalpha << (monkeyTrouble(false, false) == true) << endl;
	cout << boolalpha << (monkeyTrouble(true, false) == false) << endl;

	cout << ("sumDouble") << endl;
	cout << boolalpha << (sumDouble(1, 2) == 3) << endl;
	cout << boolalpha << (sumDouble(3, 2) == 5) << endl;
	cout << boolalpha << (sumDouble(2, 2) == 8) << endl;

	cout << ("close10") << endl;
	cout << boolalpha << (close10(8, 13) == 8) << endl;
	cout << boolalpha << (close10(13, 8) == 8) << endl;
	cout << boolalpha << (close10(13, 7) == 0) << endl;

	cout << ("stringC") << endl;
	cout << boolalpha << (stringC("Hello", 'e', 1, 3) == true) << endl;
	cout << boolalpha << (stringC("Everyone", 'e', 1, 3) == true) << endl;
	cout << boolalpha << (stringC("Heelele", 'e', 1, 3) == false) << endl;


	cout << ("lastDigit") << endl;
	cout << boolalpha << (lastDigit(7, 17) == true) << endl;
	cout << boolalpha << (lastDigit(6, 17) == false) << endl;
	cout << boolalpha << (lastDigit(3, 113) == true) << endl;

	cout << ("endUp") << endl;
	cout << boolalpha << (endUp("Hello", 3) == "HeLLO") << endl;
	cout << boolalpha << (endUp("hi there", 3) == "hi thERE") << endl;
	cout << boolalpha << (endUp("hi", 3) == "HI") << endl;

	cout << ("everyNth") << endl;
	cout << boolalpha << (everyNth("Miracle", 2) == "Mrce") << endl;
	cout << boolalpha << (everyNth("abcdefg", 2) == "aceg") << endl;
	cout << boolalpha << (everyNth("abcdefg", 3) == "adg") << endl;

	cout << "press any key to exit" << endl;
	
	return 0;
}
