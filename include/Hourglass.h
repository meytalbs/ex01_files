#pragma once

#include "Triangle.h"
#include "Vertex.h"

class Hourglass
{
public: 
	Hourglass(const Triangle& upper, const Triangle& lower);	//c-tor with 2 triangles
	Hourglass(const Triangle& lower);							//c-tor with lower triangle

	double getLength() const;
	double getHeight() const;
	
	void draw(Board& board) const;								//draws hourglass
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);									//scales hourglass by factor

private:
	Triangle m_upper,
		     m_lower;
	bool isHourglassValid(Triangle lower, Triangle upper);
};