// Programmer:			Ryan Riccio
// Project number:		2
// Project Desc:		Quadratic Expression class (RectangleInterface)
// Course:              COSC 2436 PF III Data Structures
// Date:				Sept 12th, 2021

/** @file driver.cpp */
#include "Rectangle.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	size_t numLoop = 4;
	double startVal = -1.0;
	for (int baseNum = 0; baseNum < numLoop; baseNum++)
	{
		Rectangle rectangle = Rectangle();
		cout << "Rectangle Test #" << baseNum + 1 << endl;
		cout << "\t(Init) Length: " << rectangle.getLength() << endl;
		cout << "\t(Init) Width: " << rectangle.getWidth() << endl;
		cout << "\t(Test) Length: " << startVal + baseNum << endl;
		cout << setprecision(4) << "\t(Test) Width: " << (startVal + baseNum) * 2 / 3 << endl; // *2/3 is just to give new numbers to test
		if (rectangle.set(startVal + baseNum, ((startVal + baseNum) * 2 / 3))) 
		{	// try to set
			cout << "Success!\n";
			cout << "Area: " << setprecision(4) << rectangle.getArea() << endl << endl;
		}
		else
		{	// if fail to set
			cout << "Error! Values less than 0!\n\n";
		}
	}
}