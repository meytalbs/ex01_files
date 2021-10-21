#pragma once

#include "Board.h"
#include "Vertex.h"

class Rectangle 
{
public:
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);	//c-tor 2 vertex
	Rectangle(const Vertex vertices[2]);							//c-tor 2 vertex in array
	Rectangle(double x0, double y0, double x1, double y1);			//c-tor with 4 coordinates
	Rectangle(const Vertex& start, double width, double height);	//c-tor with vertex + height & width

	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getWidth() const;
	double getHeight() const;

	void draw(Board& board) const;									//draws rectangle
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);										//scales rectangle by factor

private:
	Vertex m_bottomLeft;
	Vertex m_topRight;
	bool isRectangleValid(const Vertex& v1, const Vertex& v2);		//checks if rectangle is valid
};
