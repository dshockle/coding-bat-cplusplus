// W32Array-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <locale>
#include <numeric>
#include <regex>
#include <set>
#include <string>
#include <vector>

using namespace std;

/*
Consider the leftmost and righmost appearances of some value in an array.
We'll say that the "span" is the number of elements between the two inclusive.
A single value has a span of 1. Returns the largest span found in the given array.

maxSpan({1, 2, 1, 1, 3}) ? 4
maxSpan({1, 4, 2, 1, 4, 1, 4}) ? 6
maxSpan({1, 4, 2, 1, 4, 4, 4}) ? 6
*/
int maxSpan(vector<int> nums)
{
	int max = 0;
	int left = 0;
	int right = 0;
	set<int> distinct(nums.begin(), nums.end());
	
	for(int val : distinct)
	{
		vector<int>::iterator it;
		it = std::find(nums.begin(), nums.end(), val);

		if (it != nums.end())
			left = (it - nums.begin());

		vector<int>::reverse_iterator rit;
		rit = std::find(nums.rbegin(), nums.rend(), val);

		if (rit != nums.rbegin())
			right = (rit - nums.rend());

		int span = 1 + right - left;

		if (span > max)
			max = span;
	}
	return max;
}

/*
Return an array that contains exactly the same numbers as the given array,
but rearranged so that every 3 is immediately followed by a 4.
Do not move the 3's, but every other number may move.
The array contains the same number of 3's and 4's, every 3 has a number
after it that is not a 3 or 4, and a 3 appears in the array before any 4.

fix34({1, 3, 1, 4}) ? {1, 3, 4, 1}
fix34({1, 3, 1, 4, 4, 3, 1}) ? {1, 3, 4, 1, 1, 3, 4}
fix34({3, 2, 2, 4}) ? {3, 4, 2, 2}
*/
vector<int> fix34(vector<int> nums)
{
	for (unsigned int i = 0; i < nums.size() - 1; i++)
	{
		if (nums[i] == 3 && nums[i + 1] != 4)
		{
			for (unsigned int j = 0; j < nums.size(); j++)
			{
				if (nums[j] == 4 && (j == 0 || nums[j - 1] != 3))
				{
					nums[j] = nums[i + 1];
					nums[i + 1] = 4;
				}
			}
		}
	}
	return nums;
}

/*
(This is a slightly harder version of the fix34 problem.)
Return an array that contains exactly the same numbers as the given array,
but rearranged so that every 4 is immediately followed by a 5.
Do not move the 4's, but every other number may move.
The array contains the same number of 4's and 5's, and every 4 has a number
after it that is not a 4. In this version, 5's may appear anywhere in the
original array.

fix45({5, 4, 9, 4, 9, 5}) ? {9, 4, 5, 4, 5, 9}
fix45({1, 4, 1, 5}) ? {1, 4, 5, 1}
fix45({1, 4, 1, 5, 5, 4, 1}) ? {1, 4, 5, 1, 1, 4, 5}
*/
vector<int> fix45(vector<int> nums)
{
	for (unsigned int i = 0; i < nums.size() - 1; i++)
	{
		if (nums[i] == 4 && nums[i + 1] != 5)
		{
			for (unsigned int j = 0; j < nums.size(); j++)
			{
				if (nums[j] == 5 && (j == 0 || nums[j - 1] != 4))
				{
					nums[j] = nums[i + 1];
					nums[i + 1] = 5;
				}
			}
		}
	}
	return nums;
}

/*
Given a non-empty array, return true if there is a place to split the array
so that the sum of the numbers on one side is equal to the sum of the numbers
on the other side.

canBalance({1, 1, 1, 2, 1}) == true
canBalance({2, 1, 1, 2, 1}) == false
canBalance({10, 10}) == true
*/
bool canBalance(vector<int> nums)
{
	if (nums.size() < 2)
		return false;

	int sum_of_elems = std::accumulate(nums.begin(), nums.end(), 0);
	int pos = 0;
	int left = nums[pos];
	int right = sum_of_elems - nums[pos];

	while (left < right && pos < nums.size())
	{
		pos++;
		left += nums[pos];
		right -= nums[pos];
	}

	return left == right;
}

