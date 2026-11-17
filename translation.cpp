#include <iostream>
#include <GL/glut.h>
using namespace std;

int X[3], Y[3];
int tx, ty;

void myInit()
{
    glClearColor(1,1,1,0);
    glColor3f(0,0,0);
    gluOrtho2D(0,640,0,480);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);   // original triangle - red
    glBegin(GL_TRIANGLES);

    for (int i = 0; i < 3; i++)
        glVertex2i(X[i], Y[i]);

    glEnd();

    glColor3f(0,1,0);   // translated triangle - green
    glBegin(GL_TRIANGLES);

    for (int i = 0; i < 3; i++)
        glVertex2i(X[i] + tx, Y[i] + ty);

    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter Triangle Vertices (x y for 3 points):\n";

    for (int i = 0; i < 3; i++)
        cin >> X[i] >> Y[i];

    cout << "Enter Translation Factors (tx ty): ";
    cin >> tx >> ty;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Translation");

    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}