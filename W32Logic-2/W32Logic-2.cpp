// W32Logic-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <locale>
#include <map>
#include <regex>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/*
We want to make a row of bricks that is goal inches long.
We have a number of small bricks (1 inch each) and big bricks (5 inches each).
Return true if it is possible to make the goal by choosing from the given bricks.
This is a little harder than it looks and can be done without any loops.

makeBricks(3, 1, 8) → true
makeBricks(3, 1, 9) → false
makeBricks(3, 2, 10) → true
*/
bool makeBricks(int small, int big, int goal)
{
	return (5 * big) + small >= goal && small >= (goal % 5);
}

/*
Given integer values, return their sum. If one value is the
same as another, it does not count towards the sum.

loneSum(1, 2, 3) → 6
loneSum(3, 2, 3) → 2
loneSum(3, 3, 3) → 0
*/
int loneSum(vector<int> values)
{
	map<int, int> m;
	int sum = 0;

	for (unsigned int v : values) {
		if (m.find(v) != m.end())
			m[v]++;
		else 
			m.insert(std::pair<char, int>(v, 1));
	}

	for (auto& kv : m)
		if (kv.second == 1)
			sum += kv.first;

	return sum;
}

/*
Given 3 int values, a b c, return their sum.
However, if one of the values is 13 then it does not count towards the sum
and values to its right do not count. So for example, if b is 13, then both
b and c do not count.

luckySum(1, 2, 3) → 6
luckySum(1, 2, 13) → 3
luckySum(1, 13, 3) → 1
*/
int luckySum(vector<int> values)
{
	int sum = 0;
	for (unsigned int v : values)
	{
		if (v == 13)
			break;
		else
			sum += v;
	}
	return sum;
}

//********************************************************************************************************************************
/*
Helper method
*/
int fixTeen(int n)
{
	if ((n >= 13 && n <= 14) || (n >= 17 && n <= 19))
		return 0;
	else
		return n;
}

/*
Given 3 int values, a b c, return their sum.
However, if any of the values is a teen -- in the
range 13..19 inclusive -- then that value counts as 0,
except 15 and 16 do not count as a teens. Write a
separate helper method "public int fixTeen(int n) {

noTeenSum(1, 2, 3) → 6
noTeenSum(2, 13, 1) → 3
noTeenSum(2, 1, 14) → 3
*/
int noTeenSum(vector<int> values)
{
	int sum = 0;
	for (unsigned int v : values)
	{
		sum += fixTeen(v);
	}
	return sum;
}


/*
Helper method
*/
int round10(int num)
{
	if (num % 10 >= 5)
		return (num / 10) * 10 + 10;
	else
		return (num / 10) * 10;
}

/*
For this problem, we'll round an int value up to the next multiple of 10
if its rightmost digit is 5 or more, so 15 rounds up to 20. Alternately,
round down to the previous multiple of 10 if its rightmost digit is less
than 5, so 12 rounds down to 10. Given 3 ints, a b c, return the sum of
their rounded values. To avoid code repetition, write a separate helper
"public int round10(int num) {" and call it 3 times.

roundSum(16, 17, 18) → 60
roundSum(12, 13, 14) → 30
roundSum(6, 4, 4) → 10
*/
int roundSum(vector<int> values)
{
	int sum = 0;
	
	for (unsigned int v : values)
		sum += round10(v);

	return sum;
}

/*
Given three ints, a b c, return true if one of b or c is "close"
(differing from a by at most 1), while the other is "far",
differing from both other values by 2 or more.

closeFar(1, 2, 10) → true
closeFar(1, 2, 3) → false
closeFar(4, 1, 3) → true
*/
bool closeFar(int a, vector<int> values)
{
	vector<bool> closeToA(values.size());
	vector<bool> farFromOthers(values.size());

	for (unsigned int i = 0; i < values.size(); i++)
	{
		closeToA[i] = abs(a - values[i]) <= 1;

		int min = INT32_MAX;

		for (unsigned int j = 0; j < values.size(); j++)
		{
			if (i != j)
				min = std::min(min, abs(values[j] - values[i]));
		}

		farFromOthers[i] = min >= 2;
	}

	for (unsigned int i = 0; i < values.size(); i++)
	{
		if (closeToA[i])
		{
			bool allFar = true;
			for (unsigned int j = 0; j < values.size(); j++)
			{
				if (i != j)
				{
					if (!farFromOthers[j] || closeToA[j])
					{
						allFar = false;
						break;
					}
				}
			}
			if (allFar)
				return true;
		}
	}
	return false;
}

/*
Given three ints, a b c, return true if one of b or c is "close"
(differing from a by at most 1), while the other is "far",
differing from both other values by 2 or more.

closeFar(1, 2, 10) → true
closeFar(1, 2, 3) → false
closeFar(4, 1, 3) → true
*/
bool closeFar2(vector<int> values)
{
	bool match = false;

	for (unsigned int i = 0; i < values.size(); i++)
	{
		for (unsigned int j = 0; j < values.size(); j++)
		{
			if (i != j && abs(values[i] - values[j]) <= 1)
			{
				match = true;

				for (unsigned int k = 0; k < values.size(); k++)
				{
					if (k != i && k != j)
					{
						if (abs(values[i] - values[k]) <= 1 || abs(values[j] - values[k]) <= 1)
						{
							match = false;
							break;
						}
					}
				}

				if (match)
					return match;
			}
		}
	}
	return match;
}

/*

Given 2 int values greater than 0, return whichever value is
nearest to 21 without going over. Return 0 if they both go over.

blackjack(21, 19, 21, 21) → 21
blackjack(21, 21, 19) → 21
blackjack(21, 19, 22) → 19
*/
int blackjack(int limit, vector<int> values)
{
	int max = 0;
	for(int v : values)
	{
		if (v <= limit)
			if (v > max)
				max = v;
	}

	return max;
}

/*
Given three ints, a b c, one of them is small, one is medium and one is large.
Return true if the three values are evenly spaced, so the difference between
small and medium is the same as the difference between medium and large.

evenlySpaced(2, 4, 6) → true
evenlySpaced(4, 6, 2) → true
evenlySpaced(4, 6, 3) → false
*/
bool evenlySpaced(vector<int> values)
{
	sort(values.begin(), values.end());
	
	int space = values[1] - values[0];

	for (unsigned int i = 1; i < values.size(); i++)
		if (values[i] - values[i - 1] != space)
			return false;

	return true;
}

/*
We want make a package of goal kilos of chocolate.
We have small bars (1 kilo each) and big bars (5 kilos each).
Return the number of small bars to use, assuming we always
use big bars before small bars. Return -1 if it can't be done.

makeChocolate(4, 1, 9) → 4
makeChocolate(4, 1, 10) → -1
makeChocolate(4, 1, 7) → 2
*/
int makeChocolate(int small, int big, int goal)
{
	if (5 * big + small >= goal && goal % 5 <= small)
		return goal % 5;
	else
		return -1;
}



int main()
{



	return 0;
}

