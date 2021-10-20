#include <cmath>
#include "Triangle.h"

const Vertex DEFAULT_V0 = Vertex(20, 20),
			 DEFAULT_V1 = Vertex(30, 20),
		     DEFAULT_V2 = Vertex(25, 20 + sqrt(75));

Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
	: m_v0(v0), m_v1(v1), m_v2(Vertex(v1.m_col, v1.m_row + height))
{
	if (!isTriangleValid())
	{
		m_v0 = DEFAULT_V0;
		m_v1 = DEFAULT_V1;
		m_v2 = DEFAULT_V2;
	}
};

Triangle::Triangle(const Vertex vertices[3]) 
	: Triangle(vertices[0], vertices[1], vertices[2].m_row - vertices[0].m_row)
{};

bool Triangle::isTriangleValid()
{
	return (m_v0.isValid() && m_v1.isValid() && m_v2.isValid() 
			&& m_v2.isToTheRightOf(m_v0) && m_v1.isToTheRightOf(m_v2)
			&& !m_v0.isHigherThan(m_v1)
			&& distance(m_v0, m_v2) - getLength() < 0.5 
		    && distance(m_v2, m_v1) - getLength() < 0.5);
}

double Triangle::distance(const Vertex& v0, const Vertex& v1) // todo 
{
	return sqrt(((v1.m_col - v0.m_col) * (v1.m_col - v0.m_col)) +
		((v1.m_row - v0.m_row) * (v1.m_row - v0.m_row)));
}

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
	return m_v2.m_row - m_v0.m_row;
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
	return Vertex(m_v1.m_col - m_v0.m_col, m_v2.m_row - m_v0.m_row);
}

bool Triangle::scale(double factor)
{
	Vertex center = getCenter();

	double length_x = (center.m_col - m_v0.m_col) * factor,
		   length_y = (center.m_row - m_v0.m_row) * factor;

	Vertex new_v0 = Vertex(center.m_col - length_x, center.m_row - length_y),
		   new_v1 = Vertex(center.m_col + length_x, center.m_row - length_y),
		   new_v2 = Vertex(center.m_col, center.m_row + length_y);

	if (factor < 0 || !new_v0.isValid() || !new_v1.isValid() || !new_v2.isValid())
		return false;

	m_v0 = new_v0;
	m_v1 = new_v1;
	m_v2 = new_v2;

	return true;
}
