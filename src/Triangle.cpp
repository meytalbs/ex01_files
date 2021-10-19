#include "Triangle.h"
#include "Rectangle.h"

/*

Triangle::Triangle(const Vertex vertices[3]) 
	: m_v0(vertices[0]), m_v1(vertices[1]), m_v2(vertices[2])
{};

Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
	: m_v0(v0), m_v1(v1), m_v2(v1)
{};

Vertex Triangle::getVertex(int index) const
{
	if (index == 0)
		return m_v0;
	else if (index == 1)
		return m_v1;
	else
		return m_v2;
}

// this function returns triangular rib length
double Triangle::getLength() const
{
	return m_v1.m_col - m_v0.m_col;
}

// this function returns the height of triangle
double Triangle::getHeight() const
{
	return m_v3.m_row - m_v0.m_row;
}

// this function draw a triangle in board
void Triangle::draw(Board& board) const
{
	board.drawLine(m_v0, m_v1);
	board.drawLine(m_v0, m_v2);
	board.drawLine(m_v1, m_v2);
}

Rectangle Triangle::getBoundingRectangle() const
{
	Vertex topRight = Vertex(m_v1.m_col, m_v1.m_row + getHeight());

	return Rectangle(m_v0, topRight);
}

double Triangle::getArea() const
{
	return (getHeight() * getLength() / 2);
}

double Triangle::getPerimeter() const
{
	return 3 * getLength();
}

Vertex Triangle::getCenter() const
{
	return Vertex(m_v1.m_col - m_v0.m_col, m_v2.row - m_v0.m_row);
}

bool Triangle::scale(double factor)
{

}
*/