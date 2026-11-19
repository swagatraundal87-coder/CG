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

/*
2. Theory
The Midpoint Circle Drawing Algorithm is used to draw a circle on a computer screen using pixels. It is an efficient circle-generation algorithm because it uses a decision parameter to select the next pixel.

A circle is symmetrical about its centre. Therefore, instead of calculating all points of the circle, we calculate points in one octant and use eight-way symmetry to generate the remaining points.

The algorithm starts from the point (0, r), where r is the radius of the circle. It then calculates the next point using a decision parameter.

Working of the algorithm:
1. Take the centre coordinates (xc, yc) and radius r.
2. Initialize x = 0 and y = r.
3. Calculate the initial decision parameter.
4. Check the decision parameter:
   - If it is negative, increase x by 1.
   - Otherwise, increase x by 1 and decrease y by 1.
5. Plot the calculated point using eight-way symmetry.
6. Repeat until x becomes greater than or equal to y.
Eight-way symmetry:

For every calculated point (x, y), eight points are plotted around the circle:
- (x, y)
- (x, -y)
- (-x, y)
- (-x, -y)
- (y, x)
- (-y, x)
- (y, -x)
- (-y, -x)
The program uses the plot() function to display these points using OpenGL.
3. Algorithm
1. Start the program.
2. Accept the centre coordinates xc, yc and radius r from the user.
3. Initialize the GLUT window.
4. Set the background colour to white.
5. Initialize x = 0 and y = r.
6. Calculate the initial decision parameter d = 1.25 - r.
7. Plot the initial point.
8. Repeat while y > x:
   - If d < 0, increment x and update d.
   - Otherwise, increment x, decrement y and update d.
   - Plot all eight symmetrical points.
9. Display the complete circle.
10. Stop.
4. Example
Input:
Enter the coordinates of the center:

X-coordinate : 320

Y-coordinate : 240

Enter radius : 100


Output:








slideserve.com


The program displays a yellow circle with centre (320, 240) and radius 100 on a white background.
5. Conclusion
Thus, the circle was successfully drawn using the Midpoint Circle Drawing Algorithm and OpenGL. This practical demonstrates the use of a decision parameter and eight-way symmetry for efficient circle generation.
*/