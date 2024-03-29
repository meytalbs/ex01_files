#include "Rectangle.h"

//default value to rectangle
const Vertex DEFAULT_BOTTOM_LEFT = Vertex(20, 10),	
			 DEFAULT_TOP_RIGHT = Vertex(30, 20);


Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
	: m_bottomLeft(bottomLeft), m_topRight(topRight)
{
	//if rectangle isnt valid set default values
	if (!isRectangleValid(bottomLeft, topRight))	
	{
		m_bottomLeft = DEFAULT_BOTTOM_LEFT;
		m_topRight = DEFAULT_TOP_RIGHT;
	}
}
//-----------------------------------------------------------------------------

//this c-tor uses first c-tor to build rectangle
Rectangle::Rectangle(const Vertex vertices[2])
	: Rectangle(vertices[0], vertices[1])
{}
//-----------------------------------------------------------------------------

//this c-tor uses first c-tor to build rectangle
Rectangle::Rectangle(double x0, double y0, double x1, double y1)
	: Rectangle(Vertex(x0, y0), Vertex(x1, y1))
{}
//-----------------------------------------------------------------------------

//this c-tor uses first c-tor to build rectangle
Rectangle::Rectangle(const Vertex& start, double width, double height)
	: Rectangle(start, Vertex(start.m_col + width, start.m_row + height))
{}
//-----------------------------------------------------------------------------

//validate the rectangle value and return if valid
bool Rectangle::isRectangleValid(const Vertex& v1, const Vertex& v2)
{
	return (v1.isValid() && v2.isValid() && v2.isToTheRightOf(v1) && v2.isHigherThan(v1));
}
//-----------------------------------------------------------------------------

// this function returns the bottom-left vertex of rectangle
Vertex Rectangle::getBottomLeft() const
{
	return m_bottomLeft;
}
//------------------------------------------------------------------------------

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
	//creates top left and bottom right vertexs
	Vertex topLeft = Vertex(m_bottomLeft.m_col, m_bottomLeft.m_row + getHeight()),
		   bottomRight = Vertex(m_bottomLeft.m_col + getWidth(), m_bottomLeft.m_row);

	board.drawLine(m_bottomLeft, topLeft);
	board.drawLine(topLeft, m_topRight);
	board.drawLine(m_topRight, bottomRight);
	board.drawLine(bottomRight, m_bottomLeft);
}
//-----------------------------------------------------------------------------

// this function returns the rectangle that blocks the original rectangle
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

// scales rectangle by factor and relative to the center vertex
bool Rectangle::scale(double factor)
{
	Vertex center = getCenter();

	//new length from center to vertex
	double lengthX = (center.m_col - m_bottomLeft.m_col) * factor,
	       lengthY = (center.m_row - m_bottomLeft.m_row) * factor;

	//new potenital vertexs (if they are valid)
	Vertex newBottomLeft = Vertex(center.m_col - lengthX, center.m_row - lengthY);
	Vertex newTopRight = Vertex(center.m_col + lengthX, center.m_row + lengthY);

	if (factor < 0 || !newBottomLeft.isValid() || !newTopRight.isValid())
		return false;
	
	m_bottomLeft = newBottomLeft;
	m_topRight = newTopRight;

	return true;
}
//-----------------------------------------------------------------------------
