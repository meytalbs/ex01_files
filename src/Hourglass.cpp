#include "Hourglass.h"
#include "Triangle.h"
#include <iostream>

const Vertex DEFAULT_LOWER_V0 = Vertex(20, 20),
			DEFAULT_LOWER_V1 = Vertex(30, 20),
			DEFAULT_LOWER_V2 = Vertex(25, 20 + sqrt(75)),
			DEFAULT_UPPER_V0 = Vertex(25, 20 + sqrt(75)),
			DEFAULT_UPPER_V1 = Vertex(20, 20 + 2 * sqrt(75)),
			DEFAULT_UPPER_V2 = Vertex(30, 20 + 2 * sqrt(75));

//-----------------------------------------------------------------------------
Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
	:m_upper(upper), m_lower(lower)
{
	if (!isHourglassValid(lower, upper))
	{
		m_lower = Triangle(DEFAULT_LOWER_V0, DEFAULT_LOWER_V1, DEFAULT_LOWER_V2.m_row - DEFAULT_LOWER_V0.m_row);
		m_upper = Triangle(DEFAULT_UPPER_V0, DEFAULT_UPPER_V1, -(DEFAULT_UPPER_V2.m_row - DEFAULT_UPPER_V0.m_row));
	}
}

//-----------------------------------------------------------------------------
Hourglass::Hourglass(const Triangle& lower)
	:Hourglass(Triangle(DEFAULT_UPPER_V0, DEFAULT_UPPER_V1, -(DEFAULT_UPPER_V0.m_row - DEFAULT_UPPER_V2.m_row)),
				Triangle(DEFAULT_LOWER_V0, DEFAULT_LOWER_V1, DEFAULT_LOWER_V2.m_row - DEFAULT_LOWER_V0.m_row))
{
	double new_vertex_y = lower.getVertex(0).m_row + lower.getHeight() * 2;

	Vertex topLeft = Vertex(lower.getVertex(0).m_col, new_vertex_y),
			topRight = Vertex(lower.getVertex(1).m_col, new_vertex_y);

	Triangle temp_upper = Triangle(topLeft, topRight, lower.getHeight());
	if (isHourglassValid(lower, temp_upper))
	{
		m_lower = lower;
		m_upper = temp_upper;
	}
}

//-----------------------------------------------------------------------------
bool Hourglass::isHourglassValid(Triangle lower, Triangle upper)
{
	return (lower.getLength() - upper.getLength() < 0.5
			&& lower.getVertex(2).m_col - upper.getVertex(2).m_col < 0.5
			&& lower.getVertex(2).m_row - upper.getVertex(2).m_row < 0.5
			&& upper.getVertex(0).isHigherThan(lower.getVertex(0)));
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
	Vertex bottomLeft = m_lower.getVertex(0),
		bottomRight = m_lower.getVertex(1),
		topLeft = m_upper.getVertex(0),
		topRight = m_upper.getVertex(1);

	board.drawLine(bottomLeft, bottomRight);
	board.drawLine(bottomLeft, topRight);
	board.drawLine(topLeft, topRight);
	board.drawLine(topLeft, bottomRight);
}

//-----------------------------------------------------------------------------
Rectangle Hourglass::getBoundingRectangle() const
{
	return Rectangle(m_lower.getVertex(0), m_upper.getVertex(1));
}

//-----------------------------------------------------------------------------
double Hourglass::getArea() const
{
	return m_lower.getArea() + m_upper.getArea();
}

//-----------------------------------------------------------------------------
double Hourglass::getPerimeter() const
{
	return m_lower.getPerimeter() + m_upper.getPerimeter();
}

//-----------------------------------------------------------------------------
Vertex Hourglass::getCenter() const
{
	return m_lower.getVertex(2);
}

//-----------------------------------------------------------------------------
bool Hourglass::scale(double factor)
{
	Vertex center = getCenter();

	double lengthX = (center.m_col - m_lower.getVertex(0).m_col) * factor,
		lengthY = (center.m_row - m_lower.getVertex(0).m_row) * factor;

	Vertex lowerV0 = Vertex(center.m_col - lengthX, center.m_row - lengthY),
		lowerV1 = Vertex(center.m_col + lengthX, center.m_row - lengthY),
		upperV0 = Vertex(center.m_col - lengthX, center.m_row + lengthY),
		upperV1 = Vertex(center.m_col + lengthX, center.m_row + lengthY);

	if (factor < 0 || !lowerV0.isValid() || !lowerV1.isValid() || !upperV0.isValid() || !upperV1.isValid())
		return false;

	m_lower = Triangle(lowerV0, lowerV1, center.m_row - lowerV0.m_row);
	m_upper = Triangle(upperV0, upperV1, center.m_row - lowerV0.m_row);

	return true;
}
