// Programmer:			Ryan Riccio
// Project number:		6
// Project Desc:		List ADT
// Course:              COSC 2436 PF III Data Structures
// Date:				Oct 17th, 2021

// ArrayList example driver
// This is not a thorough test of the class, but it exercises all class methods.

#include <iostream>
#include <string>

#include "LinkedList.h" // ADT list operations
using namespace std;

// anonymous namespace because both drivers are in the same folder so displayList and testCopyConstructor
// are only in this module.
namespace
{
	void displayList(ListInterface<std::string>* listPtr)
	{
		if (listPtr->isEmpty())
			cout << "The list is empty" << endl;
		else
		{	// if not empty, loop through list and print entries
			cout << "The list contains " << endl;
			for (int pos = 1; pos <= listPtr->getLength(); pos++)
			{
				try
				{
					std::cout << listPtr->getEntry(pos) << " ";
				}
				catch (PrecondViolatedExcep except)
				{
					std::cout << "Exception thrown getting entry inserted at position " << pos << std::endl;
					std::cout << except.what() << std::endl;
				}
			}
			cout << endl;
		}
	}
	void testCopyConstructor(ListInterface<std::string>* oldListPtr, ListInterface<std::string>* newListPtr)
	{
		// display both lists
		cout << "Old List Address: " << oldListPtr << '\t' << "New List Address: " << newListPtr << endl;
		cout << "\n[OLD List] ";
		displayList(oldListPtr);
		cout << "[NEW List] ";
		displayList(newListPtr);
		cout << "\nReplacing (using replace()) first entry of new list with 'twenty'..." << endl;

		try
		{	// try to replace item
			newListPtr->replace(1, "twenty");
		}
		catch (PrecondViolatedExcep except)
		{
			std::cout << "Exception thrown getting entry inserted at position 1" << std::endl;
			std::cout << except.what() << std::endl;
		}

		// display lists after replacement
		cout << "\n[OLD List] ";
		displayList(oldListPtr);
		cout << "[NEW List] ";
		displayList(newListPtr);
	}
}

int main()
{
	cout << "LinkedList Driver\n\n";

	ListInterface<std::string>* listPtr = new LinkedList<std::string>();

	cout << "List should be empty" << endl;;
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;

	// test insert
	listPtr->insert(1, "two");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 1" << endl << endl;

	listPtr->insert(1, "one");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;

	listPtr->insert(3, "three");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;

	listPtr->insert(3, "two.five");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;

	listPtr->insert(5, "five");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;

	// test contains
	cout << "Contains 'three': " << (listPtr->contains("three") ? "true" : "false") << "; should be true\n";
	cout << "Contains 'thirty': " << (listPtr->contains("thirty") ? "true" : "false") << "; should be false\n\n";

	// test copy constructor
	// LinkedList copy constructor can take any ListInterface (LinkedList or ArrayList)
	// create a new list copied from listPtr
	ListInterface<std::string>* newListPtr = new LinkedList<std::string>(*listPtr);
	testCopyConstructor(listPtr, newListPtr);

	// test remove
	cout << "\nRemove first entry" << endl;
	listPtr->remove(1);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;

	cout << "Remove last entry" << endl;
	listPtr->remove(4);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;

	cout << "Remove remaining entries" << endl;
	listPtr->remove(1);
	listPtr->remove(1);
	listPtr->remove(1);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;

	cout << "Try to remove entry from empty list" << endl;
	if (listPtr->remove(1))
		cout << "Removed an entry" << endl << endl;
	else
		cout << "Cannot remove entry" << endl << endl;

	// test clear
	cout << "Testing clear method" << endl;
	cout << "Inserting one" << endl;
	listPtr->insert(1, "one");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 1" << endl << endl;

	cout << "Inserting two" << endl;
	listPtr->insert(2, "two");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;

	cout << "Clearing list" << endl;
	listPtr->clear();
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;


	return 0;
}  // end main