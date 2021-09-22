/** @file RectangleInterface.h */
#pragma once

class RectangleInterface
{
public:
	/** Updates length and width of the Rectangle
	@param	newLength	the new length for the Rectangle
	@param	newWidth	the new width for the Rectangle
	@pre    newLength and newWidth must be greater than 0.0
	@post   If newLength and newWidth are valid, the radius
			of this object is set to these values
			Otherwise, the Rectangle is not updated
	@return True if this object is updated,
			and false otherwise. */
	virtual bool set(double newLength, double newWidth) = 0;
	
	/** Gets the length of the Rectangle
	@return The length of the Rectangle. */
	virtual double getLength() const = 0;

	/** Gets the width of the Rectangle
	@return The width of the Rectangle. */
	virtual double getWidth() const = 0;

	/** Gets the area of this Rectangle
	@return The area of this Rectangle. */
	virtual double getArea() const = 0;

	/** Destroys this Circle and frees its assigned memory. */
	virtual ~RectangleInterface() {}
};