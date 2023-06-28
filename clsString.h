#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

class clsString
{
private:
	string _Value;

public:
	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string Text)
	{
		return Text.length();
	}

	short Length()
	{
		return Length(_Value);
	}

	static bool IsDigit(char Letter)
	{
		return ((int)Letter >= 48 || (int)Letter <= 57);
	}

	static bool IsPunct(char Letter)
	{
		return ispunct(Letter);
	}

	static bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);

		return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
	}
	
	static bool IsLetter(char Letter)
	{
		return islower(Letter) || isupper(Letter);
	}

	static string LowerAllLetters(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (isupper(Text[i]))
				Text[i] = tolower(Text[i]);
		}

		return Text;
	}

	void  LowerAllLetters()
	{
		_Value = LowerAllLetters(_Value);
	}

	static string UpperAllLetters(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (islower(Text[i]))
				Text[i] = toupper(Text[i]);
		}

		return Text;
	}

	void  UpperAllLetters()
	{
		_Value = UpperAllLetters(_Value);
	}

	static char InvertLetterCase(char Letter)
	{
		return (islower(Letter) ? toupper(Letter) : tolower(Letter));
	}

	static string InvertAllLetttersCase(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = InvertLetterCase(Text[i]);
		}

		return Text;
	}

	void InvertAllLetttersCase()
	{
		_Value = InvertAllLetttersCase(_Value);
	}

	static bool IsSpecialChar(char Letter)
	{
		return ((int)Letter >= 33 || (int)Letter <= 47)
			||
			((int)Letter >= 58 || (int)Letter <= 64)
			||
			((int)Letter >= 91 || (int)Letter <= 96)
			||
			((int)Letter >= 123 || (int)Letter <= 126)
			||
			((int)Letter >= 145 || (int)Letter <= 149);
	}

	static short CountSmallLetters(string Text)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (islower(Text[i]))
				Counter++;
		}

		return Counter;
	}

	short CountSmallLetter()
	{
		return CountSmallLetters(_Value);
	}

	static short CountCapitalLetters(string Text)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (isupper(Text[i]))
				Counter++;
		}

		return Counter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountLetters(string Text)
	{
		return CountCapitalLetters(Text) + CountSmallLetters(Text);
	}

	short CountLetters()
	{
		return CountLetters(_Value);
	}

	static short CountVowels(string Text)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (IsVowel(Text[i]))
				Counter++;
		}

		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static short CountSpecificLetter(string Text, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		if (MatchCase)
		{
			for (int i = 0; i < Text.length(); i++)
			{
				if (Text[i] == Letter)
					Counter++;
			}
		}

		else
		{
			for (int i = 0; i < Text.length(); i++)
			{
				if (tolower(Text[i]) == tolower(Letter))
					Counter++;
			}
		}

		return Counter;
	}

	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	static string UpperFirstLetter(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (IsLetter(Text[i]))
			{
				Text[i] = toupper(Text[i]);
				break;
			}
		}

		return Text;
	}

	void UpperFirstLetter()
	{
		_Value = UpperFirstLetter(_Value);
	}

	static string LowerFirstLetter(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (IsLetter(Text[i]))
			{
				Text[i] = tolower(Text[i]);
				break;
			}
		}

		return Text;
	}

	void LowerFirstLetter()
	{
		_Value = LowerFirstLetter(_Value);
	}

	static string UpperFirstLetterOfEachWord(string Text)
	{
		bool IsFirstLetter = true;

		for (short i = 0; i < Text.length(); i++)
		{
			if (IsFirstLetter && Text[i] != ' ')
				Text[i] = toupper(Text[i]);

			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}

		return Text;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string Text)
	{
		bool IsFirstLetter = true;

		for (short i = 0; i < Text.length(); i++)
		{
			if (IsFirstLetter && Text[i] != ' ')
				Text[i] = tolower(Text[i]);

			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}

		return Text;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static vector<string> Split(string Text, string Delimiter = " ")
	{
		string Word = "";
		short Position = 0;
		vector<string> vWords;

		while ((Position = Text.find(Delimiter)) != std::string::npos)
		{
			Word = Text.substr(0, Position);

			if (Word != "")
				vWords.push_back(Word);

			Text.erase(0, Position + Delimiter.length());
		}

		if (Text != "")
			vWords.push_back(Text);

		return vWords;
	}

	vector<string> Split(string Delimiter = " ")
	{
		return Split(_Value, Delimiter);
	}

	static string JoinString(vector<string> vWords, string Delimiter = " ")
	{
		string Text = "";

		for (string& Word : vWords)
			Text += Word + Delimiter;

		return Text.substr(0, Text.length() - Delimiter.length());
	}

	static string JoinString(string Array[], short Length, string Delimiter = " ")
	{
		string Text = "";

		for (short i = 0; i < Length; i++)
		{
			Text += Array[i] + Delimiter;
		}

		return Text.substr(0, Text.length() - Delimiter.length());
	}

	static short CountWords(string Text, string Delimiter = " ")
	{
		return Split(Text, Delimiter).size();
	}

	short CountWords(string Delimiter = " ")
	{
		return CountWords(_Value, Delimiter);
	}

	static short CountWord(string Text, string Word)
	{
		short Counter = 0;

		vector<string> vWords = Split(Text, " ");

		for (string& W : vWords)
		{
			if (RemovePunctuations(W) == Word)
				Counter++;
		}

		return Counter;
	}

	short CountWord(string Word)
	{
		return CountWord(_Value, Word);
	}

	static string TrimLeft(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ')
				return Text.substr(i, Text.length() - i);
		}

		return "";

		//My Method
		/*
		while (Text[0] == ' ')
		{
			Text.erase(0, 1);
		}

		return Text;*/
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string Text)
	{
		/*
		for (short i = Text.length() - 1; i >= 0; i--)
		{
			if (Text[i] != ' ')
				return Text.substr(0, i + 1);
		}

		return "";*/

		//My Method
		while (Text[Text.length() - 1] == ' ')
		{
			Text.erase(Text.length() - 1, 1);
		}

		return Text;
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string Text)
	{
		return TrimLeft(TrimRight(Text));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string Reverse(string Text)
	{
		for (short i = 0; i < Text.length() / 2; i++)
		{
			swap(Text[i], Text[Text.length() - 1 - i]);
		}

		return Text;
	}

	void Reverse()
	{
		_Value = Reverse(_Value);
	}

	static string ReverseWords(string Text)
	{
		string Reversed = "";

		vector<string> vWords = Split(Text, " ");

		vector<string>::iterator iter = vWords.end();

		while (iter != vWords.begin())
		{
			iter--;

			Reversed += *iter + " ";
		}

		return Reversed.substr(0, Reversed.length() - 1);
	}

	string ReverseWords()
	{
		return ReverseWords(_Value);
	}

	static string ReplaceWord(string Text, string Replace, string Update, bool MatchCase = true)
	{
		string Delim = " ";
		short Pos = 0;

		if (MatchCase)
		{
			while ((Pos = Text.find(Replace)) != std::string::npos)
			{
				Text.replace(Pos, Replace.length(), Update);
			}
		}

		else
		{
			string Temp = LowerAllLetters(Text);
			Replace = LowerAllLetters(Replace);

			while ((Pos = Temp.find(Replace)) != std::string::npos)
			{
				Temp.replace(Pos, Replace.length(), Update);
				Text.replace(Pos, Replace.length(), Update);
			}
		}

		return Text;
	}

	void ReplaceWord(string Replace, string Update, bool MatchCase = true)
	{
		_Value = ReplaceWord(_Value, Replace, Update, MatchCase);
	}

	static string RemovePunctuations(string Text)
	{
		string S2;

		for (short i = 0; i < Text.length(); i++)
		{
			if (!ispunct(Text[i]))
				S2 += Text[i];
		}

		return S2;
	}

	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}

	static bool IsPalindrome(string Text)
	{
		return Reverse(Text) == Text;
	}

	bool IsPalindrome()
	{
		return IsPalindrome(_Value);
	}

};

