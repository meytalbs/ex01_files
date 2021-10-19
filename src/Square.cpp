#include "Square.h"


Square::Square(const Vertex& bottomLeft, const Vertex& topRight)
    :m_bottomLeft(bottomLeft), m_topRight(topRight)
{}

Square::Square(const Vertex& start, double length)
    : Square(start, Vertex(start.m_col + m_length, start.m_row + m_length))
{}

//-----------------------------------------------------------------------------
Vertex Square::getBottomLeft() const
{
    return m_bottomLeft;
}

//-----------------------------------------------------------------------------
Vertex Square::getTopRight() const
{
    return m_topRight;
}

//-----------------------------------------------------------------------------
double Square::getLength() const
{
    return m_length;
}

//-----------------------------------------------------------------------------
void Square::draw(Board& board) const
{
    Vertex topLeft = Vertex(m_bottomLeft.m_col, m_topRight.m_row),
        bottomRight = Vertex(m_bottomLeft.m_row, m_topRight.m_col);

    board.drawLine(m_bottomLeft, bottomRight);
    board.drawLine(m_bottomLeft, topLeft);
    board.drawLine(topLeft, m_topRight);
    board.drawLine(bottomRight, m_topRight);
}

//-----------------------------------------------------------------------------
Rectangle Square::getBoundingRectangle() const
{
    return Rectangle(m_bottomLeft, m_topRight);
}

//-----------------------------------------------------------------------------
double Square::getArea() const
{
    return m_length * m_length;
}

//-----------------------------------------------------------------------------
double Square::getPerimeter() const
{
    return m_length * 4;
}   

//-----------------------------------------------------------------------------
Vertex Square::getCenter() const
{
    return Vertex(m_bottomLeft.m_col + m_length / 2, m_bottomLeft.m_row + m_length / 2)
}

//-----------------------------------------------------------------------------
bool Square::scale(double factor)
{
    if (factor < 0)
        return false;

    Vertex center = getCenter();

    double new_x = center.m_col - (factor * (center.m_col - m_bottomLeft.m_col)),
            new_y = center.m_row - (factor * (center.m_row - m_bottomLeft.m_row));

    Vertex new_bottomLeft = Vertex(new_x, new_y);

    new_x = center.m_col - (factor * (center.m_col - m_topRight.m_col));
    new_y = center.m_row - (factor * (center.m_row - m_topRight.m_row));

    Vertex new_topRight = Vertex(new_x, new_y);

    if (!new_bottomLeft.isValid() || !new_topRight.isValid())
        return false;
    
    m_bottomLeft = new_bottomLeft;
    m_topRight = new_topRight;

    return true;
}