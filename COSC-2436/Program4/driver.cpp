// Programmer:			Ryan Riccio
// Project number:		4
// Project Desc:		Linked Bag
// Course:              COSC 2436 PF III Data Structures
// Date:				Oct 9th, 2021


/** @file driver.cpp */

#include <cstdlib>	// for rand/srand()
#include <ctime>	// for rand seed
#include <iostream>
#include <string>

#include "LinkedBag.h"
using namespace std;

void display(LinkedBag<string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize()
		<< " items:" << endl;
	vector<string> bagItems = bag.toVector();

	int numberOfEntries = static_cast<int>(bagItems.size());
	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}  // end for
	cout << endl << endl;
}  // end displaySet

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));	// set random seed

	LinkedBag<string> bag;
	cout << "Testing array-based Set:" << endl;
	cout << "The initial bag is empty." << endl;
	cout << "isEmpty: returns " << bag.isEmpty()
		<< "; should be 1 (true)" << endl;
	display(bag);

	string items[] = { "one", "two", "three", "four", "one" };
	cout << "Add 5 items to the bag: " << endl;
	for (int i = 0; i < 5; i++)
	{
		bag.add(items[i]);
	}  // end for

	display(bag);

	cout << "isEmpty: returns " << bag.isEmpty()
		<< "; should be 0 (false)" << endl;

	cout << "getCurrentSize: returns " << bag.getCurrentSize()
		<< "; should be 5" << endl;

	cout << "contains(\"three\"): returns " << bag.contains("three")
		<< "; should be 1 (true)" << endl;
	cout << "remove(\"two\"): returns " << bag.remove("two")
		<< "; should be 1 (true)" << endl;
	cout << "remove(\"two\"): returns " << bag.remove("two")
		<< "; should be 0 (false)" << endl;
	cout << endl;

	display(bag);

	cout << "remove(): returns " << bag.remove()
		<< "; should be 1 (true)" << endl;
	cout << endl;

	display(bag);

	cout << "After clearing the bag, ";
	bag.clear();

	cout << "isEmpty: returns " << bag.isEmpty()
		<< "; should be 1 (true)" << endl;

	return 0;
}  // end main
