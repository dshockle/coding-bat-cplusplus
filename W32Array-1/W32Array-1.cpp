// W32Array-1.cpp : Defines the entry point for the console application.
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
Start with 2 int arrays, a and b, each length() 2.
Consider the sum of the values in each array.
Return the array which has the largest sum.
In event of a tie, return a.

biggerTwo({1, 2}, {3, 4}) == {3, 4}
biggerTwo({3, 4}, {1, 2}) == {3, 4}
biggerTwo({1, 1}, {1, 2}) == {1, 2}
*/
vector<int> biggerTwo(vector<int> a, vector<int> b)
{
	if (sumArray(a) >= sumArray(b))
		return a;
	else
		return b;
}


/*
Return the two middle elements of the even-length() array.

makeMiddle({1, 2, 3, 4}) == {2, 3}
makeMiddle({7, 1, 2, 3, 4, 9}) == {2, 3}
makeMiddle({1, 2}) == {1, 2}
*/
vector<int> makeMiddle(vector<int> nums)
{
	if (nums.size() < 2)
		return nums;
	else
		return  { nums[nums.size() / 2 - 1], nums[nums.size() / 2]};
}


/*
Given 2 int arrays, each length() 2, return a new array length() 4
containing all their elements. Use a list.

plusTwoList({1, 2}, {3, 4}) == {1, 2, 3, 4}
plusTwoList({4, 4}, {2, 2}) == {4, 4, 2, 2}
plusTwoList({9, 2}, {3, 4}) == {9, 2, 3, 4}
*/
vector<int> plusTwo(vector<int> a, vector<int> b)
{
	a.insert(a.end(), b.begin(), b.end());
	return a;
}

/*
Given an array of ints, swap the first and last elements in the array.
Return the modified array.

The array length() will be at least 1.

swapEnds({1, 2, 3, 4}) == {4, 2, 3, 1}
swapEnds({1, 2, 3}) == {3, 2, 1}
swapEnds({8, 6, 7, 9, 5}) == {5, 6, 7, 9, 8}
*/
vector<int> swapEnds(vector<int>nums)
{
	int temp = nums[0];
	nums[0] = nums[nums.size() - 1];
	nums[nums.size() - 1] = temp;
	return nums;
}

/*
Given an array of ints of odd length(), return a new array length() 3
containing the elements from the middle of the array. The array
length() will be at least 3.

midThree({1, 2, 3, 4, 5}) == {2, 3, 4}
midThree({8, 6, 7, 5, 3, 0, 9}) == {7, 5, 3}
midThree({1, 2, 3}) == {1, 2, 3}
*/
vector<int> midThree(vector<int> nums)
{
	int mid = nums.size() / 2;
	return  { nums[mid - 1], nums[mid], nums[mid + 1] };
}

/*
Given an array of ints of odd length(), return a new array length() N
containing the elements from the middle of the array. The array
length() will be at least N.

midN({1, 2, 3, 4, 5}, 3) == {2, 3, 4}
midN({8, 6, 7, 5, 3, 0, 9}, 3) == {7, 5, 3}
midN({1, 2, 3}, 3) == {1, 2, 3}
*/
vector<int> midN(vector<int>nums, int n)
{
	vector<int> result;
	int start = nums.size() / 2 - n / 2;
	result.insert(result.begin(), nums[start], n);
	return result;
}

/*
Given an array of ints of odd length(), look at the first, last,
and middle values in the array and return the largest.
The array length() will be a least 1.

maxTriple({1, 2, 3}) == 3
maxTriple({1, 5, 3}) == 5
maxTriple({5, 2, 3}) == 5
*/
int maxTriple(vector<int>nums)
{
	return max(nums[0], max(nums[nums.size() / 2], nums[nums.size() - 1]));
}

/*
Given an int array of any length(), return a new array of its first 2 elements.
If the array is smaller than length() 2, use whatever elements are present.

front2({1, 2, 3}) == {1, 2}
front2({1, 2}) == {1, 2}
front2({1}) == {1}
*/
vector<int> front2(vector<int>nums)
{
	if (nums.size() < 2)
		return nums;
	else
		return  { nums[0], nums[1] };
}

/*
Given an int array of any length, return a new array of its first N elements.
If the array is smaller than length N, use whatever elements are present.

frontN({1, 2, 3}, 2) == {1, 2}
frontN({1, 2}, 2) == {1, 2}
frontN({1}, 2) == {1}
*/
vector<int> frontN(vector<int> nums, int n)
{
	int s = nums.size();
	if (s <= n)
		return nums;
	else
	{
		vector<int> result;
		auto it = std::next(nums.begin(), n);
		std::move(nums.begin(), it, std::back_inserter(result));
		return result;
	}

}

