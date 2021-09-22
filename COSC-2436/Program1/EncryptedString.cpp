#include "EncryptedString.h"


EncryptedString::EncryptedString()	// initializes with no data
{
	encryptedStr = "";
}

EncryptedString::EncryptedString(std::string str)	// encrypts at init
{
	set(str);
}

void EncryptedString::set(std::string str)
{	// loop through each char in string
	for (int currentCharIndex = 0; currentCharIndex < str.length(); currentCharIndex++)
	{
		char currentChar = str[currentCharIndex];
		// NOTE!: will not properly encrypt "!" and will leave spaces as spaces
		if (currentChar != ' ')
		{
			// wrap around capital/lowercase A
			if (currentChar == 'A')
			{
				encryptedStr += 'Z';
			}
			else if (currentChar == 'a')
			{
				encryptedStr += 'z';
			}
			else 
			{	// append modified char to encryptedStr
				encryptedStr += (currentChar - 1);
			}
		}
		else
		{
			encryptedStr += ' ';
		}
	}
}

std::string EncryptedString::get() const
{	// loop through each char in encryptedString
	std::string decryptedStr = "";
	for (int currentCharIndex = 0; currentCharIndex < encryptedStr.length(); currentCharIndex++)
	{
		char currentChar = encryptedStr[currentCharIndex];
		if (currentChar != ' ')
		{	// wrap around capital/lowercase Z
			if (currentChar == 'Z')
			{
				decryptedStr += 'A';
			}
			else if (currentChar == 'z')
			{
				decryptedStr += 'a';
			}
			else
			{	// append modified char to decryptedStr
				decryptedStr += (currentChar + 1);
			}
		}
		else
		{
			decryptedStr += ' ';
		}
	}
	// return decryptedStr after modification
	return decryptedStr;
}

std::string EncryptedString::getEncrypted() const	// for debugging purposes and proper OOP
{
	return encryptedStr;
}