// W32Codewars-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <locale>
#include <regex>
#include <string>
#include <vector>

using namespace std;

/*
Find the sum of the digits of all the numbers from 1 to N (both ends included).
For N = 10 the sum is 1+2+3+4+5+6+7+8+9+(1+0) = 46
For N = 11 the sum is 1+2+3+4+5+6+7+8+9+(1+0)+(1+1) = 48
For N = 12 the sum is 1+2+3+4+5+6+7+8+9+(1+0)+(1+1) +(1+2)= 51
When N = 123 Then 1038
When N = 1234 Then 15895
When N = 12345 Then 214455
*/
long TwistedSum(long n)
{
	long sum = 0;
	for (long i = 1; i <= n; i++)
	{
		long val = i;
		while (val != 0)
		{
			sum += val % 10;
			val /= 10;
		}
	}
	return sum;
}

/*
A child plays with a ball on the nth floor of a big building the height of which is known
(float parameter "h" in meters, h > 0) .

He lets out the ball. The ball rebounds for example to two-thirds of its height.
(float parameter "bounce", 0 < bounce < 1)

His mother looks out of a window that is 1.5 meters from the ground
(float parameters window < h).

How many times will the mother see the ball either falling or bouncing in front of the window
(return a positive integer unless conditions are not fulfilled in which case return -1) ?

Note
You will admit that the ball can only be seen if the height of the rebouncing ball is stricty greater than the window parameter.

Example:
h = 3, bounce = 0.66, window = 1.5, result is 3
h = 3, bounce = 1, window = 1.5, result is -1
*/
int bouncingBall(double h, double bounce, double window)
{
	// invalid input
	if (bounce >= 1 || window >= h || bounce <= 0 || h <= 0 || window <= 0)
		return -1;

	int count = 1;
	h = h * bounce;

	while (h > window)
	{
		count += 2;
		h = h * bounce;
	}

	if (h == window)
		count++;

	return count;
}

/*
Helper method
*/
bool reduceIt(vector<string> dir)
{
	for (unsigned int i = dir.size() - 2; i >= 0; i--)
	{
		if ((dir[i + 1] == "NORTH" && dir[i] == "SOUTH")
			|| (dir[i + 1] == "SOUTH" && dir[i] == "NORTH")
			|| (dir[i + 1] == "EAST"  && dir[i] == "WEST")
			|| (dir[i + 1] == "WEST"  && dir[i] == "EAST"))
		{
			dir.RemoveAt(i + 1);
			dir.RemoveAt(i);
			return true;
		}
	}

	return false;
}

/*
You have to write a function dirReduc which will take an array of strings and returns
an array of strings with the needless directions removed (W<->E or S<->N) side by side.
Examples
dirReduc(new String[]{"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"})
=> new String[]{"WEST"}
dirReduc(new String[]{"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH"})
=> new String[]{}
*/

vector<string> dirReduc(vector<string> arr)
{
	vector<string> directions(arr);
	bool didDelete = false;

	do
	{
		didDelete = reduceIt(directions);

	} while (didDelete);

	return directions;
}

/*
write an algorithm to check if a given string, s, can be formed from two other strings, part1 and part2.
The restriction is that the characters in part1 and part2 are in the same order as in s.
Example: 'codewars' is a merge from 'cdw' and 'oears':
s:  c o d e w a r s   = codewars
part1:  c   d   w         = cdw
part2:    o   e   a r s   = oears

Example2: Can we merge it? Yes, we can!' is a merge of 'n ee tYw n!' and 'Cawe mrgi? es, eca

*/
bool isMerge(string s, string part1, string part2)
{
	if (part1.size() + part2.size() != s.size())
		return false;
	if (part1.size() == 0 && part2.size() == 0)
		return true;

	int posS = 0;
	int posP1 = 0;
	int posP2 = 0;
	Queue<char> q = new Queue<char>();
	bool matchP1 = false;
	bool matchP2 = false;
	bool didUseQ = false;

	while (posS < s.size() - 1 && (posP1 < part1.size() || posP2 < part2.size()))
	{
		matchP1 = posP1 < part1.size() && s[posS] == part1[posP1];
		matchP2 = posP2 < part2.size() && s[posS] == part2[posP2];

		if (matchP1 && matchP2)
		{
			q.Enqueue(s[posS]);
			didUseQ = true;
			posS++;
			posP1++;
			posP2++;
		}

		else if (matchP1)
		{
			posS++;
			posP1++;
		}

		else if (matchP2)
		{
			posS++;
			posP2++;
		}

		else
		{
			if (q.size()() != 0 && q.Peek() == s[posS])
			{
				q.Dequeue();
				posS++;
			}
			else
			{
				return false;
			}
		}
	}

	while (q.size()() != 0 && q.Peek() == s[posS])
	{
		q.Dequeue();
		posS++;
	}

	if (posS == s.size() - 1 || (posS == s.size() && didUseQ))
		return true;
	else
		return false;
}