bool is13(vector<int>nums, int start)
{
	return start >= 0 && start < nums.size() - 1 && nums[start] == 1 && nums[start + 1] == 3;
}

/*
We'll say that a 1 immediately followed by a 3 in an array is an "unlucky" 1.
Return true if the given array contains an unlucky 1 in the first 2 or
last 2 positions in the array.

unlucky1({1, 3, 4, 5}) == true
unlucky1({2, 1, 3, 4, 5}) == true
unlucky1({1, 1, 1}) == false
*/
bool unlucky1(vector<int>nums)
{
	if (nums.size() < 2)
		return false;
	else
		return is13(nums, 0) || is13(nums, 1) || is13(nums, nums.size() - 2);
}

/*
Given 2 int arrays, a and b, return a new array length() 2 containing,
as much as will fit, the elements from a followed by the elements from b.
The arrays may be any length(), including 0, but there will be 2 or more
elements available between the 2 arrays.

make2({4, 5}, {1, 2, 3}) == {4, 5}
make2({4}, {1, 2, 3}) == {4, 1}
make2({}, {1, 2}) == {1, 2}
*/
vector<int> make2(vector<int>a, vector<int> b)
{
	vector<int> result;

	if (a.size() >= 2)
		result =  { a[0], a[1] };
	else if (a.size() == 1)
		result =  { a[0], b[0] };
	else
		result =  { b[0], b[1] };

	return result;
}

/*
Given 2 int arrays, a and b, return a new array length() N containing,
as much as will fit, the elements from a followed by the elements from b.
The arrays may be any length(), including 0, but there will be N or more
elements available between the 2 arrays.

makeN({4, 5}, {1, 2, 3}, 2) == {4, 5}
makeN({4}, {1, 2, 3}, 2) == {4, 1}
makeN({}, {1, 2}, 2) == {1, 2}
*/
vector<int> makeN(vector<int>a, vector<int> b, int n)
{
	if (a.size() == 0)
	{
		vector<int> result(a.begin(), a.end() - n);
		return result;
	}

	else if (b.size() == 0)
	{
		vector<int> result(b.begin(), b.end() - n);
		return result;
	}

	else
	{
		vector<int> result(a.begin(), a.end() - n);
		result.insert(result.end(), b.begin(), b.end());
		return result;
	}
}

/*
Given 2 int arrays, a and b, of any length(), return a new array with the
first element of each array. If either array is length() 0, ignore that array.
Use a list.
front11List({1, 2, 3}, {7, 9, 8}) == {1, 7}
front11List({1}, {2}) == {1, 2}
front11List({1, 7}, {}) == {1}
*/
vector<int> front11(vector<int>a, vector<int> b)
{
	vector<int> list;

	if (a.size() > 0)
		list.push_back(a[0]);
		
	if (b.size() > 0)
		list.push_back(b[0]);
	
	return list;
}


