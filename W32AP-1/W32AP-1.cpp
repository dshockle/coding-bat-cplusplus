// W32AP-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <locale>
#include <regex>
#include <string>
#include <tchar.h>
#include <vector>

using namespace std;

/*
Helper method
*/
template <typename V>

void printVector(vector<V> vec)
{
	for(V s : vec)
		cout << s << ' ';

	cout << '\n';
}



/*
Given an array of scores, return true if each score is equal or greater than the one before.
The array will be length() 2 or more.

scoresIncreasing({1, 3, 4}) == true
scoresIncreasing({1, 3, 2}) == false
scoresIncreasing({1, 1, 4}) == true
*/

bool scoresIncreasing(vector<int> scores)
{
	int len = scores.size();

	for (unsigned int i = 1; i < len; i++)
		if (scores[i] < scores[i - 1])
			return false;
	return true;
}

/*
Given an array of scores, return true if there are scores of 100 next to each other in the array.
The array length() will be at least 2.

scores100({1, 100, 100}) == true
scores100({1, 100, 99, 100}) == false
scores100({100, 1, 100, 100}) == true
*/
bool scores100(vector<int> scores)
{
	int len = scores.size();

	for (unsigned int i = 1; i < len; i++) {
		if (scores[i] == 100 && scores[i - 1] == 100) {
			return true;
		}
	}
			
	return false;
}


/*
Given a sorted array, return true if the array contains 3 adjacent scores
that differ from each other by at most 2, such as with {3, 4, 5} or {3, 5, 5}.

scoresClump({3, 4, 5}) == true
scoresClump({3, 4, 6}) == false
scoresClump({1, 3, 5, 5}) == true
*/
bool scoresClump(vector<int> scores)
{
	int len = scores.size();

	for (unsigned int i = 1; i < len - 1; i++) {
		if (abs(scores[i - 1] - scores[i + 1]) <= 2) {
			return true;
		}
	}
			
	return false;
}

/*
Given an array of scores, compute the int average of the first half and the second half, and return
whichever is larger. We'll say that the second half begins at index length()/2. The array length() will
be at least 2. Normally you would compute averages with doubles, but here we use ints so the expected
results are exact.

scoresAverage({2, 2, 4, 4}) == 4
scoresAverage({4, 4, 4, 2, 2, 2}) == 4
scoresAverage({3, 4, 5, 1, 2, 3}) == 4
*/
int scoresAverage(vector<int> scores)
{
	int leftCount = 0;
	int rightCount = 0;
	int leftSum = 0;
	int rightSum = 0;
	int len = scores.size();

	for (unsigned int i = 0; i < len; i++)
	{
		if (i < len / 2)
		{
			leftCount++;
			leftSum += scores[i];
		}
		else
		{
			rightCount++;
			rightSum += scores[i];
		}
	}

	return max(leftSum / leftCount, rightSum / rightCount);
}

/*
Given an array of strings, return the count of the number of strings with the given length().

wordsCount({"a", "bb", "b", "ccc"}, 1) == 2
wordsCount({"a", "bb", "b", "ccc"}, 3) == 1
wordsCount({"a", "bb", "b", "ccc"}, 4) == 0
*/
int wordsCount(vector<string>words, int len)
{
	int count = 0;

	for(string word : words)
		if (word.length() == len)
			count++;

	return count;
}

/*
Given an array of strings, return a new array containing the first N strings.
N will be in the range 1..length().

wordsFront({"a", "b", "c", "d"}, 1) == {"a"}
wordsFront({"a", "b", "c", "d"}, 2) == {"a", "b"}
wordsFront({"a", "b", "c", "d"}, 3) == {"a", "b", "c"}
*/
vector<string> wordsFront(vector<string> s, int N)
{
	vector<string> result;

	for (unsigned int i = 0; i < N; i++)
		result.push_back(s[i]);

	return result;
}


/*
Given an array of strings, return a new List (e.g. an ArrayList) where all the strings of the
given length() are omitted.

wordsWithoutList({"a", "bb", "b", "ccc"}, 1) == {"bb", "ccc"}
wordsWithoutList({"a", "bb", "b", "ccc"}, 3) == {"a", "bb", "b"}
wordsWithoutList({"a", "bb", "b", "ccc"}, 4) == {"a", "bb", "b", "ccc"}
*/
vector<string> wordsWithoutList(vector<string>words, int len)
{
	vector<string> result;

	for(string word : words)
		if (word.length() != len)
			result.push_back(word);

	return result;
}