/*
The weight of a number is the sum of its digits. For example 99 has a "weight" of 18. Given a
string with weights in normal order can you give this string ordered by "weights" of these numbers?
For Example:
a = "56 65 74 100 99 68 86 180 90" ordered by numbers weights becomes: "100 180 90 56 65 74 68 86 99"
When two numbers have the same "weight", let us class them as if they were strings and not numbers so
180 is before 90 since, having the same "weight" (9) it comes before as a string.
All numbers in the list are positive numbers and the list can be empty.

cout << boolalpha << ("orderWeight");
cout << boolalpha << (orderWeight("2000 103 123 4444 99") == "103 123 4444 99 2000");
cout << boolalpha << (orderWeight("11 11 2000 10003 22 123 1234000 44444444 9999") == "2000 10003 1234000 44444444 9999 11 11 22 123");
*/

string orderWeight(string strng)
{
	var tlist = new List<Tuple<int, string>>();
	vector<string> delimiters = { " " };
	vector<string> input = strng.Split(delimiters, StringSplitOptions.RemoveEmptyEntries);

	for(string s in input)
	{
		tlist.push_back(new Tuple<int, string>(getWeight(s), s));
	}

	var result = tlist
		.OrderBy(x = > x.Item1)
		.ThenBy(x = > x.Item2)
		.Select(x = > x.Item2)
		.ToList();

	return string.Join(" ", result);
}

int getWeight(string s)
{
	string str = s.ToLower().Trim();
	int sum = 0;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		sum += (int)char.GetNumericValue(str[i]);
	}
	return sum;
}


/*
Write a function, which takes a non-negative integer (seconds) as input
and returns the time in a human-readable format (HH:MM:SS)

HH = hours, padded to 2 digits, range: 00 - 99
MM = minutes, padded to 2 digits, range: 00 - 59
SS = seconds, padded to 2 digits, range: 00 - 59
The maximum time never exceeds 359999 (99:59:59)

cout << boolalpha << ("GetReadableTime");
cout << boolalpha << (GetReadableTime(0));// == "00:00:00");
cout << boolalpha << (GetReadableTime(60));// == "00:01:00");
cout << boolalpha << (GetReadableTime(86399));// == "23:59:59");
cout << boolalpha << (GetReadableTime(359999));// == "4.03:59:59");
*/
string GetReadableTime(int seconds)
{
	TimeSpan span = TimeSpan.FromSeconds(seconds);

	// Note to get this format: 99:59:59 use (int)span.TotalHours
	return (int)span.TotalHours + ":" + (int)span.Minutes + ":" + (int)span.Seconds;

	// Note to get this format: "4.03:59:59" use the default span
	//return span;
}


/*
Score a throw according to these rules. You will always be given an array with five six-sided dice values.

Three 1's => 1000 points
Three 6's =>  600 points
Three 5's =>  500 points
Three 4's =>  400 points
Three 3's =>  300 points
Three 2's =>  200 points
One   1   =>  100 points
One   5   =>   50 point

A single die can only be counted once in each roll. For example, a "5" can only count as part of a triplet
(contributing to the 500 points) or as a single 50 points, but not both in the same roll.

Example scoring
Throw       Score
5 1 3 4 1   50 + 2 * 100 = 250
1 1 1 3 1   1000 + 100 = 1100
2 4 4 5 4   400 + 50 = 450
*/

int Score(vector<int> dice)
{
	vector<int> vals(6);

	for(int d : dice)
	{
		if (d == 1) vals[0]++;
		else if (d == 2) vals[1]++;
		else if (d == 3) vals[2]++;
		else if (d == 4) vals[3]++;
		else if (d == 5) vals[4]++;
		else if (d == 6) vals[5]++;
	}

	int score = 0;

	for (unsigned int i = 0; i < vals.size(); i++)
	{
		if (vals[i] >= 3)
		{
			if (i == 0)
				score += 1000;
			else
				score += 100 * (i + 1);
			vals[i] -= 3;
		}
	}

	score += 100 * vals[0];
	score += 50 * vals[4];

	return score;
}//score


 /*
 Compute sum of digits
 Ex: digital_root(16) => 7
 */
int DigitalRoot(long n)
{
	int sum = 0;

	while (n != 0)
	{
		sum += (int)(n % 10);
		n /= 10;
	}

	return sum;
}

/*
Compute sum of digits
Ex: digital_root("16") => 7
*/
int DigitalRootString(string num)
{
	int sum = 0;

	for(char c : num)
	{
		if (char.IsDigit(c))
		{
			sum += (int)char.GetNumericValue(c);
		}
	}
	return sum;
}

