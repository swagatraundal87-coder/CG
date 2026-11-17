#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

int X[3], Y[3];
double angleRad;

double round1(double d)
{
    return floor(d + 0.5);
}

void myInit()
{
    glClearColor(1,1,1,0);
    glColor3f(0,0,0);
    gluOrtho2D(0,640,0,480);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);   // original - red
    glBegin(GL_TRIANGLES);

    for (int i = 0; i < 3; i++)
        glVertex2i(X[i], Y[i]);

    glEnd();

    glColor3f(0,1,0);   // rotated - green
    glBegin(GL_TRIANGLES);

    for (int i = 0; i < 3; i++)
    {
        glVertex2i(
            round1(X[i]*cos(angleRad) - Y[i]*sin(angleRad)),
            round1(X[i]*sin(angleRad) + Y[i]*cos(angleRad))
        );
    }

    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    int angle;

    cout << "Enter Triangle Vertices (x y for 3 points):\n";

    for (int i = 0; i < 3; i++)
        cin >> X[i] >> Y[i];

    cout << "Enter Rotation Angle: ";
    cin >> angle;

    angleRad = angle * 3.1416 / 180.0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Rotation");

    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}