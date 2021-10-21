#pragma once

#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"

class Square
{
public:
    Square(const Vertex& bottomLeft, const Vertex& topRight);   //c-tor with 2 vertexs
    Square(const Vertex& start, double length);                 //c-tor with vertex and length

    Vertex getBottomLeft() const;
    Vertex getTopRight() const;
    double getLength() const;

    void draw(Board& board) const;
    Rectangle getBoundingRectangle() const;
    double getArea() const;
    double getPerimeter() const;
    Vertex getCenter() const;
    bool scale(double factor);

private:
    Vertex m_bottomLeft;
    Vertex m_topRight;
    bool squareIsValid(const Vertex& v1, const Vertex& v2);
};