/** @file PostfixCalculator.cpp */

#include "PostfixCalculator.h"

// default constructor to init result to INT_MAX as sentinel
PostfixCalculator::PostfixCalculator() : result(INT_MAX) {}

// if constructor gets a value, automatically calculate. INT_MAX as sentinel
PostfixCalculator::PostfixCalculator(const string& postfixExpression) : result(INT_MAX), postfixExpression(postfixExpression)
{
	calculate();
}

int PostfixCalculator::getResult() const
{	// getter
	return result;
}

string PostfixCalculator::getError() const
{	// getter
	return errorMessage;
}

bool PostfixCalculator::isOperator(const char& character)
{	// check if char in list of valid characters
	if (character == '+' ||
		character == '-' ||
		character == '*' ||
		character == '/')
		return true;
	return false;
}

void PostfixCalculator::calculate()
{	// iterate over each character in postfixExpression and pull
	// char for each iteration
	for (const char character : postfixExpression)
	{	// if char is space, do nothing
		if (character == ' ')
			continue;

		// if its an operator, perform operation, otherwise push operand
		if (isOperator(character))
		{
			int operand1;
			int operand2;

			// try to pop and validate operands , give error if either fails
			// popOperand modifies operand passed by reference
			if (!popOperand(operand2) || !popOperand(operand1))
			{
				errorMessage = "Malformed Expression: Unexpected operator.";
				return;
			}
			switch (character)
			{	// perform operation with given operator
			case '+': stack.push(operand1 + operand2); break;
			case '-': stack.push(operand1 - operand2); break;
			case '*': stack.push(operand1 * operand2); break;
			case '/': stack.push(operand1 / operand2); break;
			default: break;
			}
		}
		else if (character >= '0' && character <= '9')
		{	// cast char to int - ASCII 48 ('0') then push
			const int operand = static_cast<int>(character) - '0';
			stack.push(operand);
		}
	}
	// If popOperand succeeds, the stack is not empty
	result = stack.peek();

	// if there is more than 1 value in stack at end of calculation
	// The calculation was malformed. Remove result and if it is not empty
	// An error has occurred
	stack.pop();
	if (!stack.isEmpty())
		errorMessage = "Malformed Expression: Too many operands.";
}

bool PostfixCalculator::popOperand(int& operand)
{
	// make sure stack is not empty
	if (!stack.isEmpty())
	{	// set operands then pop
		operand = stack.peek();
		stack.pop();
		return true;	// return success
	}
	return false;
}
