// W32Logic-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <locale>
#include <regex>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/*
Given three ints, a b c, return true if two or more of them have the same
rightmost digit. The ints are non-negative.

lastDigit(23, 19, 13) == true
lastDigit(23, 19, 12) == false
lastDigit(23, 19, 3) == true
*/
bool lastDigit(std::initializer_list<int> values)
{
	unordered_set<int> digits;

	for (auto val : values){
		if (digits.find(val % 10) != digits.end())
			return true;
		else
			digits.insert(val % 10);
	}
	return false;
}


/*
Given three ints, a b c, return true if one of them is 10 or more less than
one of the others.

lessBy10(1, 7, 11) == true
lessBy10(1, 7, 10) == false
lessBy10(11, 1, 7) == true
*/
bool lessBy10(std::initializer_list<int> values)
{
	int min = INT32_MAX;
	int max = INT32_MIN;

	for (unsigned int v : values) {
		if (v < min)
			min = v;
		if (v > max)
			max = v;
		if (max - min >= 10)
			break;
	}

	return max - min >= 10;
}


/*
Return the sum of two 6-sided dice rolls, each in the range 1..6.
However, if noDoubles is true, if the two dice show the same value,
increment one die to the next value, wrapping around to 1 if its value was 6.

withoutDoubles(2, 3, true) == 5
withoutDoubles(3, 3, true) == 7
withoutDoubles(3, 3, false) == 6
*/
int withoutDoubles(int die1, int die2, bool noDoubles)
{
	if (noDoubles && (die1 == die2))
		if (die1 == 6)
			die1 = 1;
		else
			die1++;

	return die1 + die2;
}

/*
Given two int values, return whichever value is larger.
However if the two values have the same remainder when divided by 5,
then the return the smaller value. However, in all cases, if the two
values are the same, return 0.

maxMod5(25, 15) == 15
maxMod5(6, 2) == 6
maxMod5(3, 3) == 0
*/
int maxMod5(int a, int b)
{
	if (a == b)
		return 0;
	else if (a % 5 == b % 5)
		return min(a, b);
	else
		return max(a, b);
}

/*
You have a red lottery ticket showing ints a, b, and c, each of which
is 0, 1, or 2. If they are all the value 2, the result is 10. Otherwise
if they are all the same, the result is 5. Otherwise so long as both
b and c are different from a, the result is 1. Otherwise the result is 0.

redTicket(2, 2, 2) == 10
redTicket(2, 2, 1) == 0
redTicket(0, 0, 0) == 5
*/
template <class T>
int redTicket(std::initializer_list<T> values)
{
	unordered_set<T> vals(values);
	bool allSame = vals.size() == 1;
	bool allDifferent = vals.size() == values.size();
	unordered_set<T>::iterator i = vals.begin();
	T val = *i;

	if (allSame)
		return val == 2 ? 10 : 5;
	else if (allDifferent)
		return 1;
	else
		return 0;
}

/*
You have a green lottery ticket, with ints a, b, and c on it.
If the numbers are all different from each other, the result is 0.
If all of the numbers are the same, the result is 20.
If two of the numbers are the same, the result is 10.

greenTicket(1, 2, 3) == 0
greenTicket(2, 2, 2) == 20
greenTicket(1, 1, 2) == 10
*/
template <class T>
int greenTicket(std::initializer_list<T> values)
{
	bool allSame = true;
	bool allDifferent = true;
	vector<T> vals(values);

	for (unsigned int i = 0; i < vals.size(); i++)
	{
		for (unsigned int j = i + 1; j < vals.size(); j++)
		{
			if (vals[i] != vals[j])
				allSame = false;
			if (vals[i] == vals[j])
				allDifferent = false;
		}
	}

	if (allSame)
		return 20;
	else if (allDifferent)
		return 0;
	else
		return 10;
}

/*
You have a blue lottery ticket, with ints a, b, and c on it.
This makes three pairs, which we'll call ab, bc, and ac.
Consider the sum of the numbers in each pair.
If any pair sums to exactly 10, the result is 10.
Otherwise if the ab sum is exactly 10 more than either bc or ac sums,
the result is 5. Otherwise the result is 0.

blueTicket(9, 1, 0) == 10
blueTicket(9, 2, 0) == 0
blueTicket(14, 1, 4) == 5
*/
int blueTicket(int a, int b, int c)
{
	int ab = a + b;
	int bc = b + c;
	int ac = a + c;

	if (ab == 10 || bc == 10 || ac == 10)
		return 10;
	else if (ab - bc == 10 || ab - ac == 10)
		return 5;
	else
		return 0;
}

