#include <iostream>
#include <vector>
#include <cmath>
#include <GL/glut.h>
using namespace std;

int edges;
double scaleX, scaleY;

vector<int> pntX, pntY;

int roundValue(double d)
{
    return (int)round(d);
}

void drawPolygon()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);

    for (int i = 0; i < edges; i++)
    {
        glVertex2i(pntX[i], pntY[i]);
    }

    glEnd();
}

void drawPolygonScale(double x, double y)
{
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);

    for (int i = 0; i < edges; i++)
    {
        glVertex2i(
            roundValue(pntX[i] * x),
            roundValue(pntY[i] * y)
        );
    }

    glEnd();
}

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawPolygon();
    drawPolygonScale(scaleX, scaleY);

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "2D Scaling Transformation\n";

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int x, y;

        cout << "Enter coordinates for vertex " << i + 1 << ": ";
        cin >> x >> y;

        pntX.push_back(x);
        pntY.push_back(y);
    }

    cout << "Enter scaling factor for X and Y: ";
    cin >> scaleX >> scaleY;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);

    glutCreateWindow("2D Scaling");

    glutDisplayFunc(myDisplay);

    myInit();

    glutMainLoop();

    return 0;
}
/*
2. Theory
Scaling is a 2D geometric transformation used to increase or decrease the size of an object.

In scaling, the coordinates of every vertex are multiplied by scaling factors along the X-axis and Y-axis.

The scaling factors are represented by Sx and Sy.

Scaling formulas:
\[
X' = X \times S_x
\]

\[
Y' = Y \times S_y
\]

Where:
- X, Y = Original coordinates.
- X', Y' = New coordinates.
- Sx = Scaling factor along the X-axis.
- Sy = Scaling factor along the Y-axis.
Types of scaling:
1. Uniform scaling: When both scaling factors are equal, the object is enlarged or reduced proportionally.
2. Differential scaling: When the X and Y scaling factors are different, the object's proportions change.
Effect of scaling factors:
- Factor greater than 1: Enlarges the object.
- Factor between 0 and 1: Reduces the object.
- Factor equal to 1: Keeps the size unchanged.
The original polygon is displayed in red, and the scaled polygon is displayed in blue.
3. Algorithm
1. Start the program.
2. Read the number of polygon vertices.
3. Accept the X and Y coordinates of each vertex.
4. Accept scaling factors Sx and Sy.
5. Initialize the OpenGL window.
6. Draw the original polygon in red colour.
7. Calculate new coordinates using the scaling formulas.
8. Round the calculated coordinates to integer values.
9. Draw the scaled polygon in blue colour.
10. Display both polygons.
11. Stop.
4. Example
Input:
Enter number of edges: 3

Enter coordinates for vertex 1: 100 100
Enter coordinates for vertex 2: 200 100
Enter coordinates for vertex 3: 150 200

Enter scaling factor for X and Y: 2 2


Calculation:
Original point	Scaled point
(100, 100)	(200, 200)
(200, 100)	(400, 200)
(150, 200)	(300, 400)

Output: The original red triangle and enlarged blue triangle are displayed in the OpenGL window.
5. Conclusion
Thus, 2D scaling was successfully performed using OpenGL. The size of the polygon was increased or decreased using scaling factors along the X-axis and Y-axis.
*/