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