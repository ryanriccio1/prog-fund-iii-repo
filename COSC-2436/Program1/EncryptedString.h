#pragma once
#include <string>

class EncryptedString 
{
public:
	EncryptedString();					// default constructor
	EncryptedString(std::string str);	// constructor with string
	void set(std::string str);			// encrypts string
	std::string get() const;			// decrypts string
	std::string getEncrypted() const;	// returns encryptedStr

private:
	std::string encryptedStr;
};