#include "Square.h"

//default value to square
const Vertex DEFAULT_BOTTOM_LEFT = Vertex(20, 10),
             DEFAULT_TOP_RIGHT = Vertex(30, 20);


//c-tor builds square using two vertexs
Square::Square(const Vertex& bottomLeft, const Vertex& topRight)
    :m_square(Rectangle(bottomLeft, topRight))
{}
//-----------------------------------------------------------------------------

//todo validate length of square equale
//uses 2 vertexs c-tor
Square::Square(const Vertex& start, double length)
    : Square(start, Vertex(start.m_col + length, start.m_row + length))
{}
//-----------------------------------------------------------------------------

Vertex Square::getBottomLeft() const
{
    return m_square.getBottomLeft();
}
//-----------------------------------------------------------------------------

Vertex Square::getTopRight() const
{
    return m_square.getTopRight();
}
//-----------------------------------------------------------------------------

double Square::getLength() const
{
    return m_square.getHeight();
}
//-----------------------------------------------------------------------------

//draws square in board
void Square::draw(Board& board) const
{
    m_square.draw(board);
}
//-----------------------------------------------------------------------------

Rectangle Square::getBoundingRectangle() const
{
    return m_square;
}
//-----------------------------------------------------------------------------

double Square::getArea() const
{
    return m_square.getArea();
}
//-----------------------------------------------------------------------------

double Square::getPerimeter() const
{
    return getLength() * 4;
}   
//-----------------------------------------------------------------------------

Vertex Square::getCenter() const
{
    return m_square.getCenter();
}
//-----------------------------------------------------------------------------

bool Square::scale(double factor)
{
    return m_square.scale(factor);
}
//-----------------------------------------------------------------------------