/*
You have to create a function that takes a positive integer number
and returns the next bigger number formed by the same digits:
NextBiggerNumber(12)==21
NextBiggerNumber(513)==531
NextBiggerNumber(2107)==2701
Assert.AreEqual(441, Kata.NextBiggerNumber(414));
Assert.AreEqual(414, Kata.NextBiggerNumber(144));

If no bigger number can be composed using those digits, return -1:
NextBiggerNumber(9)==-1
NextBiggerNumber(111)==-1
NextBiggerNumber(531)==-1
*/
long NextBiggerNumber(long n)
{
	string nString = to_string(abs(n));

	//cout << boolalpha << ("original num " + nString);

	// if there is only one digit there is nothing to rearrange
	if (nString.size() <= 1)
		return -1;

	vector<char> letters = nString.ToCharArray();
	vector<int> digits(letters.size());

	for (unsigned int i = 0; i < digits.size(); i++)
	{
		digits[i] = Convert.ToInt16(Char.GetNumericValue(letters[i]));
	}

	vector<int> newDigits(digits.size());
	Array.Copy(digits, newDigits, newDigits.size());

	// find the first digit to swap
	int pos = newDigits.size() - 1;
	bool allSame = true;
	for (unsigned int i = newDigits.size() - 1; i > 0; i--)
	{
		pos = i - 1;

		if (newDigits[i - 1] != newDigits[i])
			allSame = false;

		if (newDigits[i - 1] < newDigits[i])
			break;
	}

	// if digits are all the same there is nothing to rearrange
	if (allSame)
		return -1;

	// find the last digit to swap
	int endpos = newDigits.size() - 1;
	for (unsigned int i = pos + 1; i < newDigits.size(); i++)
	{
		endpos = i + 1;

		if (i < newDigits.size() - 1 && newDigits[i] > newDigits[i + 1])
			break;
	}

	if (endpos >= newDigits.size())
		endpos = newDigits.size() - 1;

	//cout << boolalpha << ("pos " + pos + " endpos " + endpos);
	vector<long> candidates = new vector<long>();

	for (unsigned int i = newDigits.size() - 1; i >= pos; i--)
	{
		// rotate digits between pos and endpos
		int temp = newDigits[pos];
		for (unsigned int j = pos; j < endpos; j++)
		{
			newDigits[j] = newDigits[j + 1];
		}
		newDigits[endpos] = temp;

		// create new number from the rotated digits
		long newNum = 0;
		for (unsigned int rank = 0; rank < newDigits.size(); rank++)
			newNum += (long)pow(10, rank) * newDigits[newDigits.size() - 1 - rank];

		// if new number is big enough add it to the candidates list
		if (newNum > n)
			candidates.push_back(newNum);
		//cout << boolalpha << ("newNum " + newNum);
		//Array.Copy(digits, newDigits, newDigits.size());

	}

	if (candidates.size() > 0)
		return candidates.Min();
	else
		return -1;
}

/*
You have to create a function that takes a positive integer number
and returns the next bigger number formed by the same digits:
NextBiggerNumber(12)==21
NextBiggerNumber(513)==531
NextBiggerNumber(2017)==2071
Assert.AreEqual(441, Kata.NextBiggerNumber(414));
Assert.AreEqual(414, Kata.NextBiggerNumber(144));

If no bigger number can be composed using those digits, return -1:
NextBiggerNumber(9)==-1
NextBiggerNumber(111)==-1
NextBiggerNumber(531)==-1
*/

long NextBiggerNumber2(long n)
{
	string nString = abs(n);
	vector<char> letters = nString.ToCharArray();
	vector<int> digitsletters.size());

	for (unsigned int i = 0; i <= digits.size() - 1; i++)
	{
		digits[i] = Convert.ToInt16(Char.GetNumericValue(letters[i]));
	}

	vector<int> newDigits = new int[digits.size()];
	Array.Copy(digits, newDigits, newDigits.size());

	int curpos = newDigits.size() - 1;
	int maxpos = curpos;
	int minpos = curpos;
	bool swap = false;

	// find the leftmost digit to swap
	do
	{
		// for max want leftmost of equal digits so use >=
		if (newDigits[curpos] >= newDigits[maxpos])
		{
			maxpos = curpos;
		}

		// for min want rightmost of equal digits so use <
		if (newDigits[curpos] < newDigits[minpos])
		{
			minpos = curpos;
		}

		// found the swap point
		if (newDigits[curpos] < newDigits[maxpos])
		{
			swap = true;
			break;
		}

		curpos -= 1;
	} while (curpos >= 0);

	if (swap)
	{
		int temp = newDigits[curpos];
		newDigits[curpos] = newDigits[maxpos];
		newDigits[maxpos] = temp;

		// find the rightmost digit to swap
		if (minpos != curpos && minpos != maxpos)
		{
			temp = newDigits[maxpos];
			newDigits[maxpos] = newDigits[minpos];
			newDigits[minpos] = temp;
		}

		long newNum = 0L;
		//convert array with swapped digits back into a single number
		for (unsigned int rank = 0; rank <= newDigits.size() - 1; rank++)
		{
			newNum += Convert.ToInt64(pow(10, rank)) * newDigits[newDigits.size() - 1 - rank];
		}

		return newNum;
	}
	else
	{
		return -1L;
	}
}

/*
Cut a pizza into slices. Return the maximum number of slices (not necessarily of
equal size) possible with K cuts. If K is a negative number, the result must be -1.
Examples  maxPizza(0) == 1  maxPizza(1) == 2 maxPizza(2) == 4 maxPizza(3) == 7
*/
int maxPizza(int cut)
{
	if (cut < 0)
		return -1;

	int sum = 1;

	for (unsigned int i = cut; i > 0; i--)
		sum += i;

	return sum;
}


