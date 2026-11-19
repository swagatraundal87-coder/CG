#include <GL/glut.h>
#include <iostream>
using namespace std;

float xmin = 150, ymin = 150, xmax = 350, ymax = 350;
float x1, y1, x2, y2;
bool clipped = false;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

int computeCode(float x, float y)
{
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

void cohenSutherlandClip()
{
    float x, y;

    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out = code1 ? code1 : code2;

            if (code_out & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept)
        clipped = true;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);

    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();

    if (!clipped)
        glColor3f(1, 0, 0);
    else
        glColor3f(0, 1, 0);

    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        cohenSutherlandClip();
        glutPostRedisplay();
    }
}

void init()
{
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    cout << "Enter line coordinates (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Cohen Sutherland Line Clipping with Mouse");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}

/*
2. Theory
The Cohen-Sutherland Line Clipping Algorithm is a computer graphics algorithm used to remove the unwanted portions of a line that lie outside a rectangular clipping window.

It checks whether a line is completely inside, completely outside, or partially inside the clipping window.

The algorithm divides the screen into nine regions using a rectangular clipping window. Each region is assigned a 4-bit region code.

Region Codes:
Region	Code
Inside	0000
Left	0001
Right	0010
Bottom	0100
Top	1000

Three main cases:
1. Completely Inside: If both endpoints have region code 0000, the entire line is accepted.
2. Completely Outside: If the bitwise AND of both region codes is not zero, the line is rejected.
3. Partially Inside: If the line is partially inside the clipping window, the intersection point is calculated and the outside portion is removed.
Important functions:
Function	Description
computeCode()	Calculates the region code of a point.
cohenSutherlandClip()	Performs the line clipping operation.
glBegin(GL_LINE_LOOP)	Draws the rectangular clipping window.
glBegin(GL_LINES)	Draws the line.
glutMouseFunc()	Handles mouse click events.
glutPostRedisplay()	Refreshes the display window.

In this program, the clipping window is displayed in white colour. The original line is displayed in red, and after successful clipping, the visible line is displayed in green.
3. Algorithm
1. Start the program.
2. Include the required OpenGL and iostream header files.
3. Define the rectangular clipping window boundaries.
4. Read the starting and ending coordinates of the line.
5. Initialize the GLUT window.
6. Set the background colour to black.
7. Calculate the region codes of both endpoints using computeCode().
8. Check the following conditions:
   - If both region codes are zero, accept the line.
   - If the bitwise AND of both codes is non-zero, reject the line.
   - Otherwise, calculate the intersection point with the clipping boundary.
9. Replace the outside endpoint with the intersection point.
10. Repeat the process until the line is accepted or rejected.
11. Display the clipping window and clipped line.
12. Click the left mouse button to perform clipping.
13. Stop the program.
4. Example
Input:
Enter line coordinates (x1 y1 x2 y2):

100 200 400 300


Clipping Window Coordinates:
Boundary	Coordinate
xmin	150
ymin	150
xmax	350
ymax	350

Explanation:
- Starting point: (100, 200)
- Ending point: (400, 300)
- The starting point is outside the left boundary.
- The ending point is outside the right boundary.
- The algorithm calculates the intersection points with the clipping window.
- Only the portion of the line inside the rectangle is displayed after clipping.
Expected Output:








slideserve.com


- White rectangle: Clipping window.
- Red line: Original line before clipping.
- Green line: Clipped line after successful clipping.
5. Conclusion
Thus, we successfully implemented the Cohen-Sutherland Line Clipping Algorithm using OpenGL. We learned how to identify different regions using 4-bit codes and remove the unwanted portions of a line outside a rectangular clipping window.
*/