/*
Given a non-empty array, return true if there is a place to split the array
so that the sum of the numbers on one side is equal to the sum of the numbers
on the other side.

canBalance({1, 1, 1, 2, 1}) == true
canBalance({2, 1, 1, 2, 1}) == false
canBalance({10, 10}) == true
*/
bool canBalance2(vector<int> nums)
{
	if (nums.size() < 2)
		return false;

	int left = 0; int right = 0; int pos = 0;
	bool moveToLeft = false;
	int mid = nums.size() / 2 + 1 - nums.size() % 2;

	for (unsigned int i = 0; i < nums.size(); i++)
	{
		if (i <= mid)
			left += nums[i];
		else
			right += nums[i];
	}

	if (left > right)
		moveToLeft = true;

	while (pos < mid && left != right)
	{
		pos++;

		if (moveToLeft)
		{
			left -= nums[mid - pos];
			right += nums[mid - pos];
			if (left < right) break;
		}
		else
		{
			left += nums[mid + pos];
			right -= nums[mid + pos];
			if (left > right) break;
		}
	}

	return left == right;
}

/*
Given two arrays of ints sorted in increasing order, outer and inner,
return true if all of the numbers in inner appear in outer. The best
solution makes only a single "linear" pass of both arrays, taking
advantage of the fact that both arrays are already in sorted order.

linearIn({1, 2, 4, 6}, {2, 4}) == true
linearIn({1, 2, 4, 6}, {2, 3, 4}) == false
linearIn({1, 2, 4, 4, 6}, {2, 4}) == true
*/
bool linearIn(vector<int> outer, vector<int> inner)
{
	std::vector<int> shared;
	set_intersection(inner.begin(), inner.end(), outer.begin(), outer.end(), back_inserter(shared));
	return shared.size() == inner.size();
}

/*
Given two arrays of ints sorted in increasing order, outer and inner,
return true if all of the numbers in inner appear in outer. The best
solution makes only a single "linear" pass of both arrays, taking
advantage of the fact that both arrays are already in sorted order.

linearIn({1, 2, 4, 6}, {2, 4}) == true
linearIn({1, 2, 4, 6}, {2, 3, 4}) == false
linearIn({1, 2, 4, 4, 6}, {2, 4}) == true
*/
bool linearIn2(vector<int> outer, vector<int> inner)
{
	if (inner.size() == 0 || outer.size() == 0)
		return false;

	int oPos = 0; int iPos = 0;

	while (oPos < outer.size() && iPos < inner.size())
	{
		if (inner[iPos] < outer[oPos])
			return false;
		else if (inner[iPos] == outer[oPos])
			iPos++;

		oPos++;
	}

	return true;
}

/*
Given n >= 0, create an array length n * n with the following pattern,
shown here for n=3 : {0, 0, 1,    0, 2, 1,    3, 2, 1}
(spaces added to show the 3 groups).

squareUp(3) ? {0, 0, 1, 0, 2, 1, 3, 2, 1}
squareUp(2) ? {0, 1, 2, 1}
squareUp(4) ? {0, 0, 0, 1, 0, 0, 2, 1, 0, 3, 2, 1, 4, 3, 2, 1}
*/
vector<int> squareUp(int n)
{
	vector<int> result(n * n, 0);
	int limit = n;
	int pos = result.size() - 1;
	int val = 1;

	while (pos >= 0)
	{
		result[pos] = val <= limit ? val : 0;
		pos--;
		val++;

		if (val > n)
		{
			val = 1;
			limit--;
		}
	}
	return result;
}

