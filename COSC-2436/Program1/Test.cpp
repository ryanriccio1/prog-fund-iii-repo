// Programmer:			Ryan Riccio
// Project number:		1
// Project Desc:		EncryptedString class
// Course:              COSC 2436 PF III Data Structures
// Date:				Sept 5th, 2021
#include <string>
#include <iostream>
#include "EncryptedString.h"
using namespace std;


int main()
{
	cout << "EncryptedString Test Program\n\n";

	// Test Case 1 EncryptedString(string str)
	string testCase1Str = "Hi Mom!";	// default test string
	EncryptedString testCase1EncryptedStr = EncryptedString(testCase1Str);
	cout << "Test Case 1 EncryptedString(string str):\n";
	cout << "\tInput = " << testCase1Str << endl;
	cout << "\tEncrypted = " << testCase1EncryptedStr.getEncrypted() << endl;
	cout << "\tDecrypted = " << testCase1EncryptedStr.get() << endl << endl;

	// Test Case 2 with loop for quick testing
	cout << "Test Case 2 EncryptedString():";
	while (true)
	{	// create EncryptedString without data
		EncryptedString testCase2EncryptedStr = EncryptedString();
		string testCase2Str = "";
		cout << "\n(q to quit) Enter first test string: ";
		getline(cin, testCase2Str);
		
		if (testCase2Str == "q" || testCase2Str == "Q")
		{	// exit loop
			break;
		}
		
		cout << "\tInput = " << testCase2Str << endl;
		testCase2EncryptedStr.set(testCase2Str);
		cout << "\tEncrypted = " << testCase2EncryptedStr.getEncrypted() << endl;
		cout << "\tDecrypted = " << testCase2EncryptedStr.get() << endl;
		// testCase2EncryptedStr only in scope for 1 iteration
	}
	cout << "\nThank you! Have a nice day!\n";
}