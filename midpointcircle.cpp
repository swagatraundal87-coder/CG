#include <iostream>
#include <GL/glut.h>
using namespace std;

int xc, yc, r;   // centre and radius

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x + xc, y + yc);
    glEnd();
}

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void midcircle()
{
    int x = 0;
    int y = r;
    float d = 1.25 - r;   // first decision value

    plot(x, y);

    while (y > x)
    {
        if (d < 0)
        {
            x = x + 1;
            d = d + 2*x + 1;
        }
        else
        {
            y = y - 1;
            x = x + 1;
            d = d + 2*(x - y) + 1;
        }

        plot(x, y);
        plot(x, -y);

        // 8-way symmetry
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);   // yellow
    glPointSize(5.0);

    midcircle();

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter the coordinates of the center:\n";

    cout << "\nX-coordinate : ";
    cin >> xc;

    cout << "\nY-coordinate : ";
    cin >> yc;

    cout << "\nEnter radius : ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Circle Drawing Algorithm");

    glutDisplayFunc(myDisplay);

    myInit();
    glutMainLoop();
}