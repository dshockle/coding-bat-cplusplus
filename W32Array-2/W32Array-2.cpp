// W32Array-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <locale>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int sumArray(vector<int> arr)
{
	int sum = 0;
	for (unsigned int n : arr)
	{
		sum += n;
	}
	return sum;
}

/*
1. countEvens
Return the number of even ints in the given array.

countEvens({2, 1, 2, 3, 4}) → 3
countEvens({2, 2, 0}) → 3
countEvens({1, 3, 5}) → 0
*/
int countEvens(vector<int> nums)
{
	int count = 0;

	for(int n : nums)
		if (n % 2 == 0)
			count++;

	return count;
}


/*
2. bigDiff
Given an array length 1 or more of ints, return the difference between
the largest and smallest values in the array.

bigDiff({10, 3, 5, 6}) → 7
bigDiff({7, 2, 10, 9}) → 8
bigDiff({2, 10, 7, 2}) → 8
*/
int bigDiff(vector<int> nums)
{
	int max = nums[0];
	int min = nums[0];

	for(int n : nums)
	{
		if (n > max)
			max = n;
		if (n < min)
			min = n;
	}

	return max - min;
}

/*
3. centeredAverage
Return the "centered" average of an array of ints, which we'll say is the mean average
of the values, except ignoring the largest and smallest values in the array. If there
are multiple copies of the smallest value, ignore just one copy, and likewise for the
largest value. Use int division to produce the final average. You may assume that the
array is length 3 or more.

centeredAverage({1, 2, 3, 4, 100}) → 3
centeredAverage({1, 1, 5, 5, 10, 8, 7}) → 5
centeredAverage({-10, -4, -2, -4, -2, 0}) → -3
*/
int centeredAverage(vector<int> nums)
{
	int max = nums[0];
	int min = nums[0];
	int sum = 0;

	for(int n : nums)
	{
		if (n > max)
			max = n;
		if (n < min)
			min = n;
		sum += n;
	}
	return (sum - max - min) / (nums.size() - 2);
}

/*
4. sum13
Return the sum of the numbers in the array, returning 0 for an empty array.
Do not count elements matching the numberToSkip and if alsoSkipTrailing is
true then skip any element immediately following the numberToSkip.

sum13({13, 2, 1, 2, 2, 1}, 13, true) → 6
sum13({13, 13, 2, 1, 1}, 13, true) → 2
sum13({1, 2, 2, 1, 13}, 13, true) → 6
*/
int sum13(vector<int> nums, int numberToSkip, bool alsoSkipTrailing)
{
	int sum = 0;
	for (unsigned int i = 0; i < nums.size(); i++) {
		if (nums[i] != 13 && (i == 0 || nums[i - 1] != 13))
			sum += nums[i];
	}
	return sum;
}

/*
5. sum67
Return the sum of the numbers in the array, except ignore sections of numbers
starting with left and extending through the next right.

sum67({1, 2, 2}, 6, 7) → 5
sum67({1, 2, 2, 6, 99, 99, 7}, 6, 7) → 5
sum67({1, 1, 6, 7, 2}, 6, 7) → 4
*/
int sum67(vector<int> nums, int left, int right)
{
	bool active = true;
	int sum = 0;
	for(int n : nums)
	{
		if (n == left)
			active = false;
		if (active)
			sum += n;
		if (n == right)
			active = true;
	}
	return sum;
}

/*
Given an array of ints, return true if the array contains
left followed immediately by right.

has22({1, 2, 2}, 2, 2) → true
has22({1, 2, 1, 2}, 2, 2) → false
has22({2, 1, 2}, 2, 2) → false
*/
bool has22(vector<int> nums, int left, int right)
{
	for (unsigned int i = 1; i < nums.size(); i++)
		if (nums[i - 1] == left && nums[i] == right)
			return true;

	return false;
}

/*
7. lucky13

Given an array of ints, return true if the array contains no elements
matching first and no elements matching second.

lucky13({0, 2, 4}, 1, 3) → true
lucky13({1, 2, 3}, 1, 3) → false
lucky13({1, 2, 4}, 1, 3) → false
*/
bool lucky13(vector<int> nums, int first, int second)
{
	return find(nums.begin(), nums.end(), first) != nums.end() 
		&& find(nums.begin(), nums.end(), second) != nums.end();
}

/*
8. sum28

Given an array of ints, return true if the sum of all the numberToSum
in the array is exactly equal to target.

sum28({2, 3, 2, 2, 4, 2}, 2, 8) → true
sum28({2, 3, 2, 2, 4, 2, 2}, 2, 8) → false
sum28({1, 2, 3, 4}, 2, 8) → false
*/
bool sum28(vector<int> nums, int numberToSum, int target)
{
	int sum = 0;
	for(int n : nums)
		if (n == numberToSum)
			sum += n;

	return sum == target;
}