/*
Given n >= 0, create an array with the pattern
{1,    1, 2,    1, 2, 3,   ... 1, 2, 3 .. n} (spaces added to show the grouping).
Note that the length of the array will be n*(n + 1)/2.

seriesUp(3) ? {1, 1, 2, 1, 2, 3}
seriesUp(4) ? {1, 1, 2, 1, 2, 3, 1, 2, 3, 4}
seriesUp(2) ? {1, 1, 2}
*/

vector<int> seriesUp(int n)
{
	vector<int> result;
	int limit = 1;
	int val = 1;

	for (unsigned int i = 0; i < result.size(); i++)
	{
		result.push_back(val++);
		if (val > limit)
		{
			val = 1;
			limit++;
		}
	}

	return result;
}

/*
We'll say that a "mirror" section in an array is a group of contiguous elements
such that somewhere in the array, the same group appears in reverse order.
For example, the largest mirror section in {1, 2, 3, 8, 9, 3, 2, 1}
is length 3 (the {1, 2, 3} part). Return the size of the largest mirror section
found in the given array.

maxMirror({1, 2, 3, 8, 9, 3, 2, 1}) ? 3
maxMirror({1, 2, 1, 4}) ? 3
maxMirror({7, 1, 2, 9, 7, 2, 1}) ? 2
*/
int maxMirror(vector<int> nums)
{
	int max = 0;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		for (unsigned int j = nums.size() - 1; j > i; j--)
		{
			if (nums[i] == nums[j])
			{
				int left = i;
				int right = j;
				int span = 0;

				while (left < nums.size() && right > 0 && nums[left] == nums[right])
				{
					span++;
					left++;
					right--;
				}

				if (left >= right)
					span++;

				if (span > max)
					max = span;
			}
		}
	}
	return max;
}

/*
Say that a "clump" in an array is a series of 2 or more adjacent elements of the same value.
Return the number of clumps in the given array.

countClumps({1, 2, 2, 3, 4, 4}) ? 2
countClumps({1, 1, 2, 1, 1}) ? 2
countClumps({1, 1, 1, 1, 1}) ? 1
*/
int countClumps(vector<int> nums)
{
	int count = 0;
	bool inClump = false;

	for (unsigned int i = 1; i < nums.size(); i++)
	{
		if (nums[i] == nums[i - 1])
		{
			if (!inClump)
			{
				count++;
				inClump = true;
			}
		}
		else
			inClump = false;
	}
	return count;
}


