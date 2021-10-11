/** Separate Calculator functions for better
 * distribution of responsibilities and OOP
 *@file PostfixCalculator.h */

#pragma once
#include <string>
#include "ArrayStack.h"

using namespace std;

class PostfixCalculator
{
public:
	/** Default Constructor */
	PostfixCalculator();

	/** Create object with existing postfix expression.
	 *@param postfixExpression A string that is an expression. */
	PostfixCalculator(const string& postfixExpression);

	/** Get the result of the postfix calculation.
	 * @returns Integer value of result. */
	int getResult() const;

	/** Get the error message if there was one.
	 *@returns A string with error message. Will be empty if no error. */
	string getError() const;

	/** Static method to see if char is in list of valid operators.
	 *@param character The character we are validating.
	 *@returns A boolean of validity. */
	static bool isOperator(const char& character);

private:
	int result;					// stores result of calculation
	string errorMessage;		// stores error msg
	string postfixExpression;	// stores postfix input
	ArrayStack<int> stack;		// stack used in calculation
	void calculate();			// calculation method

	/** Will pop an operand off the stack if possible.
	 *@param operand Integer& of operand to modify.
	 *@returns True if successful pop. */
	bool popOperand(int& operand);
};