/*
9. more14
Given an array of ints, return true if the number of firsts is greater
than the number of seconds

more14({1, 4, 1}, 1, 4) → true
more14({1, 4, 1, 4}, 1, 4) → false
more14({1, 1}, 1, 4) → true
*/
bool more14(vector<int> nums, int first, int second)
{
	int countF = 0;
	int countS = 0;

	for(int n : nums)
	{
		if (n == first)
			countF++;
		else if (n == second)
			countS++;
	}

	return countF > countS;
}

/*
10. fizzArray

Given a number n, create and return a new int array of length n, containing
the numbers 0, 1, 2, ... n-1. The given n may be 0, in which case just return
a length 0 array.

fizzArray(4) → {0, 1, 2, 3}
fizzArray(1) → {0}
fizzArray(10) → {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
*/
vector<int> fizzArray(int n)
{
	vector<int> result;

	for (unsigned int i = 0; i < n; i++)
		result.push_back(i);

	return result;
}

/*
11. only14
Given an array of ints, return true if every element is a 1 or a 4.

only14({1, 4, 1, 4}) → true
only14({1, 4, 2, 4}) → false
only14({1, 1}) → true
*/
bool only14(vector<int> nums) {

	for(int n : nums)
		if (n != 1 && n != 4)
			return false;

	return true;
}

/*
12. fizzArray2
Given a number n, create and return a new string array of length n, containing
the strings "0", "1" "2" .. through n-1. N may be 0, in which case just return
a length 0 array.

fizzArray2(4) → {"0", "1", "2", "3"}
fizzArray2(10) → {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}
fizzArray2(2) → {"0", "1"}
*/
vector<string> fizzArray2(int n)
{
	vector<string> result;
	for (unsigned int i = 0; i < n; i++)
		result.push_back(to_string(i));

	return result;
}

/*
13. no14

Given an array of ints, return true if it contains no firsts and/or no seconds.

no14({1, 2, 3}, 1, 4) → true
no14({1, 2, 3, 4}, 1, 4) → false
no14({2, 3, 4}, 1, 4) → true
*/
bool no14(vector<int> nums, int first, int second)
{
	bool noFirst = true;
	bool noSecond = true;

	for(int n : nums)
	{
		if (n == first)
			noFirst = false;
		if (n == second)
			noSecond = false;
		if (!noFirst && !noSecond)
			break;
	}

	return noFirst || noSecond;
}

/*
14. isEverywhere

We'll say that a value is "everywhere" in an array if for every pair of adjacent
elements in the array, at least one of the pair is that value. Return true if
the given value is everywhere in the array.

isEverywhere({1, 2, 1, 3}, 1) → true
isEverywhere({1, 2, 1, 3}, 2) → false
isEverywhere({1, 2, 1, 3, 4}, 1) → false
*/
bool isEverywhere(vector<int> nums, int val) {
	if (nums.empty())
		return false;
	else
	{
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
			{
				if (i < nums.size() - 1 && nums[i + 1] != val)
					return false;

				if (i > 0 && nums[i - 1] != val)
					return false;
			}
		}
		return true;
	}
}

/*
Helper method
*/
bool hasAdjacent(vector<int> nums, int target)
{
	return false;
}

/*
15. either24

Given an array of ints, return true if the array contains adjacent elements
containing first or adjacent elements containing second but not both.

either24({1, 2, 2}, 2, 4) → true
either24({4, 4, 1}, 2, 4) → true
either24({4, 4, 1, 2, 2}, 2, 4) → false
*/
bool either24(vector<int> nums, int first, int second)
{
	return hasAdjacent(nums, first) != hasAdjacent(nums, second);
}

/*
16. matchUp

Given arrays nums1 and nums2 of the same length, for every element in nums1,
consider the corresponding element in nums2 (at the same index). Return the
count of the number of times that the two elements differ by 2 or less,
but are not equal.

matchUp({1, 2, 3}, {2, 3, 10}) → 2
matchUp({1, 2, 3}, {2, 3, 5}) → 3
matchUp({1, 2, 3}, {2, 3, 3}) → 2
*/
int matchUp(vector<int> nums1, vector<int> nums2)
{
	int count = 0;
	for (unsigned int i = 0; i < min(nums1.size(), nums2.size()); i++) {
		int diff = abs(nums1[i] - nums2[i]);
		if (diff == 1 || diff == 2)
			count++;
	}
	return count;
}