/*
Given an int n, return true if it contains a 1 digit. Use a loop.
hasOne(10) == true
hasOne(22) == false
hasOne(220) == false
*/
bool hasOne(int n)
{
	int num = abs(n);

	while (num > 0)
	{
		int digit = num % 10;

		if (digit == 1)
			return true;

		num /= 10;
	}

	return false;
}

/*
We'll say that a positive int divides itself if every digit in the number divides into the
number evenly. So for example 128 divides itself since 1, 2, and 8 all divide into 128 evenly.
We'll say that 0 does not divide into anything evenly, so no number with a 0 digit divides itself.

dividesSelf(128) == true
dividesSelf(12) == true
dividesSelf(120) == false
*/
bool dividesSelf(int n)
{
	if (n == 0)
		return false;

	int num = abs(n);

	while (num > 0)
	{
		int digit = n % 10;

		if (digit == 0)
			return false;
		else if (n % digit != 0)
			return false;

		num /= 10;
	}

	return true;
}

/*
Given a vector of positive ints, return a new vector of length "count" containing the first even
numbers from the original array. The original array will contain at least "count" even numbers.

copyEvens({3, 2, 4, 5, 8}, 2) == {2, 4}
copyEvens({3, 2, 4, 5, 8}, 3) == {2, 4, 8}
copyEvens({6, 1, 2, 4, 5, 8}, 3) == {6, 2, 4}
*/
vector<int> copyEvens(vector<int>nums, int count)
{
	vector<int> result;
	int npos = 0, rpos = 0;

	while (rpos < count && npos < nums.size())
	{
		if (nums[npos] % 2 == 0)
		{
			result.push_back(nums[npos]);
			rpos++;
		}
		npos++;
	}

	return result;
}

/*
We'll say that a positive int n is "endy" if it is in the range 0..10 or 90..100 (inclusive).
Given a vector of positive ints, return a new vector of length "count" containing the first endy
numbers from the original array.

copyEndy({9, 11, 90, 22, 6}, 2) == {9, 90}
copyEndy({9, 11, 90, 22, 6}, 3) == {9, 90, 6}
copyEndy({12, 1, 1, 13, 0, 20}, 2) == {1, 1}
*/
vector<int> copyEndy(vector<int>nums, int count)
{
	vector<int> result;
	int npos = 0, rpos = 0;

	while (npos < nums.size() && rpos < count)
	{
		if ((nums[npos] >= 0 && nums[npos] <= 10) || (nums[npos] >= 90 && nums[npos] <= 100))
		{
			result.push_back(nums[npos]);
			rpos++;
		}
		npos++;
	}

	return result;
}

/*
Given 2 vectors that are the same length containing strings, compare the 1st string in one
array to the 1st string in the other, the 2nd to the 2nd and so on. Count the number
of times that the 2 strings are non-empty and start with the same char. The strings may be
any length, including 0.

matchUp({"aa", "bb", "cc"}, {"aaa", "xx", "bb"}) == 1
matchUp({"aa", "bb", "cc"}, {"aaa", "b", "bb"}) == 2
matchUp({"aa", "bb", "cc"}, {"", "", "ccc"}) == 1
*/
int matchUp(vector<string> a, vector<string> b)
{
	int count = 0;
	int len = min(a.size(), b.size());

	for (unsigned int i = 0; i < len; i++)
	{
		if (!a[i].empty() && !b[i].empty())
			if (a[i][0] == b[i][0])
				count++;
	}

	return count;
}

