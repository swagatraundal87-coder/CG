#include <GL/glut.h>

void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);   // black background
    gluOrtho2D(0, 640, 0, 480);         // x 0..640, y 0..480
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);           // red
    glPointSize(6);
    glBegin(GL_POINTS);
        glVertex2i(100, 100);
        glVertex2i(200, 200);
        glVertex2i(300, 300);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);           // green
    glBegin(GL_LINES);                  // 2 vertices = 1 line
        glVertex2i(100, 300);
        glVertex2i(400, 300);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("My First OpenGL Program");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}