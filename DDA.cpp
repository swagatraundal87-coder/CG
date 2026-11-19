#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

float x1,x2,y1,y2;
float dy,dx,length,x,y,k,Xin,Yin;

void simpleline();
void DashedLine();
void DottedLine();

void display()
{
    cout<<"\nSimple Line\n";
    simpleline();

    cout<<"\nDashed Line\n";
    DashedLine();

    cout<<"\nDotted Line\n";
    DottedLine();
}

void simpleline()
{
    cout<<"Enter the value of x1 :";
    cin>>x1;
    cout<<"Enter the value of y1 : ";
    cin>>y1;
    cout<<"Enter the value of x2 : ";
    cin>>x2;
    cout<<"Enter the value of y2 : ";
    cin>>y2;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)> abs(dy))
        length = abs(dx);
    else
        length = abs(dy);

    Xin = dx/length;
    Yin = dy/length;

    x=x1;
    y=y1;

    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();

    for(k=1 ;k<=length;k++)
    {
        x= x + Xin;
        y= y + Yin;

        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }

    glFlush();
}

void DashedLine()
{
    cout<<"Enter the value of x1 :";
    cin>>x1;
    cout<<"Enter the value of y1 : ";
    cin>>y1;
    cout<<"Enter the value of x2 : ";
    cin>>x2;
    cout<<"Enter the value of y2 : ";
    cin>>y2;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        length = abs(dx);
    else
        length = abs(dy);

    Xin = dx /length;
    Yin = dy /length;

    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    glVertex2i(x,y);

    for (int i = 0; i <= length; i++)
    {
        x = x + Xin;
        y = y + Yin;

        if (i % 5 == 0)
        {
            glVertex2i(x,y);
        }
    }

    glEnd();
    glFlush();
}

void DottedLine()
{
    cout<<"Enter the value of x1 :";
    cin>>x1;
    cout<<"Enter the value of y1 : ";
    cin>>y1;
    cout<<"Enter the value of x2 : ";
    cin>>x2;
    cout<<"Enter the value of y2 : ";
    cin>>y2;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        length = abs(dx);
    else
        length = abs(dy);

    Xin = dx /length;
    Yin = dy /length;

    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    glVertex2i(x,y);

    for (int i = 0; i <= length; i++)
    {
        x = x + Xin;
        y = y + Yin;

        if (i % 2 == 0)
        {
            glVertex2i(x,y);
        }
    }

    glEnd();
    glFlush();
}

void init(void)
{
    gluOrtho2D(0,499,0,499);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("DDA Line Algo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

/*
2. Theory
The DDA (Digital Differential Analyzer) Line Drawing Algorithm is used to draw a straight line between two given points on a computer screen.

It calculates intermediate points between the starting point and ending point of a line. These points are displayed using pixels.

The algorithm uses the difference between the X-coordinates and Y-coordinates to calculate the next pixel position.
Types of lines in this program:
- Simple Line: Displays continuous pixels to form a straight line.
- Dashed Line: Displays pixels at regular intervals to create a dashed line.
- Dotted Line: Displays pixels with smaller gaps to create a dotted line.
The DDA algorithm is simple and easy to implement, but it uses floating-point calculations.

3. Algorithm
1. Start the program.
2. Initialize the OpenGL window.
3. Read the starting point \((x_1,y_1)\) and ending point \((x_2,y_2)\).
4. Calculate dx = x2 - x1 and dy = y2 - y1.
5. Calculate the length using the maximum absolute difference.
6. Calculate Xin = dx / length and Yin = dy / length.
7. Set the initial point as (x1, y1).
8. For a simple line, plot every calculated point.
9. For a dashed line, plot points at every fifth interval.
10. For a dotted line, plot points at every second interval.
11. Display the lines using OpenGL.
12. Stop the program.


4. Example
Input for Simple Line:
Enter the value of x1: 50
Enter the value of y1: 50
Enter the value of x2: 200
Enter the value of y2: 200


Input for Dashed Line:
Enter the value of x1: 50
Enter the value of y1: 250
Enter the value of x2: 200
Enter the value of y2: 400


Input for Dotted Line:
Enter the value of x1: 250
Enter the value of y1: 50
Enter the value of x2: 400
Enter the value of y2: 200


Expected Output:
- First line: Continuous simple line.
- Second line: Dashed line.
- Third line: Dotted line.


5. Conclusion
Thus, we successfully studied and implemented the DDA Line Drawing Algorithm using OpenGL. We learned how to draw simple, dashed, and dotted lines by calculating intermediate pixel positions using X and Y increments.
*/