/*
The "key" array is an array containing the correct answers to an exam, like {"a", "a", "b", "b"}.
The "answers" array contains a student's answers, with "?" representing a question left blank.
The two arrays are not empty and are the same length(). Return the score for this array of answers,
giving +4 for each correct answer, -1 for each incorrect answer, and +0 for each blank answer.

scoreUp({"a", "a", "b", "b"}, {"a", "c", "b", "c"}) == 6
scoreUp({"a", "a", "b", "b"}, {"a", "a", "b", "c"}) == 11
scoreUp({"a", "a", "b", "b"}, {"a", "a", "b", "b"}) == 16
*/
int scoreUp(vector<string>key, vector<string> answers)
{
	int score = 0;
	for (unsigned int i = 0; i < min(key.size(), answers.size()); i++)
	{
		if (!key[i].empty() && !answers[i].empty())
			if (key[i] == answers[i])
				score += 4;
			else if (answers[i] != "?")
				score -= 1;
	}
	return score;
}

/*
Given an array of strings, return a new array without the strings that are equal to the target
string.

wordsWithout({"a", "b", "c", "a"}, "a") == {"b", "c"}
wordsWithout({"a", "b", "c", "a"}, "b") == {"a", "c", "a"}
wordsWithout({"a", "b", "c", "a"}, "c") == {"a", "b", "a"}
*/
vector<string> wordsWithout(vector<string>words, string target)
{
	vector<string> result;

	for(string word : words)
		if (word != target)
			result.push_back(word);

	return result;
}

/*
Given two arrays, A and B, of non-negative int scores. A "special" score is one which is a
multiple of 10, such as 40 or 90. Return the sum of largest special score in A and the largest
special score in B.

scoresSpecial({12, 10, 4}, {2, 20, 30}) == 40
scoresSpecial({20, 10, 4}, {2, 20, 10}) == 40
scoresSpecial({12, 11, 4}, {2, 20, 31}) == 20
*/
int scoresSpecial(vector<int> a, vector<int> b)
{
	int aMod10Max = 0;
	int bMod10Max = 0;

	for(int num : a)
		if (num % 10 == 0 && num > aMod10Max)
			aMod10Max = num;

	for(int num : b)
		if (num % 10 == 0 && num > bMod10Max)
			bMod10Max = num;

	return aMod10Max + bMod10Max;
}

/*
We have an array of heights, representing the altitude along a walking trail. Given start/end
indexes into the array, return the sum of the changes for a walk beginning at the start index
and ending at the end index. For example, with the heights {5, 3, 6, 7, 2} and start=2, end=4
yields a sum of 1 + 5 = 6. The start end end index will both be valid indexes into the array
with start <= end.

sumHeights({5, 3, 6, 7, 2}, 2, 4) == 6
sumHeights({5, 3, 6, 7, 2}, 0, 1) == 2
sumHeights({5, 3, 6, 7, 2}, 0, 4) == 11
*/
int sumHeights(vector<int>heights, int start, int end)
{
	int sum = 0;

	for (unsigned int i = start; i < end; i++)
		sum += abs(heights[i] - heights[i + 1]);

	return sum;
}

/*
(A variation on the sumHeights problem.) We have an array of heights, representing the altitude
along a walking trail. Given start/end indexes into the array, return the sum of the changes
for a walk beginning at the start index and ending at the end index, however increases in height
count double. For example, with the heights {5, 3, 6, 7, 2} and start=2, end=4 yields a sum
of 1*2 + 5 = 7. The start end end index will both be valid indexes into the array with start <= end.

sumHeights2({5, 3, 6, 7, 2}, 2, 4) == 7
sumHeights2({5, 3, 6, 7, 2}, 0, 1) == 2
sumHeights2({5, 3, 6, 7, 2}, 0, 4) == 15
*/
int sumHeights2(vector<int>heights, int start, int end)
{
	int sum = 0;

	for (unsigned int i = start; i < end; i++)
	{
		if (heights[i + 1] > heights[i])
			sum += 2 * (heights[i + 1] - heights[i]);
		else
			sum += heights[i] - heights[i + 1];
	}

	return sum;
}

/*
(A variation on the sumHeights problem.) We have an array of heights, representing the altitude
along a walking trail. Given start/end indexes into the array, return the number of "big" steps
for a walk starting at the start index and ending at the end index. We'll say that step is big
if it is 5 or more up or down. The start end end index will both be valid indexes into the array
with start <= end.

bigHeights({5, 3, 6, 7, 2}, 2, 4) == 1
bigHeights({5, 3, 6, 7, 2}, 0, 1) == 0
bigHeights({5, 3, 6, 7, 2}, 0, 4) == 1
*/
int bigHeights(vector<int>heights, int start, int end)
{
	int count = 0;

	for (unsigned int i = start; i < end; i++)
		if (abs(heights[i + 1] - heights[i]) >= 5)
			count++;

	return count;

}

