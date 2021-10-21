#include "Hourglass.h"
#include "Triangle.h"

const Vertex DEFAULT_UPPER_V0 = Vertex(20, 20),
			 DEFAULT_UPPER_V1 = Vertex(30, 20),
			 DEFAULT_UPPER_V2 = Vertex(25, 20 + sqrt(75)),
			 DEFAULT_LOWER_V0 = Vertex(25, 20 + sqrt(75)),
			 DEFAULT_LOWER_V1 = Vertex(20, 20 + 2*sqrt(75)),
			 DEFAULT_LOWER_V2 = Vertex(30, 20 + 2*sqrt(75));

//-----------------------------------------------------------------------------
Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
	: m_upper(upper), m_lower(lower)
{
	if (!isHourglassValid())
	{
		m_lower = Triangle(DEFAULT_LOWER_V0, DEFAULT_LOWER_V1, DEFAULT_LOWER_V2.m_row - DEFAULT_LOWER_V0.m_row);
		m_upper = Triangle(DEFAULT_UPPER_V0, DEFAULT_UPPER_V1, DEFAULT_UPPER_V2.m_row - DEFAULT_UPPER_V0.m_row);
	}
}

//-----------------------------------------------------------------------------
Hourglass::Hourglass(const Triangle& lower)
	: m_lower(lower),
   	m_upper(Triangle(Vertex(lower.getVertex(0).m_col, lower.getVertex(0).m_row + lower.getHeight()),
		             Vertex(lower.getVertex(1).m_col, lower.getVertex(1).m_row + lower.getHeight()),
		             lower.getHeight()))
{
	/*
	double new_v_row = lower.getVertex(0).m_row + lower.getHeight() * 2;
	Vertex point = lower.getVertex(2), // try to do it befor
    	   topLeft = Vertex(lower.getVertex(0).m_col, new_v_row),
		   topRight = Vertex(lower.getVertex(1).m_col , new_v_row);
	Vertex vertics[] = {topLeft, topRight, point};
	
	m_upper = Triangle(vertics);
	*/
	Hourglass(m_upper, lower);
}

bool Hourglass::isHourglassValid()
{
	return (m_lower.getLength() - m_upper.getLength() < 0.5
			&& m_lower.getVertex(2).m_col - m_upper.getVertex(2).m_col < 0.5
			&& m_lower.getVertex(2).m_row - m_upper.getVertex(2).m_row < 0.5
			&& m_lower.getVertex(0).isHigherThan(m_upper.getVertex(0)));
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
	Vertex centerLower = m_lower.getCenter(),
			centerUpper = m_upper.getCenter();

	double lengthX = (centerLower.m_col - m_lower.getVertex(0).m_col) * factor,
		   lengthY = (centerLower.m_row - m_lower.getVertex(0).m_row) * factor;
	
	Vertex lowerV0 = Vertex(centerLower.m_col - lengthX, centerLower.m_row - lengthY),
		   lowerV1 = Vertex(centerLower.m_col + lengthX, centerLower.m_row - lengthY),
		   upperV0 = Vertex(centerUpper.m_col - lengthX, centerUpper.m_row + lengthY), 
		   upperV1 = Vertex(centerUpper.m_col + lengthX, centerUpper.m_row + lengthY);

	if (factor < 0 || !lowerV0.isValid() || !lowerV1.isValid() || !upperV0.isValid() || !upperV1.isValid())
		return false;
	
	m_lower = Triangle(lowerV0, lowerV1, m_upper.getHeight() + lengthY);
	m_upper = Triangle(upperV0, upperV1, m_upper.getHeight() + lengthY);

	return true;
}