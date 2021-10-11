// Programmer:			Ryan Riccio
// Project number:		5
// Project Desc:		Postfix Expression Calculator
// Course:              COSC 2436 PF III Data Structures
// Date:				Oct 9th, 2021

/** @file driver.cpp */

#include <iostream>
#include <string>

#include "PostfixCalculator.h"
using namespace std;

bool validatePostfix(const string& inputString)
{	// static var to store lastChar to check for numbers larger than 9
	static char lastChar;
	bool isValid = true;
	for (const char character : inputString)
	{	// if char in set of valid chars
		if (character >= '0' && character <= '9' ||
			PostfixCalculator::isOperator(character) ||
			character == ' ')
		{	// if the last character is a number and this next character is also a number or operator
			if (lastChar >= '0' && lastChar <= '9' && character != ' ')
			{	// will only give valid error message for inputs < 99 (still sets valid error state)
				cout << "\nInvalid Input: '" << lastChar << character << "'. Operands must be between 0 and 9.\nYou may just need more spaces.";
				isValid = false;
			}
			lastChar = character;
			continue;
		}
		// when the character is not in the set of valid characters
		cout << "\nUnexpected Input: Invalid Character '" << character << "'.";
		isValid = false;
	}
	if (!isValid)	// add space after errors for formatting
		cout << "\n";
	return isValid;
}

bool validateRestart(const string& inputString)
{	// just make sure that the user only entered y or n
	if (inputString != "y" && inputString != "Y" &&
		inputString != "n" && inputString != "N")
	{
		cout << "\nUnknown Input: '" << inputString << "'.\n";
		return false;
	}
	return true;
}

bool stringToBool(const string& inputString)
{	// convert y or n to bool (separate from validateRestart()
	// to prevent trying to convert without validation)
	// will not return if invalid data is given (see validateRestart())
	if (inputString == "y" || inputString == "Y")
		return true;
	if (inputString == "n" || inputString == "N")
		return false;
}

int main()
{
	cout << "POSTFIX CALCULATOR\n";

	// main loop
	bool moreExpressions = true;
	while (moreExpressions)
	{
		bool valid;
		string rawInput;
		do
		{	// priming read and validation 
			cout << "\nEnter postfix expression:\n";
			getline(cin, rawInput);
			valid = validatePostfix(rawInput);

			// once we get a valid input
			if (valid)
			{	// create calc object, perform calculation
				PostfixCalculator calculator = PostfixCalculator(rawInput);
				if (!calculator.getError().empty())	// error is empty when there is no error
					cout << '\n' << calculator.getError() << '\n';	// print error msg
				else
					cout << "Result: " << calculator.getResult() << endl;	// print result
			}
		} while (!valid);	// repeat until we get 1 successful iteration

		string wantsMore;
		do
		{	// priming read and validation
			cout << "\nMore expressions (Y or N)? ";
			getline(cin, wantsMore);
			valid = validateRestart(wantsMore);

			// wait for valid input to parse
			if (valid)
				moreExpressions = stringToBool(wantsMore);	// if moreExp = false, we will not loop again
		} while (!valid);	// repeat until we get 1 successful iteration
	}
	return EXIT_SUCCESS;
}