/*
We have data for two users, A and B, each with a string name and an int id. The goal is to order
the users such as for sorting. Return -1 if A comes before B, 1 if A comes after B, and 0 if they
are the same. Order first by the string names, and then by the id numbers if the names are the same.

userCompare("bb", 1, "zz", 2) == -1
userCompare("bb", 1, "aa", 2) == 1
userCompare("bb", 1, "bb", 1) == 0
*/
int userCompare(string aName, int aId, string bName, int bId)
{
	if (aName.compare(bName) < 0)
		return -1;
	else if (aName.compare(bName) > 0)
		return 1;
	else if (aId < bId)
		return -1;
	else if (aId > bId)
		return 1;
	else
		return 0;

}

/*
Start with two arrays of strings, A and B, each with its elements in alphabetical order and
without duplicates. Return a new array containing the first N elements from the two arrays.
The result array should be in alphabetical order and without duplicates. A and B will both
have a length() which is N or more. The best "linear" solution makes a single pass over A and B,
taking advantage of the fact that they are in alphabetical order, copying elements directly
to the new array.

mergeTwo({"a", "c", "z"}, {"b", "f", "z"}, 3) == {"a", "b", "c"}
mergeTwo({"a", "c", "z"}, {"c", "f", "z"}, 3) == {"a", "c", "f"}
mergeTwo({"f", "g", "z"}, {"c", "f", "g"}, 3) == {"c", "f", "g"}
*/
vector<string> mergeTwo(vector<string>a, vector<string> b, int n)
{
	vector<string> result;
	int apos = 0;
	int bpos = 0;

	for (unsigned int i = 0; i < n; i++)
	{
		while (apos < a.size() && i > 0 && a[apos].compare(result[i - 1]) <= 0)
			apos++;

		while (bpos < b.size() && i > 0 && b[bpos].compare(result[i - 1]) <= 0)
			bpos++;

		if (a[apos].compare(b[bpos]) <= 0)
			result.push_back(a[apos++]);
		else
			result.push_back(b[bpos++]);

	}
	return result;
}

/*
Start with two arrays of strings, a and b, each in alphabetical order, possibly with duplicates.
Return the count of the number of strings which appear in both arrays. The best "linear" solution
makes a single pass over both arrays, taking advantage of the fact that they are in alphabetical
order.

commonTwo({"a", "c", "c", "x"}, {"b", "c", "d", "x"}) == 2
commonTwo({"a", "c", "x"}, {"a", "b", "c", "x", "z"}) == 3
commonTwo({"a", "b", "c"}, {"a", "b", "c"}) == 3
*/
int commonTwo(vector<string>a, vector<string> b)
{
	int count = 0;
	int apos = 0;
	int bpos = 0;

	while (apos < a.size() && bpos < b.size())
	{
		while (apos > 0 && a[apos - 1] == a[apos])
			apos++;

		while (bpos > 0 && b[bpos - 1] == b[bpos])
			bpos++;

		if (a[apos].compare(b[bpos]) < 0)
			apos++;
		else if (a[apos].compare(b[bpos]) > 0)
			bpos++;
		else
		{
			count++;
			apos++;
			bpos++;
		}
	}

	return count;
}


