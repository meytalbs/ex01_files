#pragma once

#include "Vertex.h"

class Square
{
public:
	Square(const Vertex& bottomLeft, const Vertex& topRight);
	Square(const Vertex& start, double length);
	
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getLength() const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor)

private:

};