/*
The nth triangle number is equal to the sum of the n natural numbers from 1 to n.
Check if a given input is a valid triangle number. Return true if it is, false if it is not.
Note that any non-integers, including non-number types, are not triangle numbers.
You may assume that the given input, if it is a number, is always positive.
Triangle numbers: 0, 1, 3, 6, 10, 15, 21, ... 120 ...  300, 325, ...
n = n*(n+1)/2
*/
bool isTriangleNumber(long number)
{
	long previous = 0;
	long current = 0;
	long increment = 1;

	while (current < number)
	{
		current = previous + increment;
		previous = current;
		increment++;
	}

	return current == number;
}


/*
Write a function called validBraces that takes a string of braces, and determines if the order of the
braces is valid. validBraces should return true if the string is valid, and false if it's invalid.
Examples:
validBraces( "(){}[]" ) => returns true
validBraces( "(}" ) => returns false
validBraces( "[(])" ) => returns false
validBraces( "([{}])" ) => returns true
*/
bool validBraces(string input)
{
	Stack<char> stack = new Stack<char>();

	for(char c in input)
	{
		if (c == '(' || c == '[' || c == '{')
		{
			stack.Push(c);
		}
		else if (c == ')' || c == ']' || c == '}')
		{
			if (stack.size() == 0)
				return false;

			char closing = stack.Pop();

			if (c == ')' && closing != '(')
				return false;
			else if (c == ']' && closing != '[')
				return false;
			else if (c == '}' && closing != '{')
				return false;

		}
	}

	if (stack.size() == 0)
		return true;
	else
		return false;
}

/*
Write a function that takes in a binary string and returns the equivalent decoded text (the text is ASCII encoded).
Each 8 bits on the binary string represent 1 character on the ASCII table.
The input string will always be a valid binary string.
In the case of an empty binary string your function should return an empty string.
cout << boolalpha << (BinaryToString("") == "");
cout << boolalpha << (BinaryToString("0100100001100101011011000110110001101111") == "Hello");
*/

string BinaryToString(string binary)
{
	string text;
	vector<byte> bytes = new byte[binary.size() / 8];

	for (unsigned int i = 0; i < binary.size(); i += 8)
	{
		bytes[i / 8] = Convert.ToByte(binary.substr(i, 8), 2);
	}

	return Encoding.ASCII.GetString(bytes);
}

/*
Given the string representations of two integers, return the string representation of their sum.
For example:
cout << boolalpha << ("sumStrings"");
cout << boolalpha << (sumStrings("1","2") == "3");
cout << boolalpha << (sumStrings("123","456") == "579");
cout << boolalpha << (sumStrings("821429", "999999"));// == "1821428");
The input will contain no characters besides the ten numerals "0" to "9".
NOTE The tests will try to overflow your INTS!
test7 == "712577413488402631964821329"
test8 == "131151201344081895336534324866"
*/
string sumStrings(string a, string b)
{
	vector<string> aParts();
	vector<string> bParts();
	const int chunk = 6;

	if (a.size() <= chunk)
		aParts.push_back(a);
	else
	{
		for (unsigned int i = a.size() - chunk; i >= 0; i -= chunk)
		{
			aParts.push_back(a.substr(i, chunk));
			if (i != 0 && i < chunk)
				aParts.push_back(a.substr(0, i));
		}
	}

	if (b.size() <= chunk)
		bParts.push_back(b);
	else
	{
		for (unsigned int i = b.size() - chunk; i >= 0; i -= chunk)
		{
			bParts.push_back(b.substr(i, chunk));
			if (i != 0 && i < chunk)
				bParts.push_back(b.substr(0, i));
		}
	}

	vector<long> results;
	long overage = 0;
	long sum = 0;
	for (unsigned int i = 0; i < max(aParts.size(), bParts.size()); i++)
	{
		if (i < aParts.size() && i < bParts.size())
			sum = overage + Convert.ToInt64(aParts[i]) + Convert.ToInt64(bParts[i]);
		else if (i < aParts.size())
			sum = overage + Convert.ToInt64(aParts[i]);
		else
			sum = overage + Convert.ToInt64(bParts[i]);

		overage = 0;
		string sumString = sum;
		if (sumString.size() > chunk)
		{
			int len = sumString.size() - chunk;
			string front = sumString.substr(0, len);
			string back = sumString.substr(len);
			overage = Convert.ToInt64(front);
			sum = Convert.ToInt64(back);
		}
		results.push_back(sum);
	}

	string sb;

	for (unsigned int i = results.size() - 1; i >= 0; i--)
	{
		sb += (results[i]);
	}

	if (overage > 0)
		sb.Insert(0, overage);

	return sb;
}

