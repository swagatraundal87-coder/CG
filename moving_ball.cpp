#include <GL/glut.h>

float ballX = -1.5f;
float speed = 0.01f;

void init(int Width, int Height)
{
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)Width/Height, 0.1, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Draw ground
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-2, -0.3, -5);
    glVertex3f(2, -0.3, -5);
    glEnd();

    // Draw moving ball
    glColor3f(1, 0, 0);
    glTranslatef(ballX, 0, -5);
    glutSolidSphere(0.2, 20, 20);

    glutSwapBuffers();
}

void update()
{
    ballX += speed;

    if(ballX > 1.5 || ballX < -1.5)
        speed = -speed;

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Moving Ball");

    glutDisplayFunc(Draw);
    glutIdleFunc(update);

    init(640, 480);
    glutMainLoop();

    return 0;
}

/*
2. Theory
Computer animation is the process of creating the illusion of movement by displaying objects at different positions over time.

In this practical, a 3D red ball moves horizontally from left to right and right to left on a black ground line. OpenGL and GLUT are used to create the window, draw the ball, and update its position continuously.

The position of the ball is controlled by the variable ballX, while the variable speed determines its movement speed and direction.

Working of the program:
1. A white background is created.
2. A perspective projection is set using gluPerspective().
3. A black ground line is drawn using GL_LINES.
4. A red 3D ball is created using glutSolidSphere().
5. The glTranslatef() function changes the horizontal position of the ball.
6. The update() function continuously increases or decreases the ball's X-coordinate.
7. When the ball reaches either boundary, its direction is reversed.
8. glutPostRedisplay() requests the window to redraw the updated scene.
Important OpenGL functions:
Function	Purpose
glClearColor()	Sets the background colour.
gluPerspective()	Creates perspective projection.
glTranslatef()	Changes the position of an object.
glutSolidSphere()	Draws a solid 3D sphere.
glutIdleFunc()	Calls the update function when the program is idle.
glutPostRedisplay()	Requests the screen to be redrawn.
glutSwapBuffers()	Displays the completed frame using double buffering.

3. Algorithm
1. Start the program.
2. Initialize GLUT and create a window of size 640 × 480.
3. Set the initial ball position to -1.5.
4. Set the ball speed to 0.01.
5. Initialize the OpenGL projection and background colour.
6. Register the Draw() function for displaying graphics.
7. Register the update() function using glutIdleFunc().
8. In the Draw() function:
   - Clear the colour and depth buffers.
   - Draw the black ground line.
   - Set the ball colour to red.
   - Draw the ball at its current position.
   - Swap the buffers.
9. In the update() function:
   - Increase the ball's X-coordinate by its speed.
   - If the ball reaches either boundary, reverse its speed.
   - Request the screen to redraw.
10. Repeat the animation continuously.
11. Stop.
4. Example
Initial values:
ballX = -1.5
speed = 0.01


Animation behaviour:














Ball position	Direction
-1.5	Moving right
0.0	Moving right
1.5	Moving left
0.0	Moving left
-1.5	Moving right

Output: A red 3D ball continuously moves horizontally over a black ground line. When it reaches the boundary, it changes direction automatically.
5. Conclusion
Thus, a moving ball animation was successfully created using OpenGL and GLUT. This practical demonstrates 3D object creation, translation, double buffering, and continuous animation using an idle callback.
*/