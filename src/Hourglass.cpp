#include "Hourglass.h"

//-----------------------------------------------------------------------------
Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
	:m_upper(upper), m_lower(lower)
{
	
}

//-----------------------------------------------------------------------------
Hourglass::Hourglass(const Triangle& lower)
{
	double new_v_row = lower.getVertex(0).m_row + lower.getHeight() * 2;
	Vertex point = lower.getVertex(2),
		topLeft = Vertex(lower.getVertex(0).m_col, new_v_row),
		topRight = Vertex(lower.getVertex(1).m_col , new_v_row);

	Vertex vertics[] = {topLeft, topRight, point};
	Triangle(vertics);
}

//-----------------------------------------------------------------------------
double Hourglass::getLength() const
{
	return m_lower.getLength();
}

//-----------------------------------------------------------------------------
double Hourglass::getHeight() const
{
	return m_lower.getHeight() * 2;
}

//-----------------------------------------------------------------------------
void Hourglass::draw(Board& board) const
{
	m_lower.draw(board);
	m_upper.draw(board);
}

//-----------------------------------------------------------------------------
//the 2nd vertex may be 1 cause its upside down
Rectangle Hourglass::getBoundingRectangle() const
{
	return Rectangle(m_lower.getVertex(0), m_upper.getVertex(2));
}

//-----------------------------------------------------------------------------
double Hourglass::getArea() const
{
	return m_lower.getArea() + m_upper.getArea();
}

//-----------------------------------------------------------------------------
double Hourglass::getPerimeter() const
{
	m_lower.getPerimeter() + m_upper.getPerimeter();
}

//-----------------------------------------------------------------------------
Vertex Hourglass::getCenter() const
{
	return m_lower.getVertex(2);
}

//-----------------------------------------------------------------------------
bool Hourglass::scale(double factor)
{

}