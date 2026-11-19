#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0, 640, 0, 480);
}

void bound_it(int x, int y, float* fColor, float* bc)
{
    float color[3];

    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);

    if ((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2]) &&
        (color[0]!=fColor[0] || color[1]!=fColor[1] || color[2]!=fColor[2]))
    {
        glColor3f(fColor[0], fColor[1], fColor[2]);

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();

        bound_it(x+1, y, fColor, bc);
        bound_it(x-2, y, fColor, bc);
        bound_it(x, y+2, fColor, bc);
        bound_it(x, y-2, fColor, bc);
    }

    glFlush();
}

void mouse(int btn, int state, int x, int y)
{
    y = 480 - y;

    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float bCol[] = {1,0,0};   // boundary colour = red
        float color[] = {0,0,1};  // fill colour = blue

        bound_it(x, y, color, bCol);
    }
}

void polygon()
{
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);

    glBegin(GL_LINE_LOOP);  // closed red triangle

    glVertex2i(150,100);
    glVertex2i(300,300);
    glVertex2i(450,100);

    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);

    glutCreateWindow("Polygon Filling - Boundary Fill");

    glutDisplayFunc(polygon);
    glutMouseFunc(mouse);

    init();
    glutMainLoop();

    return 0;
}

/*
2. Theory
The Boundary Fill Algorithm is a polygon-filling algorithm used in computer graphics to fill the inside area of a closed shape with a particular colour.

It starts filling from a selected point called the seed point and checks the colour of neighbouring pixels.

The filling process continues until it reaches the boundary colour. It does not fill pixels that already have the fill colour.

In this practical, we use a triangle with a red boundary and blue filling colour. When the user clicks inside the triangle, the algorithm fills the triangle with blue colour.

Important functions:
Function	Description
glReadPixels()	Reads the colour of a particular pixel.
glColor3f()	Sets the filling colour.
glVertex2i()	Specifies the pixel position.
glBegin(GL_POINTS)	Starts drawing points.
glEnd()	Ends the drawing operation.
glutMouseFunc()	Handles mouse click events.
glutPostRedisplay()	Requests the window to be redrawn (not used in this code).

Colours used:
- Boundary colour: Red (1, 0, 0)
- Fill colour: Blue (0, 0, 1)
- Background colour: White (1, 1, 1)
Types of Boundary Fill Algorithm:
1. 4-connected Boundary Fill: Checks four neighbouring pixels: left, right, top and bottom.
2. 8-connected Boundary Fill: Checks eight neighbouring pixels, including diagonal neighbours.
This program uses four-direction recursive filling. It moves through neighbouring pixels until it reaches the red boundary or an already-filled blue pixel.
3. Algorithm
1. Start the program.
2. Include the required header files.
3. Initialize the GLUT window.
4. Set the background colour to white.
5. Set the 2D coordinate system.
6. Draw a closed triangle using GL_LINE_LOOP.
7. Set the boundary colour to red.
8. Wait for the user to click inside the triangle.
9. Read the colour of the selected pixel using glReadPixels().
10. Check whether the pixel colour is different from the boundary colour and fill colour.
11. If the condition is true, change the pixel colour to blue.
12. Apply the same process recursively to the neighbouring pixels.
13. Stop filling when the boundary colour is reached.
14. Stop the program.
4. Example
Input:

No keyboard input is required.
- Run the program.
- A red triangle appears on a white background.
- Click anywhere inside the triangle using the left mouse button.
Expected Output:








tex.stackexchange.com


Output explanation:
- Before clicking: The triangle has a red boundary and white interior.
- After clicking: The inside area of the triangle becomes blue.
- The red boundary remains unchanged.
5. Conclusion
Thus, we successfully implemented the Boundary Fill Algorithm using OpenGL. We learned how to fill a closed polygon with a selected colour by starting from a seed point and checking neighbouring pixels until the boundary is reached.

Important practical note: Your supplied code uses recursive calls with offsets of 1 and 2 pixels. This is not the standard four-connected implementation, which normally checks (x+1,y), (x-1,y), (x,y+1) and (x,y-1). Also, recursive filling can become very slow or cause stack overflow for large areas. For your practical exam, understand the code as supplied, but test it before relying on it.
*/