/*
17. has77

Given an array of ints, return true if the array contains two 7's next to
each other, or there are two 7's separated by one element, such as with {7, 1, 7}.

has77({1, 7, 7}) → true
has77({1, 7, 1, 7}) → true
has77({1, 7, 1, 1, 7}) → false
*/
bool has77(vector<int> nums)
{
	for (unsigned int i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] == 7 && nums[i] == 7)
			return true;
		else if (i > 1 && nums[i - 2] == 7 && (nums[i - 1] == 7 || nums[i] == 7))
			return true;
	}

	return false;
}

/*
18. has12

Given an array of ints, return true if first is in the array
with second somewhere later in the array.

has12({1, 2, 1}, 1, 2) → true
has12({3, 1, 2}, 1, 2) → true
has12({3, 2, 1}, 1, 2) → false
*/
bool has12(vector<int> nums, int first, int second)
{
	return std::find(nums.begin(), nums.end(), first) < std::find(nums.begin(), nums.end(), second);
}

/*
19. modThree

Given an array of ints, return true if the array contains
either 3 even or 3 odd values all next to each other.

modThree({2, 1, 3, 5}) → true
modThree({2, 1, 2, 5}) → false
modThree({2, 4, 2, 5}) → true
modThree({1}) → false
modThree({}) → false
*/
bool modThree(vector<int> nums)
{
	if (nums.size() < 3)
		return false;

	for (unsigned int i = 2; i < nums.size(); i++)
		if (nums[i - 2] % 2 == nums[i - 1] % 2 && nums[i - 2] % 2 == nums[i] % 2)
			return true;

	return false;
}

/*
20. haveThree

Given an array of ints, return true if the value 3 appears in the array exactly 3 times,
and no 3's are next to each other.

haveThree({3, 1, 3, 1, 3}) → true
haveThree({3, 1, 3, 3}) → false
haveThree({3, 4, 3, 3, 4}) → false
*/
bool haveThree(vector<int> nums)
{
	int count = 0;

	if (nums.size() < 2)
		return false;

	for (unsigned int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 3)
		{
			count++;

			if (i > 0 && nums[i - 1] == 3)
				return false;
			if (i < nums.size() - 1 && nums[i + 1] == 3)
				return false;
		}
	}

	return count == 3;
}

/*
21. twoTwo
Given an array of ints, return true if every 2 that appears in the array is next to another 2.

twoTwo({4, 2, 2, 3}) → true
twoTwo({2, 2, 4}) → true
twoTwo({2, 2, 4, 2}) → false
*/
bool twoTwo(vector<int> nums)
{
	bool hasLoneTwo = false;

	for (unsigned int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 2)
		{
			hasLoneTwo = true;

			if (i > 0 && nums[i - 1] == 2)
				hasLoneTwo = false;
			else if (i < nums.size() - 1 && nums[i + 1] == 2)
				hasLoneTwo = false;
		}

		if (hasLoneTwo)
			return false;
	}

	return !hasLoneTwo;
}

/*
22. sameEnds
Return true if the group of N numbers at the start and end of the array are the same.
For example, with {5, 6, 45, 99, 13, 5, 6}, the ends are the same for n=0 and n=2,
and false for n=1 and n=3.

sameEnds({5, 6, 45, 99, 13, 5, 6}, 1) → false
sameEnds({5, 6, 45, 99, 13, 5, 6}, 2) → true
sameEnds({5, 6, 45, 99, 13, 5, 6}, 3) → false
*/
bool sameEnds(vector<int> nums, int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		if (nums[i] != nums[i + nums.size() - n])
			return false;
	}

	return true;
}

/*
23. tripleUp
Return true if the array contains, somewhere, three increasing adjacent numbers
like .... 4, 5, 6, ... or 23, 24, 25.

tripleUp({1, 4, 5, 6, 2}) → true
tripleUp({1, 2, 3}) → true
tripleUp({1, 2, 4}) → false
*/
bool tripleUp(vector<int> nums)
{
	for (unsigned int i = 2; i < nums.size(); i++)
		if (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)
			return true;

	return false;
}

/*
24. fizzArray3
Given start and end numbers, return a new array containing
the sequence of integers from start up to but not including end,
so start=5 and end=10 yields {5, 6, 7, 8, 9}.

fizzArray3(5, 10) → {5, 6, 7, 8, 9}
fizzArray3(11, 18) → {11, 12, 13, 14, 15, 16, 17}
fizzArray3(1, 3) → {1, 2}
*/
vector<int> fizzArray3(int start, int end)
{
	vector<int> result;

	for (unsigned int i = 0; i < end - start; i++)
		result.push_back(start + i);

	return result;
}

