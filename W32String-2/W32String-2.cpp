// W32string-2.cpp : Defines the entry point for the console application.
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
int countsub(const std::string& str, const std::string& sub)
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
Helper method
*/
int countMatchInRegex(std::string s, std::string re)
{
	std::regex words_regex(re);
	auto words_begin = std::sregex_iterator(
		s.begin(), s.end(), words_regex);
	auto words_end = std::sregex_iterator();

	return std::distance(words_begin, words_end);
}

/*
Given a string, return a string where for every char in the original, there are two chars.

doubleChar("The") → "TThhee"
doubleChar("AAbb") → "AAAAbbbb"
doubleChar("Hi-There") → "HHii--TThheerree"
*/
string doubleChar(string str)
{
	string sb;
	for(char c : str)
	{
		sb += (c);
		sb += (c);
	}
	return sb;
}

/*
Return the number of times that the string "hi" appears
anywhere in the given string.

countHi("abc hi ho") → 1
countHi("ABChi hi") → 2
countHi("hihi") → 2
*/
int countHi(string str)
{
	return countMatchInRegex(str, "hi");
	/*
	string withoutHi = str.replace(str.find("hi"), 2, "");
	return (str.length() - withoutHi.length()) / 2;
	*/
}

/*
Return true if the string "cat" and "dog" appear
the same number of times in the given string.

catDog("catdog") → true
catDog("catcat") → false
catDog("1cat1cadodog") → true
*/
bool catDog(string str)
{
	return countMatchInRegex(str, "cat") == countMatchInRegex(str, "dog");
}

/*
Return the number of times that the string "code" appears anywhere in the given string,
except we'll accept any letter for the 'd', so "cope" and "cooe" count.

countCode("aaacodebbb") → 1
countCode("codexxcode") → 2
countCode("cozexxcope") → 2
*/
int countCode(string str)
{
	return countMatchInRegex(str, "co.e");
}

/*
Given two strings, return true if either of the strings appears at the
very end of the other string, ignoring upper/lower case differences.

endOther("Hiabc", "abc") → true
endOther("AbC", "HiaBc") → true
endOther("abc", "abXabc") → true
*/
bool endOther(string a, string b)
{
	string lowA = str_tolower(a);
	string lowB = str_tolower(b);
	int lenA = lowA.length();
	int lenB = lowB.length();

	if (lenA == lenB)
		return lowA == lowB;
	else if (lenA < lenB)
		return lowB.substr(lenB - lenA) == lowA;
	else
		return lowA.substr(lenA - lenB) == lowB;
}

/*
Return true if the given string contains an appearance of "xyz" where the xyz is
not directly preceeded by a period (.). So "xxyz" counts but "x.xyz" does not.

xyzThere("abcxyz") → true
xyzThere("abc.xyz") → false
xyzThere("xyz.abc") → true
*/
bool xyzThere(string str)
{
	return countMatchInRegex(str, "^xyz|[^\\.]xyz") > 0;
}

/*
Return true if the given string contains a "bob" string,
but where the middle 'o' char can be any char.

bobThere("abcbob") → true
bobThere("b9b") → true
bobThere("bac") → false
*/
bool bobThere(string str)
{
	return countMatchInRegex(str, "b.b") > 0;
}

/*
Return true if  for all the 'x' chars in the string, there exists a 'y'
char somewhere later in the string. One 'y' can balance multiple 'x's.

xyBalance("aaxbby") → true
xyBalance("aaxbb") → false
xyBalance("yaaxbb") → false
*/
bool xyBalance(string str)
{
	int posX = str.find_last_of("x");
	int posY = str.find_last_of("y");
	return posX < posY;
}

/*
Given two strings, a and b, create a bigger string made of the first char of a,
the first char of b, the second char of a, the second char of b, and so on.
Any leftover chars go at the end of the result.

mixstring("abc", "xyz") → "axbycz"
mixstring("Hi", "There") → "HTihere"
mixstring("xxxx", "There") → "xTxhxexre"
*/
string mixstring(string a, string b)
{
	string sb;
	int min = std::min(a.size(), b.size());
	int max = std::max(a.size(), b.size());

	for (unsigned int i = 0; i < min; i++)
	{
		sb += (a[i]);
		sb += (b[i]);
	}

	if (max != min)
		if (max == a.size())
			sb += (a.substr(min));
	if (max == b.size())
		sb += (b.substr(min));

	return sb;
}

