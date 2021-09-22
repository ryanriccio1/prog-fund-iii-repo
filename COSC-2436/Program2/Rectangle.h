/** @file Rectangle.h */
#pragma once
#include "RectangleInterface.h"

class Rectangle : public RectangleInterface
{
public:
	Rectangle();
	Rectangle(double newLength, double newWidth);
	bool set(double newLength, double newWidth);
	double getLength() const;
	double getWidth() const;
	double getArea() const;

private:
	double length;
	double width;
};