/*
25. shiftLeft

Return an array that is "left shifted" by one -- so {6, 2, 5, 3} returns {2, 5, 3, 6}.

shiftLeft({6, 2, 5, 3}) → {2, 5, 3, 6}
shiftLeft({1, 2}) → {2, 1}
shiftLeft({1}) → {1}
*/
vector<int> shiftLeft(vector<int> nums)
{
	if (nums.size() < 2)
		return nums;
	else
	{
		nums.push_back(nums[0]);
		vector<int>::iterator it = nums.begin();
		nums.erase(it);
		return nums;
	}
}

/*
26. tenRun

For each multiple of 10 in the given array, change all the values following it
to be that multiple of 10, until encountering another multiple of 10.
So ({2, 10, 3, 4, 20, 5}, 10) yields {2, 10, 10, 10, 20, 20}.

tenRun({2, 10, 3, 4, 20, 5}) → {2, 10, 10, 10, 20, 20}
tenRun({10, 1, 20, 2}) → {10, 10, 20, 20}
tenRun({10, 1, 9, 20}) → {10, 10, 10, 20}
tenRun({1}) → {1}
tenRun({}) → {}

*/
vector<int> tenRun(vector<int> nums)
{
	const int sentinel = -1;
	int replacement = sentinel;

	for (unsigned int i = 0; i < nums.size(); i++) {
		if (nums[i] % 10 == 0)
			replacement = nums[i];
		else if (replacement != sentinel)
			nums[i] = replacement;
	}
	return nums;
}

/*
27. pre4
Given a non-empty array of ints, return a new array containing the elements
from the original array that come before the first 4 in the original array.
The original array will contain at least one 4.

pre4({1, 2, 4, 1}) → {1, 2}
pre4({3, 1, 4}) → {3, 1}
pre4({1, 4, 4}) → {1}
pre4({4, 4}) → {}
*/
vector<int> pre4(vector<int> nums)
{
	vector<int> result;
	for (unsigned int n : nums) {
		if (n == 4)
			break;
		else
			result.push_back(n);
	}
	return result;
}

/*
28. post4

Given a non-empty array of ints, return a new array containing the elements
from the original array that come after the last 4 in the original array.
The original array will contain at least one 4.

post4({2, 4, 1, 2}) → {1, 2}
post4({4, 1, 4, 2}) → {2}
post4({4, 4, 1, 2, 3}) → {1, 2, 3}
post4({4, 4}) → {}
post4({4}) → {}
*/
vector<int> post4(vector<int> nums)
{
	vector<int> result;
	bool found4 = false;

	for (unsigned int n : nums) {
		if (found4)
			result.push_back(n);
		else if (n == 4)
			found4 = true;
	}
	return result;
}

/*
29. notAlone

We'll say that an element in an array is "alone" if there are values before and after it,
and those values are different from it.
Return a version of the given array where every instance of the given value which is alone
is replaced by whichever value to its left or right is larger.

notAlone({1, 2, 3}, 2) → {1, 3, 3}
notAlone({1, 2, 3, 2, 5, 2}, 2) → {1, 3, 3, 5, 5, 2}
notAlone({3, 4}, 3) → {3, 4}
*/
vector<int> notAlone(vector<int> nums, int val)
{
	for (unsigned int i = 1; i < nums.size() - 1; i++)
	{
		if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
			nums[i] = max(nums[i - 1], nums[i + 1]);
	}
	return nums;
}

/*
30. zeroFront

Return an array that contains the exact same numbers as the given array,
but rearranged so that all the zeros are grouped at the start of the array.
The order of the non-zero numbers does not matter.
So {1, 0, 0, 1} becomes {0 ,0, 1, 1}.

zeroFront({1, 0, 0, 1}) → {0, 0, 1, 1}
zeroFront({0, 1, 1, 0, 1}) → {0, 0, 1, 1, 1}
zeroFront({1, 0}) → {0, 1}
zeroFront({}) → {}
*/
vector<int> zeroFront(vector<int> nums)
{
	vector<int> result;
	int rpos = result.size() - 1;

	for(int n : nums)
		if (n != 0)
			result[rpos--] = n;

	return result;
}

/*
31. withoutTen

Return a version of the given array where all the 10's have been removed.
The remaining elements should shift left towards the start of the array as needed,
and the empty spaces a the end of the array should be 0.
So {1, 10, 10, 2} yields {1, 2, 0, 0}.

withoutTen({1, 10, 10, 2}) → {1, 2, 0, 0}
withoutTen({10, 2, 10}) → {2, 0, 0}
withoutTen({1, 99, 10}) → {1, 99, 0}
withoutTen({}) → {}	{}	OK
*/
vector<int> withoutTen(vector<int> nums)
{
	vector<int> result;
	int rpos = 0;

	for(int n : nums)
		if (n != 10)
			result[rpos++] = n;

	return result;
}