int main()
{
	cout << boolalpha << ("maxSpan") << endl;
	cout << boolalpha << (maxSpan(vector<int> { 1, 2, 1, 1, 3 }) == 4) << endl;
	cout << boolalpha << (maxSpan(vector<int> { 1, 4, 2, 1, 4, 1, 4}) == 6) << endl;
	cout << boolalpha << (maxSpan(vector<int> { 1, 4, 2, 1, 4, 4, 4}) == 6) << endl;

	cout << boolalpha << ("fix34") << endl;
	cout << boolalpha << (fix34(vector<int> { 1, 3, 1, 4 }) == (vector<int> { 1, 3, 4, 1 })) << endl;
	cout << boolalpha << (fix34(vector<int> { 1, 3, 1, 4, 4, 3, 1}) == (vector<int> { 1, 3, 4, 1, 1, 3, 4})) << endl;
	cout << boolalpha << (fix34(vector<int> { 3, 2, 2, 4}) == (vector<int> { 3, 4, 2, 2})) << endl;

	cout << boolalpha << ("fix45") << endl;
	cout << boolalpha << (fix45(vector<int> { 5, 4, 9, 4, 9, 5}) == (vector<int> { 9, 4, 5, 4, 5, 9})) << endl;
	cout << boolalpha << (fix45(vector<int> { 1, 4, 1, 5}) == (vector<int> { 1, 4, 5, 1})) << endl;
	cout << boolalpha << (fix45(vector<int> { 1, 4, 1, 5, 5, 4, 1}) == (vector<int> { 1, 4, 5, 1, 1, 4, 5})) << endl;

	cout << boolalpha << ("canBalance") << endl;
	cout << boolalpha << (canBalance(vector<int> { 1, 1, 1, 2, 1}) == true) << endl;
	cout << boolalpha << (canBalance(vector<int> { 2, 1, 1, 2, 1}) == false) << endl;
	cout << boolalpha << (canBalance(vector<int> { 10, 10}) == true) << endl;

	cout << boolalpha << ("canBalance2") << endl;
	cout << boolalpha << (canBalance2(vector<int> { 1, 1, 1, 2, 1 }) == true) << endl;
	cout << boolalpha << (canBalance2(vector<int> { 2, 1, 1, 2, 1 }) == false) << endl;
	cout << boolalpha << (canBalance2(vector<int> { 10, 10 }) == true) << endl;

	cout << boolalpha << ("linearIn") << endl;
	cout << boolalpha << (linearIn(vector<int> { 1, 2, 4, 6}, vector<int> { 2, 4}) == true) << endl;
	cout << boolalpha << (linearIn(vector<int> { 1, 2, 4, 6}, vector<int> { 2, 3, 4}) == false) << endl;
	cout << boolalpha << (linearIn(vector<int> { 1, 2, 4, 4, 6}, vector<int> { 2, 4}) == true) << endl;

	cout << boolalpha << ("linearIn2") << endl;
	cout << boolalpha << (linearIn2(vector<int> { 1, 2, 4, 6 }, vector<int> { 2, 4 }) == true) << endl;
	cout << boolalpha << (linearIn2(vector<int> { 1, 2, 4, 6 }, vector<int> { 2, 3, 4 }) == false) << endl;
	cout << boolalpha << (linearIn2(vector<int> { 1, 2, 4, 4, 6 }, vector<int> { 2, 4 }) == true) << endl;

	cout << boolalpha << ("squareUp") << endl;
	cout << boolalpha << (squareUp(3) == (vector<int> { 0, 0, 1, 0, 2, 1, 3, 2, 1 })) << endl;
	cout << boolalpha << (squareUp(2) == (vector<int> { 0, 1, 2, 1})) << endl;
	cout << boolalpha << (squareUp(4) == (vector<int> { 0, 0, 0, 1, 0, 0, 2, 1, 0, 3, 2, 1, 4, 3, 2, 1})) << endl;

	cout << boolalpha << ("seriesUp") << endl;
	cout << boolalpha << (seriesUp(3) == (vector<int> { 1, 1, 2, 1, 2, 3})) << endl;
	cout << boolalpha << (seriesUp(4) == (vector<int> { 1, 1, 2, 1, 2, 3, 1, 2, 3, 4})) << endl;
	cout << boolalpha << (seriesUp(2) == (vector<int> { 1, 1, 2})) << endl;

	cout << boolalpha << ("maxMirror") << endl;
	cout << boolalpha << (maxMirror(vector<int> { 1, 2, 3, 8, 9, 3, 2, 1 }) == 3) << endl;
	cout << boolalpha << (maxMirror(vector<int> { 1, 2, 1, 4}) == 3) << endl;
	cout << boolalpha << (maxMirror(vector<int> { 7, 1, 2, 9, 7, 2, 1}) == 2) << endl;
	cout << boolalpha << (maxMirror(vector<int> { 1, 2, 7, 2, 1, 3, 1 }) == 5) << endl;

	cout << boolalpha << ("countClumps") << endl;
	cout << boolalpha << (countClumps(vector<int> { 1, 2, 2, 3, 4, 4 }) == 2) << endl;
	cout << boolalpha << (countClumps(vector<int> { 1, 1, 2, 1, 1}) == 2) << endl;
	cout << boolalpha << (countClumps(vector<int> { 1, 1, 1, 1, 1}) == 1) << endl;

	// 
	return 0;
}

