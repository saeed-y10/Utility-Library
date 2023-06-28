#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

int main()
{

    clsUtil::Srand();
    
    cout << clsUtil::RandomNumber(1, 10) << endl;
    cout << clsUtil::RandomCharacter(clsUtil::CapitalLetter) << endl;
    cout << clsUtil::GenerateWord(clsUtil::MixChars, 8) << endl;
    cout << clsUtil::GenerateKey(clsUtil::MixChars) << endl;

    cout << "\n";

    clsUtil::GenerateKeys(10, clsUtil::MixChars);

    cout << "\n";

    //Swap Int
    int x = 10, y = 20;
    cout << x << " " << y << endl;

    clsUtil::Swap(x, y);
    cout << x << " " << y << endl << endl;

    //Swap double
    double a = 10.5, b = 20.5;
    cout << a << " " << b << endl;

    clsUtil::Swap(a, b);
    cout << a << " " << b << endl << endl;

    //Swap String
    string s1 = "Ali", s2 = "Ahmed";
    cout << s1 << " " << s2 << endl;
    clsUtil::Swap(s1, s2);
    cout << s1 << " " << s2 << endl << endl;

    //Swap Dates
    clsDate d1(1, 10, 2022), d2(1, 1, 2022);
    cout << d1.ToString() << " " << d2.ToString() << endl;

    clsUtil::Swap(d1, d2);
    cout << d1.ToString() << " " << d2.ToString() << endl;

    //Shuffl Array
    // 
    //int array
    int Arr1[5] = { 1,2,3,4,5 };
    
    clsUtil::Shuffle(Arr1, 5);

    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr1[i] << ", ";
    }

    //string array
    string Arr2[5] = { "Ali","Fadi","Ahmed","Qasem","Khalid" };

    clsUtil::Shuffle(Arr2, 5);

    cout << "\n\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr2[i] << ", ";
    }

    int Arr3[5];
    clsUtil::FillArrayWithRandomNumbers(Arr3, 5, 20, 50);

    cout << "\n\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr3[i] << ", ";
    }


    string Arr4[5];
    clsUtil::FillArrayWithRandomWords(Arr4, 5, clsUtil::MixChars, 8);

    cout << "\n\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr4[i] << ", ";
    }

    string Arr5[5];
    clsUtil::FillArrayWithRandomKeys(Arr5, 5, clsUtil::MixChars);

    cout << "\n\nArray after filling keys:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr5[i] << endl;
    }

    cout << "\nText1 " << clsUtil::Tabs(4) << "Text2\n";

    cout << "\nText1 " << clsUtil::Spaces(4) << "Text2\n";


    const short EncryptionKey = 2; //this is the key.
    string TextAfterEncryption, TextAfterDecryption;
    string Text = "Mohammed Abu-Hadhoud";

    TextAfterEncryption = clsUtil::EncryptText(Text, EncryptionKey);
    TextAfterDecryption = clsUtil::DecryptText(TextAfterEncryption, EncryptionKey);

    cout << "\nText Before Encryption : ";
    cout << Text << endl;
    
    cout << "Text After Encryption  : ";
    cout << TextAfterEncryption << endl;
    
    cout << "Text After Decryption  : ";
    cout << TextAfterDecryption << endl;

    system("pause>0");

	return 0;
}