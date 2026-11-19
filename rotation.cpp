#include <iostream>
#include <vector>
#include <cmath>
#include <GL/glut.h>
using namespace std;

int edges;
double angle, angleRad;

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

void drawPolygonRotation(double angleRad)
{
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);

    for (int i = 0; i < edges; i++)
    {
        double x = pntX[i] * cos(angleRad)
                 - pntY[i] * sin(angleRad);

        double y = pntX[i] * sin(angleRad)
                 + pntY[i] * cos(angleRad);

        glVertex2i(roundValue(x), roundValue(y));
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
    drawPolygonRotation(angleRad);

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "2D Rotation Transformation\n";

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

    cout << "Enter angle of rotation in degrees: ";
    cin >> angle;

    angleRad = angle * 3.14159265 / 180.0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);

    glutCreateWindow("2D Rotation");

    glutDisplayFunc(myDisplay);

    myInit();

    glutMainLoop();

    return 0;
}
/*
2. Theory
Rotation is a 2D geometric transformation used to turn an object around a fixed point by a specified angle.

In this program, the polygon is rotated around the origin (0, 0).

The rotation angle is represented by θ (theta).

Rotation formulas:
\[
X' = X\cos\theta - Y\sin\theta
\]

\[
Y' = X\sin\theta + Y\cos\theta
\]

Where:
- X, Y = Original coordinates.
- X', Y' = New coordinates.
- θ = Angle of rotation.
- sin() = Sine function.
- cos() = Cosine function.
The angle must be converted from degrees into radians because the C++ sin() and cos() functions use radians.

Degree-to-radian conversion:
\[
\theta_{\text{rad}} = \theta_{\text{degree}}\times\frac{\pi}{180}
\]

Types of rotation:
- Positive angle: Anticlockwise rotation.
- Negative angle: Clockwise rotation.
The original polygon is displayed in red, and the rotated polygon is displayed in blue.
3. Algorithm
1. Start the program.
2. Read the number of polygon vertices.
3. Accept the X and Y coordinates of each vertex.
4. Accept the angle of rotation in degrees.
5. Convert the angle from degrees into radians.
6. Initialize the OpenGL window.
7. Draw the original polygon in red colour.
8. Calculate the new X and Y coordinates using the rotation formulas.
9. Round the calculated coordinates to integer values.
10. Draw the rotated polygon in blue colour.
11. Display both polygons.
12. Stop.
4. Example
Input:
Enter number of edges: 3

Enter coordinates for vertex 1: 100 100
Enter coordinates for vertex 2: 200 100
Enter coordinates for vertex 3: 150 200

Enter angle of rotation in degrees: 90


Calculation:

For a 90-degree anticlockwise rotation:
\[
\cos 90^\circ=0,\quad \sin 90^\circ=1
\]

Therefore:
\[
X'=-Y,\qquad Y'=X
\]

Original point	Rotated point
(100, 100)	(-100, 100)
(200, 100)	(-100, 200)
(150, 200)	(-200, 150)

Output: The original red triangle and rotated blue triangle are displayed. However, these example coordinates produce negative X-values after rotation, so the rotated polygon will be outside the visible window.
5. Conclusion
Thus, 2D rotation was successfully performed using OpenGL. The polygon was rotated by a specified angle using sine and cosine functions and the rotation transformation formulas.
*/