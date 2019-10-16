#include<bits/stdc++.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>

void display();
void display2();

using namespace std;
float xmin = -100;
float ymin = -100;
float xmax = 100;
float ymax = 100;
float xd1, yd1, xd2, yd2;
float xdd1,ydd1,xdd2,ydd2;
#define maxWD 400
#define maxHT 400

void init(void)
{
    glColor3f(0.0, 0.0, 1.0);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glPointSize(6);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400, maxWD, -400, maxHT);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();


}

int code(float x, float y)
{
    int c = 0;
    if (y > ymax)c = 8;
    if (y < ymin)c = 4;
    if (x > xmax)c = c | 2;
    if (x < xmin)c = c | 1;
    return c;
}

void cohen_Line(float x1, float y1, float x2, float y2)
{
    int c1 = code(x1, y1);
    int c2 = code(x2, y2);
    float m = (y2 - y1) / (x2 - x1);
    while ((c1 | c2) > 0)
    {
        if ((c1 & c2) > 0)
        {
            exit(0);
        }

        float xi = x1; float yi = y1;
        int c = c1;
        if (c == 0)
        {
            c = c2;
            xi = x2;
            yi = y2;
        }
        float x, y;
        if ((c & 8) > 0)
        {
            y = ymax;
            x = xi + 1.0 / m * (ymax - yi);
        }
        else if ((c & 4) > 0)
        {
            y = ymin;
            x = xi + 1.0 / m * (ymin - yi);
        }
        else if ((c & 2) > 0)
        {
            x = xmax;
            y = yi + m * (xmax - xi);
        }
        else if ((c & 1) > 0)
        {
            x = xmin;
            y = yi + m * (xmin - xi);
        }

        if (c == c1)
        {
            xd1 = x;
            yd1 = y;
            c1 = code(xd1, yd1);
        }

        if (c == c2)
        {
            xd2 = x;
            yd2 = y;
            c2 = code(xd2, yd2);
        }
    }

    display2();

}





void mykey(unsigned char key, int x, int y)
{
    if (key == 'c')
    {   cout << "Hello" << endl;
        cohen_Line(xd1, yd1, xd2, yd2);
        glFlush();
    }
}

void display2()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(6);

    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);

    glVertex2i(0, -400);
    glVertex2i(0, 400);

    glEnd();
    glFlush();

    glBegin(GL_LINES);

    glVertex2i(400, 0);
    glVertex2i(-400, 0);

    glEnd();


    glColor3f(0.0, 0.0, 1.0);


    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin, ymin);
    glVertex2i(xmin, ymax);
    glVertex2i(xmax, ymax);
    glVertex2i(xmax, ymin);
    glEnd();


    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
        glVertex2i(xdd1,ydd1);
        glVertex2i(xd1, yd1);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(xd1, yd1);
    glVertex2i(xd2, yd2);
    glEnd();
    glFlush();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
        glVertex2i(xd2, yd2);
        glVertex2i(xdd2,ydd2);
    glEnd();

}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(6);

    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);
        glVertex2i(0, -400);
        glVertex2i(0, 400);

    glEnd();
    glFlush();

    glBegin(GL_LINES);
        glVertex2i(400, 0);
        glVertex2i(-400, 0);

    glEnd();


    glColor3f(0.0, 0.0, 1.0);


    glBegin(GL_LINE_LOOP);
        glVertex2i(xmin, ymin);
        glVertex2i(xmin, ymax);
        glVertex2i(xmax, ymax);
        glVertex2i(xmax, ymin);
    glEnd();




    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2i(xd1, yd1);
        glVertex2i(xd2, yd2);
    glEnd();


    glFlush();


}


int main(int argc, char** argv)
{
    printf("Enter line co-ordinates:");
    cin >> xd1 >> yd1 >> xd2 >> yd2;
    xdd1 = xd1;
    ydd1 = yd1;
    xdd2 = xd2;
    ydd2 = yd2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(2 * maxWD, 2 * maxHT);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Line Clipping");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(mykey);

    glutMainLoop();
    return 0;
}


/*
-120 0
0 120
*/