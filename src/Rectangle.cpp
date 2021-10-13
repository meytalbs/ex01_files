#include "Rectangle.h"
#include "Board.h"

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
double Rectangle::getWidth() const   // ask which way is better
{
	/*
	double x1, x2;

	x1 = m_bottomLeft.m_col;
	x2 = m_topRight.m_col;
	*/
	return m_topRight.m_col - m_bottomLeft.m_col;
}
//-----------------------------------------------------------------------------

// this function returns rectangle height
double Rectangle::getHeight() const
{
	return m_topRight.m_row - m_bottomLeft.m_row;
}
//-----------------------------------------------------------------------------

// this function returns rectangle center vertex
Vertex Rectangle::getCenter() const
{
	return getVertex(m_bottomLeft, getWidth() / 2, getHeight() / 2); 
}
//-----------------------------------------------------------------------------

// this function draw the rectangle in board
void Rectangle::draw(Board& board) const
{
	Vertex topLeft = getVertex(m_bottomLeft, 0, getHeight()),
		   bottomRight = getVertex(m_bottomLeft, getWidth(), 0);

	drawLine(m_bottomLeft, topLeft);
	drawLine(m_bottomLeft, bottomRight);
	drawLine(m_topRight, topLeft);
	drawLine(m_topRight, bottomRight);
}
//-----------------------------------------------------------------------------

// Documentation
Rectangle getBoundingRectangle() const;
//-----------------------------------------------------------------------------

// Documentation
double getArea() const;
//-----------------------------------------------------------------------------

// Documentation
double getPerimeter() const;
//-----------------------------------------------------------------------------

// Documentation
bool scale(double factor)
//-----------------------------------------------------------------------------



// this function get vertex length in x and length in y to add to vertex
// and returns the result
Vertex Rectangle::getVertex(Vertex v, double x_val, double y_val) // ask about func location (which file)
{
	Vertex temp;	// for temp vertex

	temp.m_col = v.m_col + x_val;
	temp.m_row = v.m_row + y_val;

	return temp;
}
//-----------------------------------------------------------------------------
