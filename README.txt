ex0: Shapes
name: Tomer Akrish
name: Meytal Ben Shimol	
===============================================================================
This program can draw up to 4 shapes: Rectangle, Square, Triangle and Hourglass.
first it will read vertexs from user for each of the shapes, if values arent 
egible it will enter default values.
the draw: shape, shape with bounding rectangle, shape multiply by factor and with
bounding retangle of new size shape.

Rectangle:
creates an object using 2 vertexs: bottom left and top right and has 4 c-tors:
1st: 2 vertexs, 2nd: array of 2 vertexs, 3rd: using 4 coordinates last: vertex + width + height
can get vertexs, height, length and scale

Square:
creates an object with (optional) 2 c-tors: 1st: 2 vertexs, 2nd: vertex + length
can get vertexs, length and scale it

Triangle:
creates an object with 2 c-tors: 1st: an array of 3 vertexs, 2nd: 2 vertexs and height
can get length, vertexs and scale it

Hourglass:
creates an object with 2 c-tors: 1st: 2 triangles, 2nd lower triangle
can get width, length, vertexs and scale it


worthy mentioning notes:
building square class using rectangle member and using his functions