/*
Given a string and an int n, return a string made of n repetitions
of the last n characters of the string. You may assume that n is
between 0 and the length of the string, inclusive.

repeatEnd("Hello", 3) → "llollollo"
repeatEnd("Hello", 2) → "lolo"
repeatEnd("Hello", 1) → "o"
*/
string repeatEnd(string str, int n)
{
	string end = str.substr(str.length() - n);
	string result;

	for (int i = 0; i < n; i++)
		result += end;

	return result;
}

/*
Given a string and an int n, return a string made of the first n characters
of the string, followed by the first n-1 characters of the string, and so on.

repeatFront("Chocolate", 4) → "ChocChoChC"
repeatFront("Chocolate", 3) → "ChoChC"
repeatFront("Ice Cream", 2) → "IcI"
*/
string repeatFront(string str, int n)
{
	string sb;

	for (unsigned int i = n; i > 0; --i)
		sb += str.substr(0, i);

	return sb;
}

/*
Given two strings, word and a separator sep, return a big string
made of count occurrences of the word, separated by the separator string.

repeatSeparator("Word", "X", 3) → "WordXWordXWord"
repeatSeparator("This", "And", 2) → "ThisAndThis"
repeatSeparator("This", "And", 1) → "This"
*/
string repeatSeparator(string word, string sep, int count)
{
	string sb;
	for (unsigned int i = 0; i < count; i++)
	{
		sb += (word);
		if (i < count - 1)
			sb += (sep);
	}
	return sb;
}

/*
Given a string, consider the prefix string made of the first N chars
of the string. Does that prefix string appear somewhere else in the string?
Assume that the string is not empty and that N is in the range 1..str.length().

prefixAgain("abXYabc", 1) → true
prefixAgain("abXYabc", 2) → true
prefixAgain("abXYabc", 3) → false
*/
bool prefixAgain(string str, int n)
{
	string front = str.substr(0, n);
	string back = str.substr(n);
	return back.find(front) != back.npos;
}

/*
Given a string, does the sub string appear in the middle of the string?
To define middle, we'll say that the number of chars to the left
and right of the sub string must differ by at most one.
This problem is harder than it looks.

subMiddle("AAxyzBB", "xyz") → true
subMiddle("AxyzBB", "xyz") → true
subMiddle("AAxyzB", "xyz") → true
subMiddle("AxyzBBB", "xyz") → false
*/
bool subMiddle(string str, string sub)
{
	int strLen = str.size();
	int subLen = sub.size();
	bool oddPadding = (strLen - subLen) % 2 == 1;

	int startEven = strLen / 2 - subLen / 2;
	int startOdd = strLen / 2 - subLen / 2 - 1;

	string strEven = str.substr(startEven, subLen);
	string strOdd = str.substr(startOdd, subLen);

	bool resultEven = strEven == (sub);
	bool resultOdd = strOdd == (sub);

	return resultEven || (oddPadding && resultOdd);
	//return oddPadding ? resultEven || resultOdd : resultEven;
}

/*
Return the string that is between the first and last appearance
of "bread" in the given string, or return the empty string "" if
there are not two pieces of bread.

getSandwich("breadjambread", "bread") → "jam"
getSandwich("xxbreadjambreadyy", "bread") → "jam"
getSandwich("xxbreadyy", "bread") → ""
*/
string getSandwich(string str, string bread)
{
	if (countsub(str, bread) < 2)
		return "";
	else {
		std::size_t first = str.find(bread);
		std::size_t last = str.rfind(bread);
		int blen = bread.length();
		string result = str.substr(first + blen, last - first - blen);
		return result;
	}
}

/*
Returns true if for every '*' (star) in the string, if there are chars
both immediately before and after the star, they are the same.

sameStarChar("xy*yzz") → true
sameStarChar("xy*zzz") → false
sameStarChar("*xa*az") → true
*/
bool sameStarChar(string str)
{
	for (unsigned int i = 1; i < str.size() - 1; i++)
	{
		if (str[i] == '*')
			if (str[i - 1] != str[i + 1])
				return false;
	}
	return true;
}

/*
Given a string, compute a new string by moving the first char to come
after the next two chars, so "abc" yields "bca". Repeat this process for
each subsequent group of 3 chars, so "abcdef" yields "bcaefd".
Ignore any group of fewer than 3 chars at the end.

oneTwo("abc") → "bca"
oneTwo("tcax") → "cat"
oneTwo("tcagdo") → "catdog"
*/
string oneTwo(string str)
{
	string sb;
	for (unsigned int i = 0; i < str.size() - 2; i += 3)
	{
		sb += (str[i + 1]);
		sb += (str[i + 2]);
		sb += (str[i]);
	}
	return sb;
}

