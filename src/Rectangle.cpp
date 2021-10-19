#pragma once

#include "Rectangle.h"
#include "Board.h"
#include "Vertex.h"

const Vertex DEFAULT_BOTTOM_LEFT = Vertex(20,10),
			 DEFAULT_TOP_RIGHT = Vertex(20,30);

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
	//: m_bottomLeft(DEFAULT_BOTTOM_LEFT), m_topRight(DEFAULT_TOP_RIGHT)
{
	m_bottomLeft = bottomLeft;
	m_topRight = topRight;
}

Rectangle::Rectangle(const Vertex vertices[2])
	//: m_bottomLeft(DEFAULT_BOTTOM_LEFT), m_topRight(DEFAULT_TOP_RIGHT)
{
	m_bottomLeft = vertices[0];
	m_topRight = vertices[1];
}

/*
Rectangle(double x0, double y0, double x1, double y1)
{

}

Rectangle(const Vertex& start, double width, double height)
{

}
*/
// this function returns the bottom-left vertex of rectangle
Vertex Rectangle::getBottomLeft() const
{
	return m_bottomLeft;
}
//-----------------------------------------------------------------------------

// this function returns the top-right vertex of rectangle
Vertex Rectangle::getTopRight() const
{
	return m_topRight;
}
//-----------------------------------------------------------------------------

// this function returns rectangle width
double Rectangle::getWidth() const
{
	return m_topRight.m_col - m_bottomLeft.m_col;
}
//-----------------------------------------------------------------------------

// this function returns rectangle height
double Rectangle::getHeight() const
{
	return m_topRight.m_row - m_bottomLeft.m_row;
}
//-----------------------------------------------------------------------------

// this function draw the rectangle in board
void Rectangle::draw(Board& board) const
{
	Vertex topLeft = Vertex(m_bottomLeft_m_col, m_bottomLeft_m_row + getHeight()),
		   bottomRight = Vertex(m_bottomLeft_m_col + getWidth(), m_bottomLeft_m_row);

	board.drawLine(m_bottomLeft, topLeft);
	board.drawLine(m_bottomLeft, bottomRight);
	board.drawLine(m_topRight, topLeft);
	board.drawLine(m_topRight, bottomRight);
}
//-----------------------------------------------------------------------------

// this function draw the rectangle that blocks the original rectangle
Rectangle Rectangle::getBoundingRectangle() const
{
	return Rectangle(m_bottomLeft, m_topRight);
}
//-----------------------------------------------------------------------------

// this function returns rectangle area
double Rectangle::getArea() const
{
	return (getHeight() * getWidth());
}
//-----------------------------------------------------------------------------

// this function returns rectangle perimeter
double Rectangle::getPerimeter() const
{
	return ((2 * getHeight()) + (2 * getWidth()));
}
//-----------------------------------------------------------------------------

// this function returns rectangle center vertex
Vertex Rectangle::getCenter() const
{
	return Vertex(m_bottomLeft.m_col + getWidth() / 2, m_bottomLeft.m_row + getHeight() / 2);
}
//-----------------------------------------------------------------------------

// Documentation
bool Rectangle::scale(double factor)
{
	Vertex center = getCenter();

	double length_x = (center.m_col - m_bottomLeft.m_col) * factor,
	       length_y = (center.m_row - m_bottomLeft.m_row) * factor;

	Vertex new_bottomLeft = Vertex(center.m_col - length_x, center.m_row + length_y);
	Vertex new_topRight = Vertex(center.m_col - length_x, center.m_row - length_y);

	if (factor < 0 || !new_bottomLeft.isValid() || !new_topRight.isValid())
		return false;
	
	m_bottomLeft = new_bottomLeft;
	m_topRight = new_topRight;

	return true;
}
//-----------------------------------------------------------------------------
