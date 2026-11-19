#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 640, 0, 480);
}

void flood_it(int x, int y, float* fillColor, float* ic)
{
    float color[3];

    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);

    if (color[0]==ic[0] && color[1]==ic[1] && color[2]==ic[2])
    {
        glColor3f(fillColor[0], fillColor[1], fillColor[2]);

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();

        glFlush();

        flood_it(x-2, y, fillColor, ic);  // left
        flood_it(x+1, y, fillColor, ic);  // right
        flood_it(x, y+1, fillColor, ic);  // up
        flood_it(x, y-2, fillColor, ic);  // down
    }
}

void polygon()
{
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    glColor3f(1,0,0);  // left edge red
    glVertex2i(150,100);
    glVertex2i(300,300);

    glColor3f(0,1,0);  // right edge green
    glVertex2i(300,300);
    glVertex2i(450,100);

    glColor3f(0,0,1);  // bottom edge blue
    glVertex2i(150,100);
    glVertex2i(450,100);

    glEnd();
    glFlush();
}

void mouse(int btn, int state, int x, int y)
{
    y = 480 - y;

    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float intCol[] = {1,0,0};
        float color[] = {0,0,1};  // fill colour

        glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, intCol);

        flood_it(x, y, color, intCol);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);

    glutCreateWindow("Polygon Filling - Flood Fill");

    glutDisplayFunc(polygon);
    glutMouseFunc(mouse);

    init();
    glutMainLoop();

    return 0;
}


/*
2. Theory
The Flood Fill Algorithm is a polygon-filling algorithm used in computer graphics to fill a connected area with a selected colour.

It starts from a selected point called the seed point and checks the colour of neighbouring pixels. If the pixel has the same colour as the original interior colour, it changes that pixel to the new fill colour.

The process continues recursively until all connected pixels of the original colour are filled.

In this practical, a triangle is drawn using three different boundary colours. When the user clicks inside the triangle, the algorithm fills the connected interior area with blue colour.

Important functions:
Function	Description
glReadPixels()	Reads the colour of a selected pixel.
glColor3f()	Sets the filling colour.
glVertex2i()	Specifies the pixel coordinates.
glBegin(GL_POINTS)	Starts drawing individual pixels.
glEnd()	Ends the drawing operation.
glutMouseFunc()	Handles mouse click events.

Types of Flood Fill Algorithm:
1. 4-connected Flood Fill: Checks four neighbouring pixels: left, right, up and down.
2. 8-connected Flood Fill: Checks eight neighbouring pixels, including diagonal pixels.
This program uses recursive filling in four directions.

Flood Fill vs Boundary Fill:
- Flood Fill checks whether the pixel has the original interior colour.
- Boundary Fill checks whether the pixel has reached the boundary colour.
3. Algorithm
1. Start the program.
2. Include the required header files.
3. Initialize the GLUT window.
4. Set the background colour to black.
5. Set the 2D coordinate system using gluOrtho2D().
6. Draw a triangle using three different boundary colours.
7. Wait for the user to click inside the triangle.
8. Read the selected pixel colour using glReadPixels().
9. Store the original interior colour and new fill colour.
10. Check whether the current pixel colour matches the original interior colour.
11. If the colours match, change the pixel colour to blue.
12. Check the neighbouring pixels recursively.
13. Repeat the process until all connected pixels are filled.
14. Stop the program.
4. Example
Input:

No keyboard input is required.
- Run the program.
- A triangle with red, green and blue boundary edges appears on a black background.
- Click inside the triangle using the left mouse button.
Expected Output:








blog.magnum.graphics


Output explanation:
- Background colour: Black.
- Left boundary: Red.
- Right boundary: Green.
- Bottom boundary: Blue.
- Interior filling colour: Blue.
After clicking inside the triangle, the interior area is filled with blue colour.
5. Conclusion
Thus, we successfully studied and implemented the Flood Fill Algorithm using OpenGL. We learned how to fill a connected area with a selected colour by checking the original colour of neighbouring pixels using recursive function calls.
*/