/*
Look for patterns like "zip" and "zap" in the string -- length-3,
starting with 'z' and ending with 'p'. Return a string where for
all such words, the middle letter is gone, so "zipXzap" yields "zpXzp".

zipZap("zipXzap") → "zpXzp"
zipZap("zopzop") → "zpzp"
zipZap("zzzopzop") → "zzzpzp"
*/
string zipZap(string str)
{
	std::regex r("z.p");
	return regex_replace(str, r, "zp");
}

/*
Return a version of the given string, where for every star (*) in the
string the star and the chars immediately to its left and right are gone.
So "ab*cd" yields "ad" and "ab**cd" also yields "ad".

starOut("ab*cd") → "ad"
starOut("ab**cd") → "ad"
starOut("sm**eilly") → "silly"
*/
string starOut(string str)
{
	std::regex r(".\\*+.");
	return regex_replace(str, r, "");
}

/*
Given a string and a non-empty word string, return a version of the original
string where all chars have been replaced by pluses ("+"), except for appearances
of word which are preserved unchanged.

plusOut("12xy34", "xy") → "++xy++"
plusOut("12xy34", "1") → "1+++++"
plusOut("12xy34xyabcxy", "xy") → "++xy++xy+++xy"
*/
string plusOut(string str, string word)
{
	std::regex r("[^" + word + "]");
	string result = regex_replace(str, r, "+");
	return result;
}

/*
Given a string and a non-empty word string, return a string made of each char
just before and just after every appearance of the word in the string.
Ignore cases where there is no char before or after the word, and a char may
be included twice if it is between two words.

wordEnds("abcXY123XYijk", "XY") → "c13i"
wordEnds("XY123XY", "XY") → "13"
wordEnds("XY1XY", "XY") → "11"
*/
string wordEnds(string str, string word)
{
/*
create empty string
create positions list
foreach position in positions
if position not zero
add character one before
if position + word.length < str.length - 1
add character one behind
return string
*/
	string result;
	int len = word.length();
	vector<size_t> vec = findsubs(str, word);

	for (unsigned int n : vec) {
		if (n != 0)
			result += str[n - 1];
		if (n + len < str.length() - 1)
			result += str[n + len];
	}

	return result;
}