/*
Given the string representations of two integers, return the string representation of their sum.
For example:
cout << boolalpha << ("sumStrings"");
cout << boolalpha << (sumStrings("1","2") == "3");
cout << boolalpha << (sumStrings("123","456") == "579");
cout << boolalpha << (sumStrings("821429", "999999"));// == "1821428");
The input will contain no characters besides the ten numerals "0" to "9".
NOTE The tests will try to overflow your INTS!
test7 == "712577413488402631964821329"
test8 == "131151201344081895336534324866"
*/
string sumStrings2(string a, string b)
{
	string longest = a.size() >= b.size() ? a : b;
	string shortest = a.size() < b.size() ? a : b;
	int carry = 0;
	int sum = 0;
	int pos = longest.size() - 1;
	int differenceInLengths = longest.size() - shortest.size();
	string result;

	do
	{
		sum = carry + (int)Char.GetNumericValue(longest[pos]);

		if (pos - differenceInLengths >= 0)
			sum += (int)Char.GetNumericValue(shortest[pos - differenceInLengths]);

		if (sum >= 10)
		{
			carry = sum / 10;
			sum = sum % 10;
		}
		else
			carry = 0;

		result.Insert(0, sum);

	} while (--pos >= 0);

	if (carry > 0)
		result.Insert(0, carry);

	return result;
}

/*
Given the string representations of two integers, return the string representation of their sum.
For example:
cout << boolalpha << ("sumStrings"");
cout << boolalpha << (sumStrings("1","2") == "3");
cout << boolalpha << (sumStrings("123","456") == "579");
cout << boolalpha << (sumStrings("821429", "999999"));// == "1821428");
The input will contain no characters besides the ten numerals "0" to "9".
NOTE The tests will try to overflow your INTS!
test7 == "712577413488402631964821329"
test8 == "131151201344081895336534324866"
*/
string sumStrings3(string a, string b)
{
	string sb;
	int posA = a.size() - 1;
	int posB = b.size() - 1;
	int carry = 0;
	int sum = 0;

	while (posA > -1 || posB > -1)
	{
		if (posA > -1 && posB > -1)
			sum = (int)(char.GetNumericValue(a[posA]) + char.GetNumericValue(b[posB]));
		else if (posA > -1)
			sum = (int)(char.GetNumericValue(a[posA]));
		else if (posB > -1)
			sum = (int)(char.GetNumericValue(b[posB]));

		sb.Insert(0, carry + sum % 10);
		carry = sum >= 10 ? 1 : 0;
		posA--;
		posB--;
	}

	if (carry > 0)
		sb.Insert(0, carry);

	return sb;
}

/*
You have to create a method "compoundArray" which should take as input two int arrays of
different length and return one int array with numbers of both arrays shuffled one by one.
Example: Input - {1,2,3,4,5,6} and {9,8,7,6} Output - {1,9,2,8,3,7,4,6,5,6}
*/
vector<int> compoundArray(vector<int> a, vector<int> b)
{
	int aLen = a.size();
	int bLen = b.size();
	int min = std::min(aLen, bLen);
	vector<int> result(aLen + bLen);

	for (unsigned int i = 0; i < min; i++)
	{
		int rpos = 2 * i;
		result[rpos] = a[i];
		result[rpos + 1] = b[i];
	}

	if (aLen < bLen)
		Array.Copy(b, aLen, result, aLen * 2, bLen - aLen);
	else if (bLen < aLen)
		Array.Copy(a, bLen, result, bLen * 2, aLen - bLen);

	return result;
}

/*
Vowel2Index(string s)
Takes in a string and replaces all the vowels [a,e,i,o,u]
with their respective positions within that string.
Kata.vowel2Index("this is my string") == "th3s 6s my str15ng"
Kata.vowel2Index("Codewars is the best site in the world")
*/
string vowel2Index(string str)
{
	string sb;
	vector<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (vowels.Contains(str[i]))
			sb += (i + 1);
		else
			sb += (str[i]);
	}

	return sb;
}

/*
Each part of the string is of the form: h|m|s where h, m, s are positive
or null integer (represented as strings) with one or two digits.
You are asked for giving three statistics; range, average and median
where hh, mm, ss are integers (represented by strings) with each 2 digits.
Example Input: "01|15|59, 1|47|6, 01|17|20, 1|32|34, 2|3|17"
Example Output: "Range: 00|47|18 Average: 01|35|15 Median: 01|32|34"
*/
string stat(string strg)
{
	// In:  "01|15|59, 1|47|16, 01|17|20, 1|32|34, 2|17|17"
	// Out: "Range: 01|01|18 Average: 01|38|05 Median: 01|32|34"
	List<TimeSpan> times = new List<TimeSpan>();
	vector<string> timeStrings = strg.Split(',');

	for(string tStr in timeStrings)
	{
		TimeSpan span = TimeSpan.Parse(tStr.Trim().Replace("|", ":"));
		times.push_back(span);
	}

	times.Sort();

	TimeSpan min = times.Min();
	TimeSpan max = times.Max();
	TimeSpan range = max - min;
	TimeSpan sum = default(TimeSpan);

	for(TimeSpan ts in times)
	{
		sum += ts;
	}


	TimeSpan average = TimeSpan.FromSeconds(Math.Round(sum.TotalSeconds / times.size()()));
	TimeSpan median = times[0];

	if (times.size()() % 2 == 1)
		median = times[times.size()() / 2];
	else
	{
		TimeSpan doubleMedian = times[times.size()() / 2 - 1] + times[times.size()() / 2];
		median = TimeSpan.FromSeconds(Math.Round(doubleMedian.TotalSeconds / 2));
	}

	string rangeStr = range.Replace(":", "|");
	string averageStr = average.Replace(":", "|");
	string medianStr = median.Replace(":", "|");
	string result = "Range: " + rangeStr + " Average: " + averageStr + " Median: " + medianStr;

	return result;
}