/*
32. zeroMax

Return a version of the given array where each zero value in the array is replaced
by the largest odd value to the right of the zero in the array. If there is no odd
value to the right of the zero, leave the zero as a zero.

zeroMax({0, 5, 0, 2}) → {5, 5, 0, 2}
zeroMax({4, 0, 4, 3}) → {4, 3, 4, 3}
zeroMax({0, 1, 0}) → {1, 1, 0}
*/
vector<int> zeroMax(vector<int> nums)
{
	for (unsigned int i = 0; i < nums.size() - 1; i++)
	{
		if (nums[i] == 0)
		{
			int max = 0;

			for (unsigned int j = i + 1; j < nums.size(); j++)
				if (nums[j] % 2 != 0 && nums[j] > max)
					max = nums[j];

			nums[i] = max;
		}
	}

	return nums;
}

/*
33. evenOdd
Return an array that contains the exact same numbers as the given array,
but rearranged so that all the even numbers come before all the odd numbers.
Other than that, the numbers can be in any order.

evenOdd({-1, 0, -1, 0, 0, -1}) → {0, 0, 0, -1, -1, -1}
evenOdd({3, 3, 2}) → {2, 3, 3}
evenOdd({2, 2, 2}) → {2, 2, 2}
*/
vector<int> evenOdd(vector<int> nums)
{
	int evenPos = 0;
	int oddPos = nums.size() - 1;
	int temp = 0;

	for (unsigned int i = 0; i < nums.size(); i++)
		if (evenPos == oddPos)
			break;
		else if (nums[i] % 2 == 0)
		{
			temp = nums[evenPos];
			nums[evenPos] = nums[i];
			nums[i] = temp;
			evenPos++;
		}
		else
		{
			temp = nums[oddPos];
			nums[oddPos] = nums[i];
			nums[i] = temp;
			oddPos--;
		}

	return nums;
}

/*
Helper method
*/
string fb(int num)
{
	if (num % 3 == 0 && num % 5 == 0)
		return "FizzBuzz";
	else if (num % 3 == 0)
		return "Fizz";
	else if (num % 5 == 0)
		return "Buzz";
	else
		return to_string(num);
}

/*
34. fizzBuzz
Consider the series of numbers beginning at start and running up to but not
including end, so for example start=1 and end=5 gives the series 1, 2, 3, 4.
Return a vector<string> array containing the string form of these numbers, except
for multiples of 3, use "Fizz" instead of the number, for multiples of 5 use "Buzz",
and for multiples of both 3 and 5 use "FizzBuzz".

fizzBuzz(1, 6) → {"1", "2", "Fizz", "4", "Buzz"}
fizzBuzz(1, 8) → {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7"}
fizzBuzz(1, 11) → {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz"}
*/
vector<string> fizzBuzz(int start, int end)
{
	vector<string> result;

	for (unsigned int i = start; i < end; i++)
		result[i - start] = fb(i);

	return result;

}