/*
Helper method
*/
vector<int> digits(int n) {
	vector<int> result;
	int num = abs(n);

	if (num == 0)
		result.push_back(0);
	else {
		while (num > 0) {
			result.push_back(num % 10);
			num /= 10;
		}
	}

	std::sort(result.begin(), result.end());
	return result;
}
/*
Given two ints, each in the range 10..99, return true if there is
a digit that appears in both numbers, such as the 2 in 12 and 23.

shareDigit(12, 23) == true
shareDigit(12, 34) == false
shareDigit(12, 44) == false
*/
bool shareDigit(int a, int b)
{
	vector<int> aDigits = digits(a);
	vector<int> bDigits = digits(b);

	std::vector<int> v(aDigits.size() + bDigits.size());
	std::vector<int>::iterator it;

	it = std::set_intersection(aDigits.begin(), aDigits.end(), bDigits.begin(), bDigits.end(), v.begin());
	v.resize(it - v.begin());

	return v.size() > 0;
}

/*
Calculate the sum and the maximum of the passed-in values.
If the sum and maximum have the same number of digits then
return the sum, otherwise return the maximum.

sumLimit(2, 3) == 5
sumLimit(8, 3) == 8
sumLimit(-12, 3) == -9
*/
template <class T>
int sumLimit(std::initializer_list<T> values)
{
	int sum = 0;
	int max = *values.begin();

	for (T val : values){
		sum += val;
		if (val > max)
			max = val;
	}

	int sumDigits = to_string(abs(sum)).length();
	int maxDigits = to_string(abs(max)).length();
	return sumDigits == maxDigits ? sum : max;
}


int main()
{
	cout << ("lastDigit") << endl;
	cout << boolalpha << (lastDigit({23, 19, 13}) == true) << endl;
	cout << boolalpha << (lastDigit({23, 19, 12}) == false) << endl;
	cout << boolalpha << (lastDigit({23, 19, 3}) == true) << endl;

	cout << ("lessBy10") << endl;
	cout << boolalpha << (lessBy10({1, 7, 11}) == true) << endl;
	cout << boolalpha << (lessBy10({1, 7, 10}) == false) << endl;
	cout << boolalpha << (lessBy10({11, 1, 7}) == true) << endl;

	cout << ("withoutDoubles") << endl;
	cout << boolalpha << (withoutDoubles(6, 6, true) == 7) << endl;
	cout << boolalpha << (withoutDoubles(2, 3, true) == 5) << endl;
	cout << boolalpha << (withoutDoubles(3, 3, true) == 7) << endl;
	cout << boolalpha << (withoutDoubles(3, 3, false) == 6) << endl;

	cout << ("maxMod5") << endl;
	cout << boolalpha << (maxMod5(25, 15) == 15) << endl;
	cout << boolalpha << (maxMod5(6, 2) == 6) << endl;
	cout << boolalpha << (maxMod5(3, 3) == 0) << endl;

	cout << ("redTicket") << endl;
	cout << boolalpha << (redTicket({2, 2, 2}) == 10) << endl;
	cout << boolalpha << (redTicket({2, 2, 1}) == 0) << endl;
	cout << boolalpha << (redTicket({0, 0, 0}) == 5) << endl;

	cout << ("greenTicket") << endl;
	cout << boolalpha << (greenTicket({1, 2, 3}) == 0) << endl;
	cout << boolalpha << (greenTicket({2, 2, 2}) == 20) << endl;
	cout << boolalpha << (greenTicket({1, 1, 2}) == 10) << endl;

	cout << ("blueTicket") << endl;
	cout << boolalpha << (blueTicket(14, 1, 4) == 5) << endl;
	cout << boolalpha << (blueTicket(9, 1, 0) == 10) << endl;
	cout << boolalpha << (blueTicket(9, 2, 0) == 0) << endl;

	cout << ("shareDigit") << endl;
	cout << boolalpha << (shareDigit(90, 0) == true) << endl;
	cout << boolalpha << (shareDigit(12, 23) == true) << endl;
	cout << boolalpha << (shareDigit(12, 34) == false) << endl;
	cout << boolalpha << (shareDigit(12, 44) == false) << endl;

	cout << ("sumLimit") << endl;
	cout << boolalpha << (sumLimit({-12, 3}) == -9) << endl;
	cout << boolalpha << (sumLimit({2, 3}) == 5) << endl;
	cout << boolalpha << (sumLimit({8, 3}) == 8) << endl;

    return 0;
}