/*
You are going to be given a string. Let's say you start with this: 012345
The first thing you do is reverse it:543210
Then you will take the string from the 1st position and reverse it again:501234
Then you will take the string from the 2nd position and reverse it again:504321
Then you will take the string from the 3rd position and reverse it again:504123
Continue this pattern until you have done every single position, and then you will
return the string you have created. For this particular number, you would return: 504132
*/
string flipNumber(string n)
{
	string str = n;

	for (unsigned int i = 0; i < n.size() - 1; i++)
	{
		str = flipString(str, i);
	}

	return str;
}

string flipString(string n, int index)
{
	string left = n.substr(0, index);
	vector<char> right = n.substr(index).ToCharArray();
	Array.Reverse(right);
	return  left + new string(right);
}

/*
You are given two arrays a1 and a2 of strings.Each string is composed with letters from a to z.
Let x be any string in the first array and y be any string in the second array.
Find max(abs(length(x) − length(y))).  If a1 or a2 are empty return -1.
s1 = ["hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"]
s2 = ["cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"]
maxDiffLength(s1, s2) --> 13
*/
int maxDiffLength(vector<string> a1, vector<string> a2)
{
	if (a1 == null || a1.size() == 0 || a2 == null || a2.size() == 0)
		return -1;

	int max1 = a1.Max(w = > w.size());
	int max2 = a2.Max(w = > w.size());
	int min1 = a1.Min(w = > w.size());
	int min2 = a2.Min(w = > w.size());

	return max(max1 - min2, max2 - min1);
}

/*
Given two arrays of strings a1 and a2 return a sorted array r in lexicographical order
and without duplicates of the strings of a1 which are substrings of strings of a2.
Example 1:
a1 = ["arp", "live", "strong"]
a2 = ["lively", "alive", "harp", "sharp", "armstrong"]
returns ["arp", "live", "strong"]
Example 2:
a1 = ["tarp", "mice", "bull"]
a2 = ["lively", "alive", "harp", "sharp", "armstrong"]
returns []
*/
vector<string> inArray(vector<string> array1, vector<string> array2)
{
	vector<string> list();

	for(string s : array2)
		for(string t : array1)
		if (!list.Contains(t) && s.Contains(t))
		{
			list.push_back(t);
			break;
		}

	list.Sort();
	//list.ForEach(item => Console.Write(item + " "));
	return list;
}

/*
Return the sum of following series upto nth term(parameter).
Series: 1 + 1/4 + 1/7 + 1/10 + 1/13 + 1/16 +...
Rules:
You need to round the answer upto 2 decimal places and return it as String.
If the given value is 0 then it should return 0.00
You will only be given Natural Numbers as arguments.
Examples:
SeriesSum(1) => 1 = "1.00"
SeriesSum(2) => 1 + 1/4 = "1.25"
SeriesSum(5) => 1 + 1/4 + 1/7 + 1/10 + 1/13 = "1.57"
*/
string seriesSum(int n)
{
	double numerator = 1.0;
	int denominator = 1;
	double sum = 0;

	for (unsigned int i = 0; i < n; i++)
	{
		sum += (numerator / denominator);
		denominator += 3;
	}

	return Math.Round(sum, 2).ToString("0.00");
}


