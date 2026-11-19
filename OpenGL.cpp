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

/*
2. Theory
OpenGL (Open Graphics Library) is a graphics library used to create and display 2D and 3D graphics. It provides functions to draw different graphical objects such as points, lines, shapes, and 3D objects.

OpenGL is commonly used in computer graphics, games, simulations, and animation.

In this practical, we use OpenGL with the GLUT (OpenGL Utility Toolkit) library. GLUT helps us create a window and handle display functions.

Important OpenGL functions:
Function	Description
glClearColor()	Sets the background colour.
gluOrtho2D()	Sets the 2D coordinate system.
glClear()	Clears the display screen.
glColor3f()	Sets the drawing colour.
glPointSize()	Sets the size of points.
glBegin()	Starts drawing a graphical object.
glVertex2i()	Specifies a 2D vertex using integer coordinates.
glEnd()	Ends the drawing operation.
glFlush()	Executes the OpenGL commands.
glutCreateWindow()	Creates an OpenGL window.
glutDisplayFunc()	Registers the display function.

Drawing modes used:
- GL_POINTS: Used to draw individual points.
- GL_LINES: Used to draw straight lines. Every two vertices form one line.
In this program, three red points and one green horizontal line are displayed on a black background.
3. Algorithm
1. Start the program.
2. Include the OpenGL GLUT header file.
3. Initialize GLUT using glutInit().
4. Set the display mode to single buffering and RGB colour.
5. Set the window size and position.
6. Create the OpenGL window.
7. Set the background colour to black using glClearColor().
8. Set the 2D coordinate system using gluOrtho2D().
9. Register the display function using glutDisplayFunc().
10. Clear the screen using glClear().
11. Set the drawing colour to red and draw three points using GL_POINTS.
12. Set the drawing colour to green and draw one line using GL_LINES.
13. Execute the drawing commands using glFlush().
14. Stop the program.
4. Example
Input: No input is required because the coordinates and colours are already defined in the program.

Coordinates of red points:
Point	X-coordinate	Y-coordinate
P1	100	100
P2	200	200
P3	300	300

Coordinates of green line:
- Starting point: (100, 300)
- Ending point: (400, 300)
Expected Output:








stackoverflow.com


- Black background.
- Three red points.
- One green horizontal line.
5. Conclusion
Thus, we successfully studied and implemented a basic OpenGL program using the GLUT library. We learned how to create an OpenGL window, set background colours, draw points, and draw straight lines using different OpenGL functions.
*/