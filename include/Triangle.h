#pragma once

#include "Vertex.h"  // ask - where do we need to put the includes
#include "Board.h"
#include "Rectangle.h"

class Triangle
{
public:
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& v0, const Vertex& v1, double height);

	Vertex getVertex(int index) const;
	double getLength() const;
	double getHeight() const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	Vertex m_v0;
	Vertex m_v1;
	Vertex m_v2;
};
