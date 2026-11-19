#include <GL/glut.h>
#include <iostream>
using namespace std;

int X1, Y1, X2, Y2;

void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 499, 0, 499);
}

void bresenham()
{
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    int x = X1, y = Y1;

    int e = 2*dy - dx;

    glBegin(GL_POINTS);
    glVertex2i(x, y);

    for (int i = 1; i <= dx; i++)
    {
        if (e >= 0)
        {
            y = y + 1;
            e = e - 2*dx;
        }

        x = x + 1;
        e = e + 2*dy;

        glVertex2i(x, y);
    }

    glEnd();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    bresenham();
}

int main(int argc, char** argv)
{
    cout << "Enter x1 y1 x2 y2 : ";
    cin >> X1 >> Y1 >> X2 >> Y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham Line");

    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

/*
2. Theory
Bresenham's Line Drawing Algorithm is a computer graphics algorithm used to draw a straight line between two given points on the screen.

It selects the nearest pixel to the actual line path using an integer decision parameter. It mainly uses addition, subtraction and integer calculations instead of floating-point calculations.

The algorithm determines whether the next pixel should be selected in the horizontal direction or diagonally.

Important formulas:
1. Calculate the differences:
   
   \[
   dx = x_2-x_1
   \]
   
   \[
   dy = y_2-y_1
   \]
2. Calculate the initial decision parameter:
   
   \[
   P = 2dy-dx
   \]
3. If the decision parameter is greater than or equal to zero:
   
   \[
   P = P-2dx+2dy
   \]
   
   Increase both X and Y coordinates.
4. If the decision parameter is less than zero:
   
   \[
   P = P+2dy
   \]
   
   Increase only the X coordinate.
Advantages:
- Uses integer calculations.
- Faster than DDA in many implementations.
- Produces accurate lines.
- Requires less computational effort.
Note: The given program is designed for lines drawn from left to right with a slope between 0 and 1.
3. Algorithm
1. Start the program.
2. Include the required header files.
3. Read the starting point (X1, Y1) and ending point (X2, Y2).
4. Initialize the GLUT window.
5. Set the background colour to black.
6. Calculate dx = X2 - X1 and dy = Y2 - Y1.
7. Set the initial coordinates as x = X1 and y = Y1.
8. Calculate the decision parameter e = 2*dy - dx.
9. Plot the starting pixel.
10. Repeat the following steps until the line reaches the ending point:
    - If e >= 0, increase Y by 1 and subtract 2*dx from e.
    - Increase X by 1 and add 2*dy to e.
    - Plot the new pixel.
11. Display the line using OpenGL.
12. Stop the program.
4. Example
Input:
Enter x1 y1 x2 y2:

100 100 200 150


Calculation:
\[
dx = 200-100 = 100
\]

\[
dy = 150-100 = 50
\]

Initial decision parameter:
\[
P = 2(50)-100 = 0
\]

The algorithm calculates the next pixel using the decision parameter and continues until it reaches the ending point.

Expected Output:








blog.mbedded.ninja


- Background colour: Black.
- Line colour: White.
- Starting point: (100, 100).
- Ending point: (200, 150).
5. Conclusion
Thus, we successfully implemented Bresenham's Line Drawing Algorithm using OpenGL. We learned how to draw a straight line by selecting the nearest pixels using an integer decision parameter. This algorithm reduces floating-point calculations and provides an efficient method for line drawing.
*/