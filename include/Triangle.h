#pragma once

#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"

class Triangle
{
public:
	Triangle(const Vertex vertices[3]);								//c-tor with 3 vetexs array
	Triangle(const Vertex& v0, const Vertex& v1, double height);	//c-tor with 2 vertex & height

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
	bool isTriangleValid();										//checks if triangle is valid
};
