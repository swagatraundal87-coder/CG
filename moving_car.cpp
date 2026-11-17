#include <GL/glut.h>

float rt = 0.0f;   // vertical position of the car

void init(int Width, int height)
{
    glClearColor(1.1, 1.1, 1.1, 1.1);

    glMatrixMode(GL_PROJECTION);

    gluPerspective(45.0f,
                   (GLfloat)Width / (GLfloat)height,
                   0.1f, 50.0f);

    glMatrixMode(GL_MODELVIEW);
}

float ballX = -0.5f;   // first wheel position
float ballY = 0.0f;
float ballZ = 0.0f;

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(0.0f, rt, -6.0f);   // move the whole car

    glBegin(GL_POLYGON);   // car body

        glColor3f(1.0, 0.0, 1.0);

        glVertex3f(-1.0f, 1.0f, 0.0f);
        glVertex3f( 0.4f, 1.0f, 0.0f);
        glVertex3f( 1.0f, 0.4f, 0.0f);

        glColor3f(0.0, 1.0, 0.0);

        glVertex3f(1.0f, 0.0f, 0.0f);

        glColor3f(0.0, 1.0, 1.0);

        glVertex3f(-1.0f, 0.0f, 0.0f);

    glEnd();

    glColor3f(1.0, 1.0, 0.0);   // wheels - yellow

    glTranslatef(ballX, ballY, ballZ);

    glutSolidSphere(0.3, 20, 20);   // first wheel

    glTranslatef(ballX + 1.5, ballY, ballZ);

    glutSolidSphere(0.3, 20, 20);   // second wheel

    rt -= 0.0005f;   // move a little

    if (rt < -2.0f)
        rt = 0.2f;   // come back to the start

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    glutInitWindowSize(640, 480);

    glutInitWindowPosition(0, 0);

    glutCreateWindow("Moving Car");

    glutDisplayFunc(Draw);

    glutIdleFunc(Draw);   // keep calling Draw for animation

    init(640, 480);

    glutMainLoop();

    return 0;
}