int main()
{
	cout << boolalpha << ("doubleChar") << endl;
	cout << boolalpha << (doubleChar("The") == "TThhee") << endl;
	cout << boolalpha << (doubleChar("AAbb") == "AAAAbbbb") << endl;
	cout << boolalpha << (doubleChar("Hi-There") == "HHii--TThheerree") << endl;

	cout << boolalpha << ("countHi") << endl;
	cout << boolalpha << (countHi("ABChi hi") == 2) << endl;
	cout << boolalpha << (countHi("abc hi ho") == 1) << endl;
	cout << boolalpha << (countHi("hihi") == 2) << endl;

	cout << boolalpha << ("catDog") << endl;
	cout << boolalpha << (catDog("catdog") == true) << endl;
	cout << boolalpha << (catDog("catcat") == false) << endl;
	cout << boolalpha << (catDog("1cat1cadodog") == true) << endl;

	cout << boolalpha << ("countCode") << endl;
	cout << boolalpha << (countCode("aaacodebbb") == 1) << endl;
	cout << boolalpha << (countCode("codexxcode") == 2) << endl;
	cout << boolalpha << (countCode("cozexxcope") == 2) << endl;

	cout << boolalpha << ("endOther") << endl;
	cout << boolalpha << (endOther("Hiabc", "abc") == true) << endl;
	cout << boolalpha << (endOther("AbC", "HiaBc") == true) << endl;
	cout << boolalpha << (endOther("abc", "abXabc") == true) << endl;

	cout << boolalpha << ("xyzThere") << endl;
	cout << boolalpha << (xyzThere(".xyzabcxyz") == true) << endl;
	cout << boolalpha << (xyzThere("abcxyz") == true) << endl;
	cout << boolalpha << (xyzThere("abc.xyz") == false) << endl;
	cout << boolalpha << (xyzThere("xyz.abc") == true) << endl;

	cout << boolalpha << ("bobThere") << endl;
	cout << boolalpha << (bobThere("abcbob") == true) << endl;
	cout << boolalpha << (bobThere("b9b") == true) << endl;
	cout << boolalpha << (bobThere("bac") == false) << endl;

	cout << boolalpha << ("xyBalance") << endl;
	cout << boolalpha << (xyBalance("aaxbby") == true) << endl;
	cout << boolalpha << (xyBalance("aaxbb") == false) << endl;
	cout << boolalpha << (xyBalance("yaaxbb") == false) << endl;

	cout << boolalpha << ("mixstring") << endl;
	cout << boolalpha << (mixstring("abc", "xyz") == "axbycz") << endl;
	cout << boolalpha << (mixstring("Hi", "There") == "HTihere") << endl;
	cout << boolalpha << (mixstring("xxxx", "There") == "xTxhxexre") << endl;

	cout << boolalpha << ("repeatEnd") << endl;
	cout << boolalpha << (repeatEnd("Hello", 2) == "lolo") << endl;
	cout << boolalpha << (repeatEnd("Hello", 3) == "llollollo") << endl;
	cout << boolalpha << (repeatEnd("Hello", 1) == "o") << endl;

	cout << boolalpha << ("repeatFront") << endl;
	cout << boolalpha << (repeatFront("Chocolate", 4) == "ChocChoChC") << endl;
	cout << boolalpha << (repeatFront("Chocolate", 3) == "ChoChC") << endl;
	cout << boolalpha << (repeatFront("Ice Cream", 2) == "IcI") << endl;

	cout << boolalpha << ("repeatSeparator") << endl;
	cout << boolalpha << (repeatSeparator("Word", "X", 3) == "WordXWordXWord") << endl;
	cout << boolalpha << (repeatSeparator("This", "And", 2) == "ThisAndThis") << endl;
	cout << boolalpha << (repeatSeparator("This", "And", 1) == "This") << endl;

	cout << boolalpha << ("prefixAgain") << endl;
	cout << boolalpha << (prefixAgain("abXYabc", 1) == true) << endl;
	cout << boolalpha << (prefixAgain("abXYabc", 2) == true) << endl;
	cout << boolalpha << (prefixAgain("abXYabc", 3) == false) << endl;

	cout << boolalpha << ("subMiddle") << endl;
	cout << boolalpha << (subMiddle("AAxyzB", "xyz") == true) << endl;
	cout << boolalpha << (subMiddle("AxyzBB", "xyz") == true) << endl;
	cout << boolalpha << (subMiddle("AxyzBBB", "xyz") == false) << endl;

	cout << boolalpha << ("getSandwich") << endl;
	cout << boolalpha << (getSandwich("jellybreadjambreadbutter", "bread") == "jam") << endl;
	cout << boolalpha << (getSandwich("breadjambread", "bread") == "jam") << endl;
	cout << boolalpha << (getSandwich("xxbreadjambreadyy", "bread") == "jam") << endl;
	cout << boolalpha << (getSandwich("xxbreadyy", "bread") == "") << endl;

	cout << boolalpha << ("sameStarChar") << endl;
	cout << boolalpha << (sameStarChar("xy*yzz") == true) << endl;
	cout << boolalpha << (sameStarChar("xy*zzz") == false) << endl;
	cout << boolalpha << (sameStarChar("*xa*az") == true) << endl;

	cout << boolalpha << ("oneTwo") << endl;
	cout << boolalpha << (oneTwo("tcax") == "cat") << endl;
	cout << boolalpha << (oneTwo("abc") == "bca") << endl;
	cout << boolalpha << (oneTwo("tcagdo") == "catdog") << endl;

	cout << boolalpha << ("zipZap") << endl;
	cout << boolalpha << (zipZap("zipXzap") == "zpXzp") << endl;
	cout << boolalpha << (zipZap("zopzop") == "zpzp") << endl;
	cout << boolalpha << (zipZap("zzzopzop") == "zzzpzp") << endl;

	cout << boolalpha << ("starOut") << endl;
	cout << boolalpha << (starOut("sm**eilly") == "silly") << endl;
	cout << boolalpha << (starOut("ab*cd") == "ad") << endl;
	cout << boolalpha << (starOut("ab**cd") == "ad") << endl;
	cout << boolalpha << (starOut("sm**eilly") == "silly") << endl;

	cout << boolalpha << ("plusOut") << endl;
	cout << boolalpha << (plusOut("12xy34xyabcxy", "xy") == "++xy++xy+++xy") << endl;
	cout << boolalpha << (plusOut("12xy34", "xy") == "++xy++") << endl;
	cout << boolalpha << (plusOut("12xy34", "1") == "1+++++") << endl;
	cout << boolalpha << (plusOut("12xy34xyabcxy", "xy") == "++xy++xy+++xy") << endl;

	cout << boolalpha << ("wordEnds") << endl;
	cout << boolalpha << (wordEnds("abcXY123XYijk", "XY") == "c13i") << endl;
	cout << boolalpha << (wordEnds("XY1XY", "XY") == "11") << endl;
	cout << boolalpha << (wordEnds("XY123XY", "XY") == "13") << endl;
	cout << boolalpha << (wordEnds("XY1XY", "XY") == "11") << endl;

	return 0;
}