int main()
{

	cout << boolalpha << ("TwistedSum") << endl;
	cout << boolalpha << (TwistedSum(10)) << endl;// == 46 = 46 * 1 + 0) << endl;
	cout << boolalpha << (TwistedSum(11)) << endl;// == 48) << endl;
	cout << boolalpha << (TwistedSum(12)) << endl;// == 51) << endl;
	cout << boolalpha << (TwistedSum(20)) << endl;// == 102 = 46 * 2 + 10) << endl; 
	cout << boolalpha << (TwistedSum(90)) << endl;// == 774 = 46 * 9 + 360) << endl;
	cout << boolalpha << (TwistedSum(99)) << endl;// == 900 = ) << endl;
	cout << boolalpha << (TwistedSum(100)) << endl;// == 901 = 46 * 10 + 441) << endl;

	cout << boolalpha << ("bouncingBall") << endl;
	cout << boolalpha << (bouncingBall(h: 3, bounce : 0.66, window : 1.5) == 3) << endl;
	cout << boolalpha << (bouncingBall(h: 3, bounce : 1, window : 1.5) == -1) << endl;

	cout << boolalpha << ("dirReduc") << endl;
	cout << boolalpha << (dirReduc(vector<string>{ "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" }) == (vector<string>{ "WEST" })) << endl;
	cout << boolalpha << (string.Join(" ", dirReduc(vector<string>{ "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" }))) << endl;
	cout << boolalpha << (dirReduc(vector<string>{ "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH" }) == (vector<string>{})) << endl;
	cout << boolalpha << (string.Join(" ", dirReduc(vector<string>{ "NORTH", "EAST", "SOUTH", "EAST", "WEST", "NORTH", "WEST" }))) << endl;

	cout << boolalpha << ("isMerge") << endl;
	cout << boolalpha << (isMerge("codewars", "cdw", "oears") == true) << endl;
	cout << boolalpha << (isMerge("codewars", "cod", "wars") == false) << endl;
	cout << boolalpha << (isMerge("Can we merge it? Yes, we can!", "n ee tYw n!", "Cawe mrgi? es, eca") == true) << endl;
	cout << boolalpha << (isMerge("", "", "") == true) << endl;
	cout << boolalpha << (isMerge("BananaBanana", "Banana", "Banana") == true) << endl;

	cout << boolalpha << ("orderWeight") << endl;
	cout << boolalpha << (orderWeight("103 123 4444 99 2000") == "2000 103 123 4444 99") << endl;
	cout << boolalpha << (orderWeight("2000 10003 1234000 44444444 9999 11 11 22 123") == "11 11 2000 10003 22 123 1234000 44444444 9999") << endl;

	cout << boolalpha << ("GetReadableTime") << endl;
	cout << boolalpha << (GetReadableTime(0)) << endl;// == "00:00:00") << endl;
	cout << boolalpha << (GetReadableTime(60)) << endl;// == "00:01:00") << endl;
	cout << boolalpha << (GetReadableTime(86399)) << endl;// == "23:59:59") << endl;
	cout << boolalpha << (GetReadableTime(359999)) << endl;// == "4.03:59:59") << endl; 

	cout << boolalpha << ("Score") << endl;
	cout << boolalpha << (Score(vector<int> { 5, 1, 3, 4, 1 }) == 250) << endl;
	cout << boolalpha << (Score(vector<int> { 1, 1, 1, 3, 1 }) == 1100) << endl;
	cout << boolalpha << (Score(vector<int> { 2, 4, 4, 5, 4 }) == 450) << endl;

	cout << boolalpha << ("DigitalRoot") << endl;
	cout << boolalpha << (DigitalRoot(15) == 6) << endl;
	cout << boolalpha << (DigitalRoot(16) == 7) << endl;

	cout << boolalpha << ("NextBiggerNumber") << endl;
	cout << boolalpha << (NextBiggerNumber(102) == 120) << endl;
	cout << boolalpha << (NextBiggerNumber(144) == 414) << endl;
	cout << boolalpha << (NextBiggerNumber(513) == 531) << endl;
	cout << boolalpha << (NextBiggerNumber(12) == 21) << endl;
	cout << boolalpha << (NextBiggerNumber(2071) == 2107) << endl;
	cout << boolalpha << (NextBiggerNumber(67890) == 67908) << endl;
	cout << boolalpha << (NextBiggerNumber(678900) == 679008) << endl;
	cout << boolalpha << (NextBiggerNumber(111) == -1) << endl;
	cout << boolalpha << (NextBiggerNumber(9) == -1) << endl;

	cout << boolalpha << ("NextBiggerNumber2") << endl;
	cout << boolalpha << (NextBiggerNumber2(102) == 120) << endl;
	cout << boolalpha << (NextBiggerNumber2(144) == 414) << endl;
	cout << boolalpha << (NextBiggerNumber2(513) == 531) << endl;
	cout << boolalpha << (NextBiggerNumber2(12) == 21) << endl;
	cout << boolalpha << (NextBiggerNumber2(2071) == 2107) << endl;
	cout << boolalpha << (NextBiggerNumber2(67890) == 67908) << endl;
	cout << boolalpha << (NextBiggerNumber2(678900) == 679008) << endl;
	cout << boolalpha << (NextBiggerNumber2(111) == -1) << endl;
	cout << boolalpha << (NextBiggerNumber2(9) == -1) << endl;

	cout << boolalpha << ("maxPizza") << endl;
	cout << boolalpha << (maxPizza(-1) == -1) << endl;
	cout << boolalpha << (maxPizza(0) == 1) << endl;
	cout << boolalpha << (maxPizza(1) == 2) << endl;
	cout << boolalpha << (maxPizza(2) == 4) << endl;
	cout << boolalpha << (maxPizza(3) == 7) << endl;

	cout << boolalpha << ("isTriangleNumber") << endl;
	cout << boolalpha << (isTriangleNumber(0) == true) << endl;
	cout << boolalpha << (isTriangleNumber(1) == true) << endl;
	cout << boolalpha << (isTriangleNumber(2) == false) << endl;
	cout << boolalpha << (isTriangleNumber(3) == true) << endl;
	cout << boolalpha << (isTriangleNumber(4) == false) << endl;
	cout << boolalpha << (isTriangleNumber(5) == false) << endl;
	cout << boolalpha << (isTriangleNumber(6) == true) << endl;
	cout << boolalpha << (isTriangleNumber(10) == true) << endl;
	cout << boolalpha << (isTriangleNumber(120) == true) << endl;
	cout << boolalpha << (isTriangleNumber(300) == true) << endl;
	cout << boolalpha << (isTriangleNumber(325) == true) << endl;

	cout << boolalpha << ("validBraces") << endl;
	cout << boolalpha << (validBraces("(){}[]") == true) << endl;
	cout << boolalpha << (validBraces("(}") == false) << endl;
	cout << boolalpha << (validBraces("[(])") == false) << endl;
	cout << boolalpha << (validBraces("([{}])") == true) << endl;

	cout << boolalpha << ("BinaryToString") << endl;
	cout << boolalpha << (BinaryToString("") == "") << endl;
	cout << boolalpha << (BinaryToString("0100100001100101011011000110110001101111") == "Hello") << endl;

	cout << boolalpha << ("sumStrings") << endl;
	cout << boolalpha << (sumStrings("1", "2")) << endl;// == "3") << endl;
	cout << boolalpha << (sumStrings("123", "456")) << endl;// == "579") << endl;
	cout << boolalpha << (sumStrings("821429", "999999")) << endl;// == "1821428") << endl;
	cout << boolalpha << (sumStrings("712577413488402631964821329", "100")) << endl;// == "712577413488402631964821429") << endl;

	cout << boolalpha << ("sumStrings2") << endl;
	cout << boolalpha << (sumStrings2("1", "2")) << endl;// == "3") << endl;
	cout << boolalpha << (sumStrings2("123", "456")) << endl;// == "579") << endl;
	cout << boolalpha << (sumStrings2("821429", "999999")) << endl;// == "1821428") << endl;
	cout << boolalpha << (sumStrings2("712577413488402631964821329", "100")) << endl;// == "712577413488402631964821429") << endl;

	cout << boolalpha << ("sumStrings3") << endl;
	cout << boolalpha << (sumStrings3("1", "2")) << endl;// == "3") << endl;
	cout << boolalpha << (sumStrings3("123", "456")) << endl;// == "579") << endl;
	cout << boolalpha << (sumStrings3("821429", "999999")) << endl;// == "1821428") << endl;
	cout << boolalpha << (sumStrings3("712577413488402631964821329", "100")) << endl;// == "712577413488402631964821429") << endl;

	cout << boolalpha << ("compoundArray") << endl;
	cout << boolalpha << (compoundArray(vector<int> { 1, 2, 3, 4, 5, 6 },
		vector<int> { 9, 8, 7, 6 }) == (vector<int> { 1, 9, 2, 8, 3, 7, 4, 6, 5, 6 })) << endl;


	cout << boolalpha << ("vowel2Index") << endl;
	cout << boolalpha << (vowel2Index("this is my string") == "th3s 6s my str15ng") << endl;
	cout << boolalpha << (vowel2Index("Codewars is the best site in the world")
		== "C2d4w6rs 10s th15 b18st s23t25 27n th32 w35rld") << endl;


	cout << boolalpha << ("stat") << endl;
	cout << boolalpha << (stat("01|15|59, 1|47|16, 01|17|20, 1|32|34, 2|17|17")
		== "Range: 01|01|18 Average: 01|38|05 Median: 01|32|34") << endl;
	cout << boolalpha << (stat("02|15|59, 2|47|16, 02|17|20, 2|32|34, 2|17|17, 2|22|00, 2|31|41")
		== "Range: 00|31|17 Average: 02|26|18 Median: 02|22|00") << endl;
	cout << boolalpha << (stat("01|15|59, 1|47|16, 01|17|20, 1|32|34")) << endl;

	cout << boolalpha << ("flipNumber") << endl;
	cout << boolalpha << (flipNumber("012345") == "504132") << endl;

	cout << boolalpha << ("maxDiffLength") << endl;
	vector<string> MDL1 = { "hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz" };
	vector<string> MDL2 = { "cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww" };
	cout << boolalpha << (maxDiffLength(MDL1, MDL2) == 13) << endl;

	cout << boolalpha << ("inArray") << endl;
	vector<string> inA1 = { "arp", "live", "strong" };
	vector<string> inA2 = { "lively", "alive", "harp", "sharp", "armstrong" };
	vector<string> inAResult = { "arp", "live", "strong" };
	cout << boolalpha << (inArray(inA1, inA2) == (inAResult)) << endl;

	cout << boolalpha << ("seriesSum") << endl;
	cout << boolalpha << (seriesSum(0) == "0.00") << endl;
	cout << boolalpha << (seriesSum(1) == "1.00") << endl;
	cout << boolalpha << (seriesSum(2) == "1.25") << endl; // 1 + 1 / 4
	cout << boolalpha << (seriesSum(5) == "1.57") << endl; // 1 + 1 / 4 + 1 / 7 + 1 / 10 + 1 / 13

    return 0;
}

