#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

int X[3], Y[3];
double sx, sy;

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

    glColor3f(0,0,1);   // scaled - blue
    glBegin(GL_TRIANGLES);

    for (int i = 0; i < 3; i++)
        glVertex2i(round1(X[i]*sx), round1(Y[i]*sy));

    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter Triangle Vertices (x y for 3 points):\n";

    for (int i = 0; i < 3; i++)
        cin >> X[i] >> Y[i];

    cout << "Enter Scaling Factors (sx sy): ";
    cin >> sx >> sy;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Scaling");

    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}
