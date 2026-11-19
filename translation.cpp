#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

int edges;
int transX, transY;

vector<int> pntX, pntY;

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

void drawPolygonTrans(int x, int y)
{
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);

    for (int i = 0; i < edges; i++)
    {
        glVertex2i(pntX[i] + x, pntY[i] + y);
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
    drawPolygonTrans(transX, transY);

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "2D Translation Transformation\n";

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

    cout << "Enter translation factor for X and Y: ";
    cin >> transX >> transY;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);

    glutCreateWindow("2D Translation");

    glutDisplayFunc(myDisplay);

    myInit();

    glutMainLoop();

    return 0;
}
/*
2. Theory
Translation is a basic 2D geometric transformation used to move an object from one position to another without changing its shape, size, or orientation.

In translation, every point of the object is moved by the same distance in the X and Y directions.

The translation factors are represented by tx and ty.

Translation formulas:
\[
X' = X + t_x
\]

\[
Y' = Y + t_y
\]

Where:
- X, Y = Original coordinates.
- X', Y' = New coordinates.
- tx = Translation factor along the X-axis.
- ty = Translation factor along the Y-axis.
Working:
- Positive tx moves the object towards the right.
- Negative tx moves the object towards the left.
- Positive ty moves the object upwards.
- Negative ty moves the object downwards.
The original polygon is displayed in red, and the translated polygon is displayed in green.
3. Algorithm
1. Start the program.
2. Read the number of polygon vertices.
3. Accept the X and Y coordinates of each vertex.
4. Accept translation factors tx and ty.
5. Initialize the OpenGL window.
6. Draw the original polygon in red colour.
7. Calculate new coordinates using the translation formulas.
8. Draw the translated polygon in green colour.
9. Display both polygons.
10. Stop.
4. Example
Input:
Enter number of edges: 3

Enter coordinates for vertex 1: 100 100
Enter coordinates for vertex 2: 200 100
Enter coordinates for vertex 3: 150 200

Enter translation factor for X and Y: 50 30


Calculation:
Original point	Translated point
(100, 100)	(150, 130)
(200, 100)	(250, 130)
(150, 200)	(200, 230)

Output: The original red triangle and translated green triangle are displayed in the OpenGL window.
5. Conclusion
Thus, 2D translation was successfully performed using OpenGL. The polygon was moved in the X and Y directions without changing its shape, size, or orientation.
*/