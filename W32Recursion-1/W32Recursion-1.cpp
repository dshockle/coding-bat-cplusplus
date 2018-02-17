// W32Recursion-1.cpp : Defines the entry point for the console application.
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
Given n of 1 or more, return the factorial of n, which is n * (n-1) * (n-2) ... 1.
Compute the result recursively (without loops).

factorial(1) == 1
factorial(2) == 2
factorial(3) == 6
*/
int factorial(int n)
{
	if (n == 0)
		 return 0;
	else if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

/*
We have a number of bunnies and each bunny has two big floppy ears. We want to compute the
total number of ears across all the bunnies recursively (without loops or multiplication).

bunnyEars(0) == 0
bunnyEars(1) == 2
bunnyEars(2) == 4
*/
int bunnyEars(int bunnies)
{
	if (bunnies == 0)
		 return 0;
	else if (bunnies == 1)
		return 2;
	else
		return 2 + bunnyEars(bunnies - 1);

}

/*
The fibonacci sequence is a famous bit of mathematics, and it happens to have a recursive
definition. The first two values in the sequence are 0 and 1 (essentially 2 base cases).
Each subsequent value is the sum of the previous two values, so the whole sequence is:
0, 1, 1, 2, 3, 5, 8, 13, 21 and so on. Define a recursive fibonacci(n) method that returns
the nth fibonacci number, with n=0 representing the start of the sequence.

fibonacci(0) == 0
fibonacci(1) == 1
fibonacci(2) == 1
*/
int fibonacci(int n)
{
	if (n == 0)
		 return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies (1, 3, ..) have the
normal 2 ears. The even bunnies (2, 4, ..) we'll say have 3 ears, because they each have a
raised foot. Recursively return the number of "ears" in the bunny line 1, 2, ... n (without
loops or multiplication).

bunnyEars2(0) == 0
bunnyEars2(1) == 2
bunnyEars2(2) == 5
*/
int bunnyEars2(int bunnies)
{
	if (bunnies == 0)
		 return 0;
	else if (bunnies == 1)
		return 2;
	else
		return 3 - bunnies % 2 + bunnyEars(bunnies - 1);
}

/*
We have triangle made of blocks. The topmost row has 1 block, the next row down has 2 blocks,
the next row has 3 blocks, and so on. Compute recursively (no loops or multiplication) the
total number of blocks in such a triangle with the given number of rows.

triangle(0) == 0
triangle(1) == 1
triangle(2) == 3
*/
int triangle(int rows)
{
	if (rows == 0)
		 return 0;
	else if (rows == 1)
		return 1;
	else
		return rows + triangle(rows - 1);
}

/*
Given a non-negative int n, return the sum of its digits recursively (no loops).

sumDigits(126) == 9
sumDigits(49) == 13
sumDigits(12) == 3
*/
int sumDigits(int n)
{
	if (n == 0)
		 return 0;
	else
		return n % 10 + sumDigits(n / 10);
}

/*
Given a non-negative int n, return the count of the occurrences of 7 as a digit, so for
example 717 yields 2. (no loops).

count7(717) == 2
count7(7) == 1
count7(123) == 0
*/
int count7(int n)
{
	if (n == 0)
		 return 0;
	else if (n % 10 == 7)
		return 1 + count7(n / 10);
	else
		return count7(n / 10);
}

/*
Given a non-negative int n, compute recursively (no loops) the count of the occurrences
of 8 as a digit, except that an 8 with another 8 immediately to its left counts double,
so 8818 yields 4.

count8(8) == 1
count8(818) == 2
count8(8818) == 4
*/
int count8(int n)
{
	if (n == 0)
		 return 0;
	else if (n % 10 == 8)
		if ((n / 10) % 10 == 8)
			return 2 + count8(n / 10);
		else
			return 1 + count8(n / 10);
	else
		return count8(n / 10);
}


/*
Given baseNum and n that are both 1 or more, compute recursively (no loops) the value of
baseNum to the 'pow' power, so powerN(3, 2) is 9 (3 squared).

powerN(3, 1) == 3
powerN(3, 2) == 9
powerN(3, 3) == 27
*/
int powerN(int baseNum, int pow)
{
	if (pow == 0)
		return 1;
	else if (pow == 1)
		return baseNum;
	else
		return baseNum * powerN(baseNum, pow - 1);
}


/*
Given a string, compute recursively (no loops) the number of lowercase 'x' chars in the string.

countX("xxhixx") == 4
countX("xhixhix") == 3
countX("hi") == 0

*/
int countX(string str)
{
	if (str.length() == 0)
		 return 0;
	else if (str[0] == 'x')
		return 1 + countX(str.substr(1));
	else
		return countX(str.substr(1));
}


/*
Given a string, compute recursively (no loops) the number of times lowercase "hi" appears
in the string.

countHi("xxhixx") == 1
countHi("xhixhix") == 2
countHi("hi") == 1
*/
int countHi(string str)
{
	if (str.length() < 2)
		 return 0;
	else if (str.substr(0, 2) == "hi")
		return 1 + countHi(str.substr(1));
	else
		return countHi(str.substr(1));
}

/*
Given a string, compute recursively (no loops) a new string where all the lowercase 'x'
chars have been changed to 'y' chars.

changeXY("codex") == "codey"
changeXY("xxhixx") == "yyhiyy"
changeXY("xhixhix") == "yhiyhiy"
*/
string changeXY(string str)
{
	if (str.length() == 0)
		return "";
	else if (str[0] == 'x')
		return "y" + changeXY(str.substr(1));
	else
		return str[0] + changeXY(str.substr(1));

}

/*
Given a string, compute recursively (no loops) a new string where all appearances of "pi"
have been replaced by "3.14".

changePi("xpix") == "x3.14x"
changePi("pipi") == "3.143.14"
changePi("pip") == "3.14p"
*/
string changePi(string str)
{
	if (str.length() < 2)
		return str;
	else if (str.substr(0, 2) == "pi")
		return "3.14" + changePi(str.substr(2));
	else
		return str.substr(0, 1) + changePi(str.substr(1));
}

/*
Given a string, compute recursively a new string where all the 'x' chars have been removed.

noX("xaxb") == "ab"
noX("abc") == "abc"
noX("xx") == ""
*/
string noX(string str)
{
	if (str.length() < 1)
		return str;
	else if (str[0] == 'x')
		return noX(str.substr(1));
	else
		return str[0] + noX(str.substr(1));
}

/*
Given an array of ints, compute recursively if the array contains a 6. We'll use the
convention of considering only the part of the array that begins at the given index.
In this way, a recursive call can pass index+1 to move down the array. The initial
call will pass in index as 0.

array6({1, 6, 4}, 0) == true
array6({1, 4}, 0) == false
array6({6}, 0) == true
*/
bool array6(vector<int>nums, int index)
{
	if (nums.size() == 0)
		return false;
	else if (nums.size() <= index)
		return false;
	else if (nums[index] == 6)
		return true;
	else
		return array6(nums, index + 1);
}

/*
Given an array of ints, compute recursively the number of times that the value 11 appears
in the array. We'll use the convention of considering only the part of the array that begins
at the given index. In this way, a recursive call can pass index+1 to move down the array.
The initial call will pass in index as 0.

array11({1, 2, 11}, 0) == 1
array11({11, 11}, 0) == 2
array11({1, 2, 3, 4}, 0) == 0
*/
int array11(vector<int>nums, int index)
{
	if (nums.size() == 0 || nums.size() <= index)
		 return 0;
	else if (nums[index] == 11)
		return 1 + array11(nums, index + 1);
	else
		return array11(nums, index + 1);
}

/*
Given an array of ints, compute recursively if the array contains somewhere a value followed
immediately by that value times 10. We'll use the convention of considering only the part of
the array that begins at the given index. In this way, a recursive call can pass index+1 to
move down the array. The initial call will pass in index as 0.

array220({1, 2, 20}, 0) == true
array220({3, 30}, 0) == true
array220({3}, 0) == false
*/
bool array220(vector<int>nums, int index)
{
	if (nums.size() < 2)
		return false;
	else if (nums[index] * 10 == nums[index + 1])
		return true;
	else
		return array220(nums, index + 1);
}

/*
Given a string, compute recursively a new string where all the adjacent chars are now separated
by a "*".

allStar("hello") == "h*e*l*l*o"
allStar("abc") == "a*b*c"
allStar("ab") == "a*b"
*/
string allStar(string str)
{
	if (str.length() <= 1)
		return str;
	else
		return str.substr(0,1) + "*" + allStar(str.substr(1));
}

/*
Given a string, compute recursively a new string where identical chars that are adjacent in
the original string are separated from each other by a "*".

pairStar("hello") == "hel*lo"
pairStar("xxyy") == "x*xy*y"
pairStar("aaaa") == "a*a*a*a"
*/
string pairStar(string str)
{
	if (str.empty() || str.length() == 1)
		return str;
	else if (str[0] == str[1])
		return str.substr(0, 1) + "*" + pairStar(str.substr(1));
	else
		return str.substr(0, 1) + pairStar(str.substr(1));

}

/*
Given a string, compute recursively a new string where all the lowercase 'x' chars have been
moved to the end of the string.

endX("xxre") == "rexx"
endX("xxhixx") == "hixxxx"
endX("xhixhix") == "hihixxx"
*/
string endX(string str)
{
	if (str.empty())
		return str;
	else if (str[0] == 'x')
		return endX(str.substr(1)) + 'x';
	else
		return str[0] + endX(str.substr(1));
}

/*
We'll say that a "pair" in a string is two instances of a char separated by a char. So "AxA"
the A's make a pair. Pair's can overlap, so "AxAxA" contains 3 pairs -- 2 for A and 1 for x.
Recursively compute the number of pairs in the given string.

countPairs("axa") == 1
countPairs("axax") == 2
countPairs("axbx") == 1
*/
int countPairs(string str)
{
	if (str.empty() || str.length() < 3)
		 return 0;
	else if (str[0] == str[2])
		return 1 + countPairs(str.substr(1));
	else
		return countPairs(str.substr(1));
}


/*
Count recursively the total number of "abc" and "aba" substrings that appear in the given string.

countAbc("abc") == 1
countAbc("abcxxabc") == 2
countAbc("abaxxaba") == 2
*/
int countAbc(string str)
{
	if (str.empty() || str.length() < 3)
		 return 0;
	else if (str.substr(0, 3) == "abc")
		return 1 + countAbc(str.substr(1));
	else if (str.substr(0, 3) == "aba")
		return 1 + countAbc(str.substr(1));
	else
		return countAbc(str.substr(1));
}

/*
Given a string, compute recursively (no loops) the number of "11" substrings in the string.
The "11" substrings should not overlap.

count11("11abc11") == 2
count11("abc11x11x11") == 3
count11("111") == 1
*/
int count11(string str)
{
	if (str.empty() || str.length() < 2)
		 return 0;
	else if (str.substr(0, 2) == "11")
		return 1 + count11(str.substr(2));
	else
		return count11(str.substr(1));
}

/*
Given a string, return recursively a "cleaned" string where adjacent chars that are the same
have been reduced to a single char. So "yyzzza" yields "yza".

stringClean("yyzzza") == "yza"
stringClean("abbbcdd") == "abcd"
stringClean("Hello") == "Helo"
*/
string stringClean(string str)
{
	if (str.empty() || str.length() < 2)
		return str;
	else if (str[0] == str[1])
		return stringClean(str.substr(1));
	else
		return str[0] + stringClean(str.substr(1));
}

/*
Given a string, compute recursively the number of times lowercase "hi" appears in the string,
however do not count "hi" that have an 'x' immedately before them.

countHi2("ahixhi") == 1
countHi2("ahibhi") == 2
countHi2("xhixhi") == 0
*/
int countHi2(string str)
{
	if (str.empty() || str.length() < 2)
		 return 0;
	else if (str.length() == 2)
		if (str == "hi")
			return 1;
		else
			 return 0;
	else if (str[0] == 'x')
		return countHi2(str.substr(2));
	else if (str.substr(0, 2) == "hi")
		return 1 + countHi2(str.substr(2));
	else
		return countHi2(str.substr(1));
}

/*
Given a string that contains a single pair of parenthesis, compute recursively a new string
made of only of the parenthesis and their contents, so "xyz(abc)123" yields "(abc)".

parenBit("xyz(abc)123") == "(abc)"
parenBit("x(hello)") == "(hello)"
parenBit("(xy)1") == "(xy)"
*/
string parenBit(string str)
{
	if (str.empty() || str.length() < 2)
		return "";
	else if (str[0] == '(' && str[str.length() - 1] == ')')
		return str;
	else if (str[0] == '(')
		return parenBit(str.substr(0, str.length() - 1));
	else if (str[str.length() - 1] == ')')
		return parenBit(str.substr(1));
	else
		return parenBit(str.substr(1, str.length() - 1));
}

/*
Given a string, return true if it is a nesting of zero or more pairs of parenthesis,
like "(())" or "((()))". Suggestion: check the first and last chars, and then recur
on what's inside them.

nestParen("(())") == true
nestParen("((()))") == true
nestParen("(((x))") == false
nestParen("((())") == false
nestParen("((()()") == false
nestParen("()") == true
nestParen("") == true
nestParen("(yy)") == false
nestParen("(())") == true
nestParen("(((y))") == false
nestParen("((y)))") == false
nestParen("((()))") == true
nestParen("(())))") == false
nestParen("((yy())))") == false
nestParen("(((())))") == true
*/
bool nestParen(string str)
{
	if (str.empty())
		return true;
	else if (str.length() == 1)
		return false;
	else
	{
		char start = str[0];
		char end = str[str.length() - 1];

		if (start != '(' || end != ')')
			return false;
		else
			return nestParen(str.substr(1, str.length() - 2));
	}
}

/*
Given a string and a non-empty substring sub, compute recursively the number of times that
sub appears in the string, without the sub strings overlapping.

strCount("catcowcat", "cat") == 2
strCount("catcowcat", "cow") == 1
strCount("catcowcat", "dog") == 0
*/
int strCount(string str, string sub)
{
	if (str.empty() || sub.empty())
		 return 0;
	else if (str.length() < sub.length())
		 return 0;
	else if (str.substr(0, sub.length()) == sub)
		return 1 + strCount(str.substr(sub.length()), sub);
	else
		return strCount(str.substr(1), sub);
}


/*
Given a string and a non-empty substring sub, compute recursively if at least n copies of
sub appear in the string somewhere, possibly with overlapping. N will be non-negative.

strCopies("catcowcat", "cat", 2) == true
strCopies("catcowcat", "cow", 2) == false
strCopies("catcowcat", "cow", 1) == true
*/
bool strCopies(string str, string sub, int n)
{
	if (n == 0)
		return true;
	else if (str.empty() || sub.empty())
		return false;
	else if (str.length() < sub.length())
		return false;
	else if (str.substr(0, sub.length()) == sub)
		return strCopies(str.substr(sub.length()), sub, n - 1);
	else
		return strCopies(str.substr(1), sub, n);
}


int main()
{

	cout << ("factorial") << endl;
	cout << boolalpha << (factorial(1) == 1) << endl;
	cout << boolalpha << (factorial(2) == 2) << endl;
	cout << boolalpha << (factorial(3) == 6) << endl;

	cout << ("bunnyEars") << endl;
	cout << boolalpha << (bunnyEars(0) == 0) << endl;
	cout << boolalpha << (bunnyEars(1) == 2) << endl;
	cout << boolalpha << (bunnyEars(2) == 4) << endl;

	cout << ("fibonacci") << endl;
	cout << boolalpha << (fibonacci(0) == 0) << endl;
	cout << boolalpha << (fibonacci(1) == 1) << endl;
	cout << boolalpha << (fibonacci(2) == 1) << endl;

	cout << ("bunnyEars2") << endl;
	cout << boolalpha << (bunnyEars2(0) == 0) << endl;
	cout << boolalpha << (bunnyEars2(1) == 2) << endl;
	cout << boolalpha << (bunnyEars2(2) == 5) << endl;

	cout << ("triangle") << endl;
	cout << boolalpha << (triangle(0) == 0) << endl;
	cout << boolalpha << (triangle(1) == 1) << endl;
	cout << boolalpha << (triangle(2) == 3) << endl;

	cout << ("sumDigits") << endl;
	cout << boolalpha << (sumDigits(126) == 9) << endl;
	cout << boolalpha << (sumDigits(49) == 13) << endl;
	cout << boolalpha << (sumDigits(12) == 3) << endl;

	cout << ("count7") << endl;
	cout << boolalpha << (count7(717) == 2) << endl;
	cout << boolalpha << (count7(7) == 1) << endl;
	cout << boolalpha << (count7(123) == 0) << endl;

	cout << ("count8") << endl;
	cout << boolalpha << (count8(8) == 1) << endl;
	cout << boolalpha << (count8(818) == 2) << endl;
	cout << boolalpha << (count8(8818) == 4) << endl;

	cout << ("powerN") << endl;
	cout << boolalpha << (powerN(3, 1) == 3) << endl;
	cout << boolalpha << (powerN(3, 2) == 9) << endl;
	cout << boolalpha << (powerN(3, 3) == 27) << endl;

	cout << ("countX") << endl;
	cout << boolalpha << (countX("xxhixx") == 4) << endl;
	cout << boolalpha << (countX("xhixhix") == 3) << endl;
	cout << boolalpha << (countX("hi") == 0) << endl;

	cout << ("countHi") << endl;
	cout << boolalpha << (countHi("xxhixx") == 1) << endl;
	cout << boolalpha << (countHi("xhixhix") == 2) << endl;
	cout << boolalpha << (countHi("hi") == 1) << endl;

	cout << ("changeXY") << endl;
	cout << boolalpha << (changeXY("codex") == "codey") << endl;
	cout << boolalpha << (changeXY("xxhixx") == "yyhiyy") << endl;
	cout << boolalpha << (changeXY("xhixhix") == "yhiyhiy") << endl;

	cout << ("changePi") << endl;
	cout << boolalpha << (changePi("xpix") == "x3.14x") << endl;
	cout << boolalpha << (changePi("pipi") == "3.143.14") << endl;
	cout << boolalpha << (changePi("pip") == "3.14p") << endl;

	cout << ("noX") << endl;
	cout << boolalpha << (noX("xaxb") == "ab") << endl;
	cout << boolalpha << (noX("abc") == "abc") << endl;
	cout << boolalpha << (noX("xx") == "") << endl;

	cout << ("array6") << endl;
	cout << boolalpha << (array6( { 1, 6, 4}, 0) == true) << endl;
	cout << boolalpha << (array6( { 1, 4}, 0) == false) << endl;
	cout << boolalpha << (array6( { 6 }, 0) == true) << endl;

	cout << ("array11") << endl;
	cout << boolalpha << (array11( { 1, 2, 11}, 0) == 1) << endl;
	cout << boolalpha << (array11( { 11, 11}, 0) == 2) << endl;
	cout << boolalpha << (array11( { 1, 2, 3, 4}, 0) == 0) << endl;

	cout << ("array220") << endl;
	cout << boolalpha << (array220( { 1, 2, 20}, 0) == true) << endl;
	cout << boolalpha << (array220( { 3, 30}, 0) == true) << endl;
	cout << boolalpha << (array220( { 3 }, 0) == false) << endl;

	cout << ("allStar") << endl;
	cout << boolalpha << (allStar("hello") == "h*e*l*l*o") << endl;
	cout << boolalpha << (allStar("abc") == "a*b*c") << endl;
	cout << boolalpha << (allStar("ab") == "a*b") << endl;

	cout << ("pairStar") << endl;
	cout << boolalpha << (pairStar("hello") == "hel*lo") << endl;
	cout << boolalpha << (pairStar("xxyy") == "x*xy*y") << endl;
	cout << boolalpha << (pairStar("aaaa") == "a*a*a*a") << endl;

	cout << ("endX") << endl;
	cout << boolalpha << (endX("xxre") == "rexx") << endl;
	cout << boolalpha << (endX("xxhixx") == "hixxxx") << endl;
	cout << boolalpha << (endX("xhixhix") == "hihixxx") << endl;

	cout << ("countPairs") << endl;
	cout << boolalpha << (countPairs("axa") == 1) << endl;
	cout << boolalpha << (countPairs("axax") == 2) << endl;
	cout << boolalpha << (countPairs("axbx") == 1) << endl;

	cout << ("countAbc") << endl;
	cout << boolalpha << (countAbc("abc") == 1) << endl;
	cout << boolalpha << (countAbc("abcxxabc") == 2) << endl;
	cout << boolalpha << (countAbc("abaxxaba") == 2) << endl;

	cout << ("count11") << endl;
	cout << boolalpha << (count11("11abc11") == 2) << endl;
	cout << boolalpha << (count11("abc11x11x11") == 3) << endl;
	cout << boolalpha << (count11("111") == 1) << endl;

	cout << ("stringClean") << endl;
	cout << boolalpha << (stringClean("yyzzza") == "yza") << endl;
	cout << boolalpha << (stringClean("abbbcdd") == "abcd") << endl;
	cout << boolalpha << (stringClean("Hello") == "Helo") << endl;

	cout << ("countHi2") << endl;
	cout << boolalpha << (countHi2("ahixhi") == 1) << endl;
	cout << boolalpha << (countHi2("ahibhi") == 2) << endl;
	cout << boolalpha << (countHi2("xhixhi") == 0) << endl;

	cout << ("parenBit") << endl;
	cout << boolalpha << (parenBit("xyz(abc)123") == "(abc)") << endl;
	cout << boolalpha << (parenBit("x(hello)") == "(hello)") << endl;
	cout << boolalpha << (parenBit("(xy)1") == "(xy)") << endl;

	cout << ("nestParen") << endl;
	cout << boolalpha << (nestParen("(())") == true) << endl;
	cout << boolalpha << (nestParen("((()))") == true) << endl;
	cout << boolalpha << (nestParen("(((x))") == false) << endl;

	cout << ("strCount") << endl;
	cout << boolalpha << (strCount("catcowcat", "cat") == 2) << endl;
	cout << boolalpha << (strCount("catcowcat", "cow") == 1) << endl;
	cout << boolalpha << (strCount("catcowcat", "dog") == 0) << endl;

	cout << ("strCopies") << endl;
	cout << boolalpha << (strCopies("catcowcat", "cat", 2) == true) << endl;
	cout << boolalpha << (strCopies("catcowcat", "cow", 2) == false) << endl;
	cout << boolalpha << (strCopies("catcowcat", "cow", 1) == true) << endl;

     return 0;
}

