// CPPWarmup-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*
The parameter weekday is true if it is a weekday, and the parameter vacation
is true if we are on vacation. We sleep in if it is not a weekday or we're on
vacation. Return true if we sleep in.

sleepIn(false, false) ? true
sleepIn(true, false) ? false
sleepIn(false, true) ? true
*/
public static Boolean sleepIn(Boolean w, Boolean v)
{
	return !w || v;
}

/*
We have two monkeys, a and b, and the parameters aSmile and bSmile indicate
if each is smiling. We are in trouble if they are both smiling or if neither
of them is smiling. Return true if we are in trouble.

monkeyTrouble(true, true) ? true
monkeyTrouble(false, false) ? true
monkeyTrouble(true, false) ? false
*/
public static Boolean monkeyTrouble(Boolean aSmile, Boolean bSmile)
{
	return aSmile == bSmile;
}

/*
Given two int values, return their sum. Unless the two values are the same,
then return double their sum.

sumDouble(1, 2) ? 3
sumDouble(3, 2) ? 5
sumDouble(2, 2) ? 8
*/
public static int sumDouble(int a, int b)
{
	if (a == b)
		return 2 * (a + b);
	else
		return a + b;
}

/*
Given 2 int values, return whichever value is nearest to the value 10, or
return 0 in the event of a tie.

close10(8, 13) ? 8
close10(13, 8) ? 8
close10(13, 7) ? 0
*/
public static int close10(int a, int b)
{
	int a10 = Math.Abs(a - 10);
	int b10 = Math.Abs(b - 10);

	if (a10 < b10)
		return a;
	else if (b10 < a10)
		return b;
	else
		return 0;
}

/*
Return true if the given string contains between min and max 'c' chars.

stringC("Hello", 'e', 1, 3) ? true
stringC("Everyone", 'e', 1, 3) ? true
stringC("Heelele", 'e', 1, 3) ? false
*/
public static Boolean stringC(String str, char c, int min, int max)
{
	int count = 0;

	if (!string.IsNullOrEmpty(str))
	{
		foreach(char ch in str)
		{
			if (char.ToLower(ch) == char.ToLower(ch))
				count++;
		}
	}

	return count >= min && count <= max;
}

/*
Return true if the given string contains between min and max 'c' chars.
Use Linq. Do not use loops.
stringCLinq("Hello", 'e', 1, 3) ? true
stringCLinq("Everyone", 'e', 1, 3) ? true
stringCLinq("Heelele", 'e', 1, 3) ? false
*/
public static Boolean stringCLinq(String str, char c, int min, int max)
{
	int count = str.ToLower().Count(letter = > letter == c);
	return count >= min && count <= max;
}

/*
Given two non-negative int values, return true if they have the same last digit,
such as with 27 and 57.

lastDigit(7, 17) ? true
lastDigit(6, 17) ? false
lastDigit(3, 113) ? true
*/
public static Boolean lastDigit(int a, int b)
{
	return a % 10 == b % 10;
}

/*
Given a string, return a new string where the last 'num' chars are
now in upper case. If the string has less than 'num' chars,
uppercase whatever is there.

endUp("Hello", 3) ? "HeLLO"
endUp("hi there", 3) ? "hi thERE"
endUp("hi", 3) ? "HI"
*/
public static string endUp(string str, int num)
{
	if (num <= 0)
		return str;
	else if (str.Length > num)
	{
		string front = str.Substring(0, str.Length - num);
		string back = str.Substring(str.Length - num);
		return front + back.ToUpper();
	}
	else
		return str.ToUpper();
}

/*
Given a non-empty string and an int N, return the string made starting
with char 0, and then every Nth char of the string.
So if N is 3, use char 0, 3, 6, ... and so on. N is 1 or more.

everyNth("Miracle", 2) ? "Mrce"
everyNth("abcdefg", 2) ? "aceg"
everyNth("abcdefg", 3) ? "adg"
*/
public static string everyNth(string str, int n)
{
	StringBuilder sb = new StringBuilder();
	for (int i = 0; i < str.Length; i += n)
	{
		sb.Append(str[i]);
	}
	return sb.ToString();
}

int main()
{
	Console.WriteLine("sleepIn");
	Console.WriteLine(sleepIn(false, false) == true);
	Console.WriteLine(sleepIn(true, false) == false);
	Console.WriteLine(sleepIn(false, true) == true);

	Console.WriteLine("monkeyTrouble");
	Console.WriteLine(monkeyTrouble(true, true) == true);
	Console.WriteLine(monkeyTrouble(false, false) == true);
	Console.WriteLine(monkeyTrouble(true, false) == false);

	Console.WriteLine("sumDouble");
	Console.WriteLine(sumDouble(1, 2) == 3);
	Console.WriteLine(sumDouble(3, 2) == 5);
	Console.WriteLine(sumDouble(2, 2) == 8);

	Console.WriteLine("close10");
	Console.WriteLine(close10(8, 13) == 8);
	Console.WriteLine(close10(13, 8) == 8);
	Console.WriteLine(close10(13, 7) == 0);

	Console.WriteLine("stringC");
	Console.WriteLine(stringC("Hello", 'e', 1, 3) == true);
	Console.WriteLine(stringC("Everyone", 'e', 1, 3) == true);
	Console.WriteLine(stringC("Heelele", 'e', 1, 3) == false);

	Console.WriteLine("stringCLinq");
	Console.WriteLine(stringCLinq("Hello", 'e', 1, 3) == true);
	Console.WriteLine(stringCLinq("Everyone", 'e', 1, 3) == true);
	Console.WriteLine(stringCLinq("Heelele", 'e', 1, 3) == false);

	Console.WriteLine("lastDigit");
	Console.WriteLine(lastDigit(7, 17) == true);
	Console.WriteLine(lastDigit(6, 17) == false);
	Console.WriteLine(lastDigit(3, 113) == true);

	Console.WriteLine("endUp");
	Console.WriteLine(endUp("Hello", 3) == "HeLLO");
	Console.WriteLine(endUp("hi there", 3) == "hi thERE");
	Console.WriteLine(endUp("hi", 3) == "HI");

	Console.WriteLine("everyNth");
	Console.WriteLine(everyNth("Miracle", 2) == "Mrce");
	Console.WriteLine(everyNth("abcdefg", 2) == "aceg");
	Console.WriteLine(everyNth("abcdefg", 3) == "adg");

	return 0;
}
