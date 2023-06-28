#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:

	static void Srand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	enum enCharType
	{
		CapitalLetter = 1,
		SmallLetter = 2,
		Digit = 3,
		SpecialCharacter = 4,
		MixChars = 5,
	};

	static char RandomCharacter(enCharType CharType)
	{
		//this method to accept mixchars
		if (CharType == MixChars)
		{
			//Capital/Samll/Digits only
			CharType = (enCharType)RandomNumber(1, 3);

		}
		switch (CharType)
		{
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));

		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));

		case enCharType::SpecialCharacter:
			return char(RandomNumber(33, 47));

		case enCharType::Digit:
			return char(RandomNumber(48, 57));

		case enCharType::MixChars:
			 return RandomCharacter((enCharType)RandomNumber(1, 3));

		default:
			return char(RandomNumber(65, 90));
		}
	}

	static string GenerateWord(enCharType CharType, int Length)
	{
		string Word = "";

		for (int i = 1; i <= Length; i++)
		{
			Word += RandomCharacter(CharType);
		}

		return Word;
	}

	static string GenerateKey(enCharType CharType = CapitalLetter)
	{
		string Key = "";

		Key = GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4);

		return Key;
	}

	static void GenerateKeys(int TotalKeys, enCharType CharType = CapitalLetter)
	{
		for (int i = 1; i <= TotalKeys; i++)
		{
			cout << "Key [" << i << "] : " << GenerateKey(CharType) << "\n";
		}
	}

	static void Swap(int& a, int& b)
	{
		int Temp = a;
		a = b;
		b = Temp;
	}

	static void Swap(double& a, double& b)
	{
		double Temp = a;
		a = b;
		b = Temp;
	}

	static void Swap(char& a, char& b)
	{
		char Temp = a;
		a = b;
		b = Temp;
	}

	static void Swap(string& a, string& b)
	{
		string Temp = a;
		a = b;
		b = Temp;
	}

	static void Swap(bool& a, bool& b)
	{
		bool Temp = a;
		a = b;
		b = Temp;
	}

	static void Swap(clsDate& a, clsDate& b)
	{
		clsDate::Swap(a, b);
	}

	static void FillArrayWithRandomNumbers(int arr[], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithOrderedNumbers(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = i + 1;
		}
	}

	static void FillArrayWithRandomWords(string arr[], int arrLength, enCharType CharType, int WordLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateWord(CharType, WordLength);
		}
	}
	 
	static void FillArrayWithRandomKeys(string arr[], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(CharType);
		}
	}

	static void Shuffle(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void Shuffle(double arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void Shuffle(char arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void Shuffle(string arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void Shuffle(bool arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static string Tabs(short NumberOfTabs)
	{
		string Tab = "";

		for (short i = 1; i < NumberOfTabs; i++)
		{
			Tab += "\t";
		}

		return Tab;
	}

	static string Spaces(short NumberOfTabs)
	{
		string Space = "";

		for (short i = 1; i < NumberOfTabs; i++)
		{
			Space += " ";
		}

		return Space;
	}

	static string EncryptText(string Text, short Key)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + Key);
		}

		return Text;
	}

	static string DecryptText(string Text, short Key)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - Key);
		}

		return Text;
	}

};


