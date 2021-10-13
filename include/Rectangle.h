#pragma once

#include "Vertex.h"

class Rectangle 
{
public: // ask if all of them need to be in public
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight); // ask why do we have 4 Rectangle ? 
	Rectangle(const Vertex vertices[2])
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& start, double width, double height);
	
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getWidth() const;
	double getHeight() const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor)

private:
	Vertex m_bottomLeft;
	Vertex m_topRight;
	Vertex getVertex;
};