int main()
{
	cout << ("biggerTwo") << '\n';
	cout << boolalpha << (biggerTwo( { 1, 2},  { 3, 4}) == std::vector<int> { 3, 4}) << '\n';
	cout << boolalpha << (biggerTwo( { 3, 4},  { 1, 2}) == std::vector<int> { 3, 4}) << '\n';
	cout << boolalpha << (biggerTwo( { 1, 1},  { 1, 2}) == std::vector<int> { 1, 2}) << '\n';

	cout << ("biggerTwo") << '\n';
	cout << boolalpha << (biggerTwo( { 1, 2 },  { 3, 4 }) == std::vector<int> { 3, 4 }) << '\n';
	cout << boolalpha << (biggerTwo( { 3, 4 },  { 1, 2 }) == std::vector<int> { 3, 4 }) << '\n';
	cout << boolalpha << (biggerTwo( { 1, 1 },  { 1, 2 }) == std::vector<int> { 1, 2 }) << '\n';

	cout << ("makeMiddle") << '\n';
	cout << boolalpha << (makeMiddle( { 1, 2, 3, 4}) == std::vector<int> { 2, 3}) << '\n';
	cout << boolalpha << (makeMiddle( { 7, 1, 2, 3, 4, 9}) == std::vector<int> { 2, 3}) << '\n';
	cout << boolalpha << (makeMiddle( { 1, 2}) == std::vector<int> { 1, 2}) << '\n';

	cout << ("plusTwo") << '\n';
	cout << boolalpha << (plusTwo( { 1, 2},  { 3, 4}) == std::vector<int> { 1, 2, 3, 4}) << '\n';
	cout << boolalpha << (plusTwo( { 4, 4},  { 2, 2}) == std::vector<int> { 4, 4, 2, 2}) << '\n';
	cout << boolalpha << (plusTwo( { 9, 2},  { 3, 4}) == std::vector<int> { 9, 2, 3, 4}) << '\n';

	cout << ("plusTwo") << '\n';
	cout << boolalpha << (plusTwo( { 1, 2 },  { 3, 4 }) == std::vector<int> { 1, 2, 3, 4 }) << '\n';
	cout << boolalpha << (plusTwo( { 4, 4 },  { 2, 2 }) == std::vector<int> { 4, 4, 2, 2 }) << '\n';
	cout << boolalpha << (plusTwo( { 9, 2 },  { 3, 4 }) == std::vector<int> { 9, 2, 3, 4 }) << '\n';

	cout << ("swapEnds") << '\n';
	cout << boolalpha << (swapEnds( { 1, 2, 3, 4}) == std::vector<int> { 4, 2, 3, 1}) << '\n';
	cout << boolalpha << (swapEnds( { 1, 2, 3}) == std::vector<int> { 3, 2, 1}) << '\n';
	cout << boolalpha << (swapEnds( { 8, 6, 7, 9, 5}) == std::vector<int> { 5, 6, 7, 9, 8}) << '\n';

	cout << ("midN") << '\n';
	cout << boolalpha << (midThree( { 1, 2, 3, 4, 5}) == std::vector<int> { 2, 3, 4}) << '\n';
	cout << boolalpha << (midThree( { 8, 6, 7, 5, 3, 0, 9}) == std::vector<int> { 7, 5, 3}) << '\n';
	cout << boolalpha << (midThree( { 1, 2, 3}) == std::vector<int> { 1, 2, 3}) << '\n';

	cout << ("midN") << '\n';
	cout << boolalpha << (midThree( { 1, 2, 3, 4, 5 }) == std::vector<int> { 2, 3, 4 }) << '\n';
	cout << boolalpha << (midThree( { 8, 6, 7, 5, 3, 0, 9 }) == std::vector<int> { 7, 5, 3 }) << '\n';
	cout << boolalpha << (midThree( { 1, 2, 3 }) == std::vector<int> { 1, 2, 3 }) << '\n';
	
	cout << ("maxTriple") << '\n';
	cout << boolalpha << (maxTriple( { 1, 2, 3}) == 3) << '\n';
	cout << boolalpha << (maxTriple( { 1, 5, 3}) == 5) << '\n';
	cout << boolalpha << (maxTriple( { 5, 2, 3}) == 5) << '\n';

	cout << ("front2") << '\n';
	cout << boolalpha << (front2( { 1, 2, 3}) == std::vector<int> { 1, 2}) << '\n';
	cout << boolalpha << (front2( { 1, 2}) == std::vector<int> { 1, 2}) << '\n';
	cout << boolalpha << (front2( { 1 }) == std::vector<int> { 1 }) << '\n';

	cout << ("frontN") << '\n';
	cout << boolalpha << (frontN( { 1, 2, 3 }, 2) == std::vector<int> { 1, 2 }) << '\n';
	cout << boolalpha << (frontN( { 1, 2 }, 2) == std::vector<int> { 1, 2 }) << '\n';
	cout << boolalpha << (frontN( { 1 }, 2) == std::vector<int> { 1 }) << '\n';

	cout << ("unlucky1") << '\n';
	cout << boolalpha << (unlucky1( { 1, 3, 4, 5}) == true) << '\n';
	cout << boolalpha << (unlucky1( { 2, 1, 3, 4, 5}) == true) << '\n';
	cout << boolalpha << (unlucky1( { 1, 1, 1}) == false) << '\n';

	cout << ("makeN") << '\n';
	cout << boolalpha << (make2( { 4, 5},  { 1, 2, 3}) == std::vector<int> { 4, 5}) << '\n';
	cout << boolalpha << (make2( { 4},  { 1, 2, 3}) == std::vector<int> { 4, 1}) << '\n';
	cout << boolalpha << (make2( {},  { 1, 2}) == std::vector<int> { 1, 2}) << '\n';

	cout << ("front11") << '\n';
	cout << boolalpha << (front11( { 1, 2, 3},  { 7, 9, 8}) == std::vector<int> { 1, 7}) << '\n';
	cout << boolalpha << (front11( { 1 },  { 2 }) == std::vector<int> { 1, 2}) << '\n';
	cout << boolalpha << (front11( { 1, 7},  {}) == std::vector<int> { 1 }) << '\n';

    // 
	return 0;
}

