/** @file Rectangle.cpp*/
#include "Rectangle.h"

Rectangle::Rectangle()
{	// set default values
	length = 1.0;
	width = 1.0;
}
Rectangle::Rectangle(double newLegnth, double newWidth)
{	// if values are given at construction, run them through set algorithm
	set(newLegnth, newWidth);
}
bool Rectangle::set(double newLength, double newWidth)
{
	if (newLength > 0.0 && newWidth > 0.0)
	{	// if possible number return true
		length = newLength;
		width = newWidth;
		return true;
	}
	else
	{	// if impossible number
		return false;
	}
}
double Rectangle::getLength() const
{
	return length;
}
double Rectangle::getWidth() const
{
	return width;
}
double Rectangle::getArea() const
{
	return length * width;
}