int main()
{
	cout << ("scoresIncreasing") << '\n';
	cout << boolalpha << (scoresIncreasing( { 1, 3, 4 }) == true) << '\n';
	cout << boolalpha << (scoresIncreasing( { 1, 3, 2 }) == false) << '\n';
	cout << boolalpha << (scoresIncreasing( { 1, 1, 4 }) == true) << '\n';

	cout << ("scores100") << '\n';
	cout << boolalpha << (scores100( { 1, 100, 100 }) == true) << '\n';
	cout << boolalpha << (scores100( { 1, 100, 99, 100 }) == false) << '\n';
	cout << boolalpha << (scores100( { 100, 1, 100, 100 }) == true) << '\n';
	
	cout << ("scoresClump") << '\n';
	cout << boolalpha << (scoresClump( { 3, 4, 5 }) == true) << '\n';
	cout << boolalpha << (scoresClump( { 3, 4, 6 }) == false) << '\n';
	cout << boolalpha << (scoresClump( { 1, 3, 5, 5 }) == true) << '\n';

	cout << ("scoresAverage") << '\n';
	cout << boolalpha << (scoresAverage( { 2, 2, 4, 4 }) == 4) << '\n';
	cout << boolalpha << (scoresAverage( { 4, 4, 4, 2, 2, 2 }) == 4) << '\n';
	cout << boolalpha << (scoresAverage( { 3, 4, 5, 1, 2, 3 }) == 4) << '\n';

	cout << ("wordsCount") << '\n';
	cout << boolalpha << (wordsCount({ "a", "bb", "b", "ccc" }, 1) == 2) << '\n';
	cout << boolalpha << (wordsCount({ "a", "bb", "b", "ccc" }, 3) == 1) << '\n';
	cout << boolalpha << (wordsCount({ "a", "bb", "b", "ccc" }, 4) == 0) << '\n';

	cout << ("wordsFront") << '\n';
	cout << boolalpha << (wordsFront( { "a", "b", "c", "d" }, 1) == vector<string> {"a" }) << '\n';
	cout << boolalpha << (wordsFront( { "a", "b", "c", "d" }, 2) == vector<string> { "a", "b" }) << '\n';
	cout << boolalpha << (wordsFront( { "a", "b", "c", "d" }, 3) == vector<string> { "a", "b", "c" }) << '\n';
	
	cout << ("wordsWithoutList") << '\n';
	cout << boolalpha << (wordsWithoutList({ "a", "bb", "b", "ccc" }, 1) == vector<string> { "bb", "ccc" }) << '\n';
	cout << boolalpha << (wordsWithoutList({ "a", "bb", "b", "ccc" }, 3) == vector<string> { "a", "bb", "b" }) << '\n';
	cout << boolalpha << (wordsWithoutList({ "a", "bb", "b", "ccc" }, 4) == vector<string> { "a", "bb", "b", "ccc" }) << '\n';

	cout << ("hasOne") << '\n';
	cout << boolalpha << (hasOne(10) == true) << '\n';
	cout << boolalpha << (hasOne(22) == false) << '\n';
	cout << boolalpha << (hasOne(220) == false) << '\n';

	cout << ("dividesSelf") << '\n';
	cout << boolalpha << (dividesSelf(128) == true) << '\n';
	cout << boolalpha << (dividesSelf(12) == true) << '\n';
	cout << boolalpha << (dividesSelf(120) == false) << '\n';

	cout << ("copyEvens") << '\n';
	cout << boolalpha << (copyEvens({ 3, 2, 4, 5, 8 }, 2) == vector<int> { 2, 4 }) << '\n';
	cout << boolalpha << (copyEvens({ 3, 2, 4, 5, 8 }, 3) == vector<int> { 2, 4, 8 }) << '\n';
	cout << boolalpha << (copyEvens({ 6, 1, 2, 4, 5, 8 }, 3) == vector<int> { 6, 2, 4 }) << '\n';

	cout << ("copyEndy") << '\n';
	cout << boolalpha << (copyEndy({ 9, 11, 90, 22, 6 }, 2) == vector<int> { 9, 90 }) << '\n';
	cout << boolalpha << (copyEndy({ 9, 11, 90, 22, 6 }, 2) == vector<int> { 9, 90 }) << '\n';
	cout << boolalpha << (copyEndy({ 9, 11, 90, 22, 6 }, 3) == vector<int> { 9, 90, 6 }) << '\n';
	cout << boolalpha << (copyEndy({ 12, 1, 1, 13, 0, 20 }, 2) == vector<int> { 1, 1 }) << '\n';
	
	cout << ("matchUp") << '\n';
	cout << boolalpha << (matchUp({ "aa", "bb", "cc" }, { "aaa", "xx", "bb" }) == 1) << '\n';
	cout << boolalpha << (matchUp({ "aa", "bb", "cc" }, { "aaa", "b", "bb" }) == 2) << '\n';
	cout << boolalpha << (matchUp({ "aa", "bb", "cc" }, { "", "", "ccc" }) == 1) << '\n';

	cout << ("scoreUp") << '\n';
	cout << boolalpha << (scoreUp({ "a", "a", "b", "b" }, { "a", "c", "b", "c" }) == 6) << '\n';
	cout << boolalpha << (scoreUp({ "a", "a", "b", "b" }, { "a", "a", "b", "c" }) == 11) << '\n';
	cout << boolalpha << (scoreUp({ "a", "a", "b", "b" }, { "a", "a", "b", "b" }) == 16) << '\n';

	cout << ("wordsWithout") << '\n';
	cout << boolalpha << (wordsWithout({ "a", "b", "c", "a" }, "a") == vector<string> { "b", "c" }) << '\n';
	cout << boolalpha << (wordsWithout({ "a", "b", "c", "a" }, "b") == vector<string> { "a", "c", "a" }) << '\n';
	cout << boolalpha << (wordsWithout({ "a", "b", "c", "a" }, "c") == vector<string> { "a", "b", "a" }) << '\n';

	cout << ("scoresSpecial") << '\n';
	cout << boolalpha << (scoresSpecial( { 12, 10, 4 },  { 2, 20, 30 }) == 40) << '\n';
	cout << boolalpha << (scoresSpecial( { 20, 10, 4 },  { 2, 20, 10 }) == 40) << '\n';
	cout << boolalpha << (scoresSpecial( { 12, 11, 4 },  { 2, 20, 31 }) == 20) << '\n';

	cout << ("sumHeights") << '\n';
	cout << boolalpha << (sumHeights( { 5, 3, 6, 7, 2 }, 2, 4) == 6) << '\n';
	cout << boolalpha << (sumHeights( { 5, 3, 6, 7, 2 }, 0, 1) == 2) << '\n';
	cout << boolalpha << (sumHeights( { 5, 3, 6, 7, 2 }, 0, 4) == 11) << '\n';

	cout << ("sumHeights2") << '\n';
	cout << boolalpha << (sumHeights2( { 5, 3, 6, 7, 2 }, 2, 4) == 7) << '\n';
	cout << boolalpha << (sumHeights2( { 5, 3, 6, 7, 2 }, 0, 1) == 2) << '\n';
	cout << boolalpha << (sumHeights2( { 5, 3, 6, 7, 2 }, 0, 4) == 15) << '\n';

	cout << ("bigHeights") << '\n';
	cout << boolalpha << (bigHeights( { 5, 3, 6, 7, 2 }, 2, 4) == 1) << '\n';
	cout << boolalpha << (bigHeights( { 5, 3, 6, 7, 2 }, 0, 1) == 0) << '\n';
	cout << boolalpha << (bigHeights( { 5, 3, 6, 7, 2 }, 0, 4) == 1) << '\n';

	cout << ("userCompare") << '\n';
	cout << boolalpha << (userCompare("bb", 1, "zz", 2) == -1) << '\n';
	cout << boolalpha << (userCompare("bb", 1, "aa", 2) == 1) << '\n';
	cout << boolalpha << (userCompare("bb", 1, "bb", 1) == 0) << '\n';

	cout << ("mergeTwo") << '\n';
	cout << boolalpha << (mergeTwo({ "a", "c", "z" }, { "b", "f", "z" }, 3) == vector<string> { "a", "b", "c" }) << '\n';
	cout << boolalpha << (mergeTwo({ "a", "c", "z" }, { "c", "f", "z" }, 3) == vector<string> { "a", "c", "f" }) << '\n';
	cout << boolalpha << (mergeTwo({ "f", "g", "z" }, { "c", "f", "g" }, 3) == vector<string> { "c", "f", "g" }) << '\n';

	cout << ("commonTwo") << '\n';
	cout << boolalpha << (commonTwo({ "a", "c", "c", "x" }, { "b", "c", "d", "x" }) == 2) << '\n';
	cout << boolalpha << (commonTwo({ "a", "c", "x" }, { "a", "b", "c", "x", "z" }) == 3) << '\n';
	cout << boolalpha << (commonTwo({ "a", "b", "c" }, { "a", "b", "c" }) == 3) << '\n';
    
    // 
	return 0;
}