int main()
{
	cout << boolalpha <<("countEvens") << endl;
	cout << boolalpha <<(countEvens(vector<int> { 2, 1, 2, 3, 4}) == 3) << endl;
	cout << boolalpha <<(countEvens(vector<int> { 2, 2, 0}) == 3) << endl;
	cout << boolalpha <<(countEvens(vector<int> { 1, 3, 5}) == 0) << endl;

	cout << boolalpha <<("bigDiff") << endl;
	cout << boolalpha <<(bigDiff(vector<int>{ 10, 3, 5, 6 }) == 7) << endl;
	cout << boolalpha <<(bigDiff(vector<int>{ 7, 2, 10, 9 }) == 8) << endl;
	cout << boolalpha <<(bigDiff(vector<int>{ 2, 10, 7, 2 }) == 8) << endl;

	cout << boolalpha <<("centeredAverage") << endl;
	cout << boolalpha <<(centeredAverage(vector<int>{ 1, 2, 3, 4, 100 }) == 3) << endl;
	cout << boolalpha <<(centeredAverage(vector<int>{ 1, 1, 5, 5, 10, 8, 7 }) == 5) << endl;
	cout << boolalpha <<(centeredAverage(vector<int>{ -10, -4, -2, -4, -2, 0}) == -3) << endl;

	cout << boolalpha <<("sum13") << endl;
	cout << boolalpha <<(sum13(vector<int>{ 1, 13, 2, 2, 2, 1 }, 13, true) == 6) << endl;
	cout << boolalpha <<(sum13(vector<int>{ 13, 13, 2, 1, 1}, 13, true) == 2) << endl;
	cout << boolalpha <<(sum13(vector<int>{ 1, 2, 2, 1, 13}, 13, true) == 6) << endl;

	cout << boolalpha <<("sum67") << endl;
	cout << boolalpha <<(sum67(vector<int>{ 1, 2, 2}, 6, 7) == 5) << endl;
	cout << boolalpha <<(sum67(vector<int>{ 1, 2, 2, 6, 99, 99, 7}, 6, 7) == 5) << endl;
	cout << boolalpha <<(sum67(vector<int>{ 1, 1, 6, 7, 2}, 6, 7) == 4) << endl;

	cout << boolalpha <<("has22") << endl;
	cout << boolalpha <<(has22(vector<int>{ 1, 2, 2}, 2, 2) == true) << endl;
	cout << boolalpha <<(has22(vector<int>{ 1, 2, 1, 2}, 2, 2) == false) << endl;
	cout << boolalpha <<(has22(vector<int>{ 2, 1, 2}, 2, 2) == false) << endl;

	cout << boolalpha <<("lucky13") << endl;
	cout << boolalpha <<(lucky13(vector<int>{ 0, 2, 4}, 1, 3) == true) << endl;
	cout << boolalpha <<(lucky13(vector<int>{ 1, 2, 3}, 1, 3) == false) << endl;
	cout << boolalpha <<(lucky13(vector<int>{ 1, 2, 4}, 1, 3) == false) << endl;

	cout << boolalpha <<("sum28") << endl;
	cout << boolalpha <<(sum28(vector<int>{ 2, 3, 2, 2, 4, 2}, 2, 8) == true) << endl;
	cout << boolalpha <<(sum28(vector<int>{ 2, 3, 2, 2, 4, 2, 2}, 2, 8) == false) << endl;
	cout << boolalpha <<(sum28(vector<int>{ 1, 2, 3, 4}, 2, 8) == false) << endl;

	cout << boolalpha <<("more14") << endl;
	cout << boolalpha <<(more14(vector<int>{ 1, 4, 1}, 1, 4) == true) << endl;
	cout << boolalpha <<(more14(vector<int>{ 1, 4, 1, 4}, 1, 4) == false) << endl;
	cout << boolalpha <<(more14(vector<int>{ 1, 1}, 1, 4) == true) << endl;

	cout << boolalpha <<("fizzArray") << endl;
	cout << boolalpha <<(fizzArray(4) == (vector<int>{ 0, 1, 2, 3 })) << endl;
	cout << boolalpha <<(fizzArray(1) == (vector<int>{ 0 })) << endl;
	cout << boolalpha <<(fizzArray(10) == (vector<int>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9})) << endl;

	cout << boolalpha <<("only14") << endl;
	cout << boolalpha <<(only14(vector<int>{ 1, 4, 1, 4}) == true) << endl;
	cout << boolalpha <<(only14(vector<int>{ 1, 4, 2, 4}) == false) << endl;
	cout << boolalpha <<(only14(vector<int>{ 1, 1}) == true) << endl;

	cout << boolalpha <<("fizzArray2") << endl;
	cout << boolalpha <<(fizzArray2(4) == (vector<string>{ "0", "1", "2", "3" })) << endl;
	cout << boolalpha <<(fizzArray2(10) == (vector<string>{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" })) << endl;
	cout << boolalpha <<(fizzArray2(2) == (vector<string>{ "0", "1" })) << endl;

	cout << boolalpha <<("no14") << endl;
	cout << boolalpha <<(no14(vector<int>{ 1, 2, 3 }, 1, 4) == true) << endl;
	cout << boolalpha <<(no14(vector<int>{ 1, 2, 3, 4}, 1, 4) == false) << endl;
	cout << boolalpha <<(no14(vector<int>{ 2, 3, 4}, 1, 4) == true) << endl;

	cout << boolalpha <<("isEverywhere") << endl;
	cout << boolalpha <<(isEverywhere(vector<int>{ 1, 2, 1, 3}, 1) == true) << endl;
	cout << boolalpha <<(isEverywhere(vector<int>{ 1, 2, 1, 3}, 2) == false) << endl;
	cout << boolalpha <<(isEverywhere(vector<int>{ 1, 2, 1, 3, 4}, 1) == false) << endl;

	cout << boolalpha <<("either24") << endl;
	cout << boolalpha <<(either24(vector<int>{ 1, 2, 2}, 2, 4) == true) << endl;
	cout << boolalpha <<(either24(vector<int>{ 4, 4, 1}, 2, 4) == true) << endl;
	cout << boolalpha <<(either24(vector<int>{ 4, 4, 1, 2, 2}, 2, 4) == false) << endl;

	cout << boolalpha <<("matchUp") << endl;
	cout << boolalpha <<(matchUp(vector<int>{ 1, 2, 3 }, vector<int>{ 2, 3, 10 }) == 2) << endl;
	cout << boolalpha <<(matchUp(vector<int>{ 1, 2, 3}, vector<int>{ 2, 3, 5}) == 3) << endl;
	cout << boolalpha <<(matchUp(vector<int>{ 1, 2, 3}, vector<int>{ 2, 3, 3}) == 2) << endl;

	cout << boolalpha <<("has77") << endl;
	cout << boolalpha <<(has77(vector<int>{ 1, 7, 7 }) == true) << endl;
	cout << boolalpha <<(has77(vector<int>{ 1, 7, 1, 7 }) == true) << endl;
	cout << boolalpha <<(has77(vector<int>{ 1, 7, 1, 1, 7 }) == false) << endl;

	cout << boolalpha <<("modThree") << endl;
	cout << boolalpha <<(modThree(vector<int>{ 2, 1, 3, 5}) == true) << endl;
	cout << boolalpha <<(modThree(vector<int>{ 2, 1, 2, 5}) == false) << endl;
	cout << boolalpha <<(modThree(vector<int>{ 2, 4, 2, 5}) == true) << endl;
	cout << boolalpha <<(modThree(vector<int>{ 1 }) == false) << endl;
	cout << boolalpha <<(modThree(vector<int>{}) == false) << endl;

	cout << boolalpha <<("haveThree") << endl;
	cout << boolalpha <<(haveThree(vector<int>{ 3, 1, 3, 1, 3 }) == true) << endl;
	cout << boolalpha <<(haveThree(vector<int>{ 3, 1, 3, 3}) == false) << endl;
	cout << boolalpha <<(haveThree(vector<int>{ 3, 4, 3, 3, 4}) == false) << endl;

	cout << boolalpha <<("has12") << endl;
	cout << boolalpha <<(has12(vector<int>{ 1, 2, 1}, 1, 2) == true) << endl;
	cout << boolalpha <<(has12(vector<int>{ 3, 1, 2}, 1, 2) == true) << endl;
	cout << boolalpha <<(has12(vector<int>{ 3, 2, 1}, 1, 2) == false) << endl;

	cout << boolalpha <<("twoTwo") << endl;
	cout << boolalpha <<(twoTwo(vector<int>{ 4, 2, 2}) == true) << endl;
	cout << boolalpha <<(twoTwo(vector<int>{ 2, 2, 4}) == true) << endl;
	cout << boolalpha <<(twoTwo(vector<int>{ 2, 4, 2}) == false) << endl;

	cout << boolalpha <<("sameEnds") << endl;
	cout << boolalpha <<(sameEnds(vector<int>{ 5, 6, 45, 99, 13, 5, 6}, 1) == false) << endl;
	cout << boolalpha <<(sameEnds(vector<int>{ 5, 6, 45, 99, 13, 5, 6}, 2) == true) << endl;
	cout << boolalpha <<(sameEnds(vector<int>{ 5, 6, 45, 99, 13, 5, 6}, 3) == false) << endl;

	cout << boolalpha <<("tripleUp") << endl;
	cout << boolalpha <<(tripleUp(vector<int>{ 1, 4, 5, 6, 2}) == true) << endl;
	cout << boolalpha <<(tripleUp(vector<int>{ 1, 2, 3}) == true) << endl;
	cout << boolalpha <<(tripleUp(vector<int>{ 1, 2, 4}) == false) << endl;

	cout << boolalpha <<("fizzArray3") << endl;
	cout << boolalpha <<(fizzArray3(5, 10) == (vector<int>{ 5, 6, 7, 8, 9 })) << endl;
	cout << boolalpha <<(fizzArray3(11, 18) == (vector<int>{ 11, 12, 13, 14, 15, 16, 17})) << endl;
	cout << boolalpha <<(fizzArray3(1, 3) == (vector<int>{ 1, 2})) << endl;

	cout << boolalpha <<("shiftLeft") << endl;
	cout << boolalpha <<(shiftLeft(vector<int>{ 6, 2, 5, 3 }) == (vector<int>{ 2, 5, 3, 6 })) << endl;
	cout << boolalpha <<(shiftLeft(vector<int>{ 1, 2}) == (vector<int>{ 2, 1})) << endl;
	cout << boolalpha <<(shiftLeft(vector<int>{ 1 }) == (vector<int>{ 1 })) << endl;

	cout << boolalpha <<("tenRun") << endl;
	cout << boolalpha <<(tenRun(vector<int>{ 10, 1, 9, 20 }) == (vector<int>{ 10, 10, 10, 20 })) << endl;
	cout << boolalpha <<(tenRun(vector<int>{ 1 }) == (vector<int>{ 1 })) << endl;
	cout << boolalpha <<(tenRun(vector<int>{}) == (vector<int>{})) << endl;

	cout << boolalpha <<("pre4") << endl;
	cout << boolalpha <<(pre4(vector<int>{ 1, 2, 4, 1 }) == (vector<int>{ 1, 2 })) << endl;
	cout << boolalpha <<(pre4(vector<int>{ 3, 1, 4 }) == (vector<int>{ 3, 1 })) << endl;
	cout << boolalpha <<(pre4(vector<int>{ 1, 4, 4 }) == (vector<int>{ 1 })) << endl;
	cout << boolalpha <<(pre4(vector<int>{ 4, 4 }) == (vector<int>{})) << endl;

	cout << boolalpha <<("post4") << endl;
	cout << boolalpha <<(post4(vector<int>{ 2, 4, 1, 2}) == (vector<int>{ 1, 2})) << endl;
	cout << boolalpha <<(post4(vector<int>{ 4, 1, 4, 2}) == (vector<int>{ 2 })) << endl;
	cout << boolalpha <<(post4(vector<int>{ 4, 4, 1, 2, 3}) == (vector<int>{ 1, 2, 3})) << endl;
	cout << boolalpha <<(post4(vector<int>{ 4, 4}) == (vector<int>{})) << endl;

	cout << boolalpha <<("zeroFront") << endl;
	cout << boolalpha <<(zeroFront(vector<int>{ 1, 0, 0, 1}) == (vector<int>{ 0, 0, 1, 1})) << endl;
	cout << boolalpha <<(zeroFront(vector<int>{ 0, 1, 1, 0, 1}) == (vector<int>{ 0, 0, 1, 1, 1})) << endl;
	cout << boolalpha <<(zeroFront(vector<int>{ 1, 0}) == (vector<int>{ 0, 1})) << endl;
	cout << boolalpha <<(zeroFront(vector<int>{}) == (vector<int>{})) << endl;

	cout << boolalpha <<("withoutTen") << endl;
	cout << boolalpha <<(withoutTen(vector<int>{ 1, 10, 10, 2}) == (vector<int>{ 1, 2, 0, 0})) << endl;
	cout << boolalpha <<(withoutTen(vector<int>{ 10, 2, 10}) == (vector<int>{ 2, 0, 0})) << endl;
	cout << boolalpha <<(withoutTen(vector<int>{ 1, 99, 10}) == (vector<int>{ 1, 99, 0})) << endl;
	cout << boolalpha <<(withoutTen(vector<int>{}) == (vector<int>{})) << endl;

	cout << boolalpha <<("zeroMax") << endl;
	cout << boolalpha <<(zeroMax(vector<int>{ 0, 5, 0, 2 }) == (vector<int>{ 5, 5, 0, 2})) << endl;
	cout << boolalpha <<(zeroMax(vector<int>{ 4, 0, 4, 3}) == (vector<int>{ 4, 3, 4, 3})) << endl;
	cout << boolalpha <<(zeroMax(vector<int>{ 0, 1, 0}) == (vector<int>{ 1, 1, 0})) << endl;

	cout << boolalpha <<("evenOdd") << endl;
	cout << boolalpha <<(evenOdd(vector<int>{ -1, 0, -1, 0, 0, -1 }) == (vector<int>{ 0, 0, 0, -1, -1, -1 })) << endl;
	cout << boolalpha <<(evenOdd(vector<int>{ 3, 3, 2 }) == (vector<int>{ 2, 3, 3 })) << endl;
	cout << boolalpha <<(evenOdd(vector<int>{ 2, 2, 2 }) == (vector<int>{ 2, 2, 2 })) << endl;

	cout << boolalpha <<("fizzBuzz") << endl;
	cout << boolalpha <<(fizzBuzz(1, 6) == (vector<string>{ "1", "2", "Fizz", "4", "Buzz" })) << endl;
	cout << boolalpha <<(fizzBuzz(1, 8) == (vector<string>{ "1", "2", "Fizz", "4", "Buzz", "Fizz", "7" })) << endl;
	cout << boolalpha <<(fizzBuzz(1, 11) == (vector<string>{ "1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz" })) << endl;

	return 0;
}

