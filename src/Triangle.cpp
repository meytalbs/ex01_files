#include <cmath>
#include "Triangle.h"
#include "Utilities.h"

//default triangle vertexs
const Vertex DEFAULT_V0 = Vertex(20, 20),			
			 DEFAULT_V1 = Vertex(30, 20),
		     DEFAULT_V2 = Vertex(25, 20 + sqrt(75));


//c-tor from 2 vertexs and height
Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
	: m_v0(v0), m_v1(v1), m_v2(Vertex((v0.m_col + v1.m_col) /2, v0.m_row + height))
{
	//if triangle isnt valid assign default values
	if (!isTriangleValid()) 
	{
		m_v0 = DEFAULT_V0;
		m_v1 = DEFAULT_V1;
		m_v2 = DEFAULT_V2;
	}
};
//-----------------------------------------------------------------------------

//
Triangle::Triangle(const Vertex vertices[3]) 
	: Triangle(vertices[0], vertices[1], vertices[2].m_row - vertices[0].m_row)
{};
//-----------------------------------------------------------------------------

bool Triangle::isTriangleValid()
{
	return (m_v0.isValid() && m_v1.isValid() && m_v2.isValid()
		&& m_v2.isToTheRightOf(m_v0) && m_v1.isToTheRightOf(m_v2)
		&& !m_v0.isHigherThan(m_v1)
		&& doubleEqual(distance(m_v0, m_v2), getLength())
		&& doubleEqual(distance(m_v2, m_v1), getLength()));
}
//-----------------------------------------------------------------------------

Vertex Triangle::getVertex(int index) const
{
	if (index == 0)
		return m_v0;
	else if (index == 1)
		return m_v1;
	else
		return m_v2;
}
//-----------------------------------------------------------------------------

// this function returns triangular rib length
double Triangle::getLength() const
{
	return m_v1.m_col - m_v0.m_col;
}
//-----------------------------------------------------------------------------

// this function returns the height of triangle
double Triangle::getHeight() const
{
	return  m_v2.m_row - m_v0.m_row;
}
//-----------------------------------------------------------------------------

// this function draw a triangle in board
void Triangle::draw(Board& board) const
{
	board.drawLine(m_v0, m_v1);
	board.drawLine(m_v1, m_v2);
	board.drawLine(m_v2, m_v0);
}
//-----------------------------------------------------------------------------

Rectangle Triangle::getBoundingRectangle() const
{
	return Rectangle(Vertex(m_v0.m_col, std::min(m_v0.m_row, m_v2.m_row)),
					 Vertex(m_v1.m_col, std::max(m_v1.m_row, m_v2.m_row))); 
}
//-----------------------------------------------------------------------------

double Triangle::getArea() const
{
	return abs((getHeight() * getLength()) / 2);
}
//-----------------------------------------------------------------------------

double Triangle::getPerimeter() const
{
	return 3 * getLength();
}
//-----------------------------------------------------------------------------

Vertex Triangle::getCenter() const
{
	return Vertex(m_v2.m_col, m_v0.m_row + (getHeight() / 3));
}
//-----------------------------------------------------------------------------

bool Triangle::scale(double factor)
{
	Vertex center = getCenter();
	double lengthX = (center.m_col - m_v0.m_col) * factor,
		lengthY = (center.m_row - m_v0.m_row) * factor;

	Vertex 
		newV0 = Vertex(center.m_col - lengthX, center.m_row - lengthY),
		newV1 = Vertex(center.m_col + lengthX, center.m_row - lengthY),
		newV2 = Vertex(center.m_col, center.m_row + lengthY);

	if (factor < 0 || !newV0.isValid() || !newV1.isValid() || !newV2.isValid())
		return false;	
	
	m_v0 = newV0;
	m_v1 = newV1;
	m_v2 = newV2;

	return true;
}
//-----------------------------------------------------------------------------
