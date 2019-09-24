#include<bits/stdc++.h>
#include <GL/glut.h>
#include<stdlib.h>
#include <time.h>

#define maxWD 400
#define maxHT 400

double xa,ya,xb,yb,xc,yc,xd,yd;
double Xa,Ya,Xb,Yb,Xc,Yc,Xd,Yd;
double A;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void myInit(void)
{
    glColor3f(0.0, 0.0, 1.0);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400, maxWD, -400, maxHT);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}


void beforeTotate()
{

    glBegin(GL_LINE_LOOP);
        glVertex2f(xa,  ya);
        glVertex2f(xb, yb);
        glVertex2f(xd,yd);
        glVertex2f(xc, yc);

    glEnd();
}
void afterRotate()
{
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_LINE_LOOP);
        glVertex2f(Xa,  Ya);
        glVertex2f(Xb, Yb);
        glVertex2f(Xd,Yd);
        glVertex2f(Xc, Yc);

    glEnd();
}

void axis() {


    glBegin(GL_LINES);
        
        glVertex2i(0, -400);     
        glVertex2i(0, 400);     

    glEnd();
    glFlush();
    
    glBegin(GL_LINES);
        
        glVertex2i(400, 0);     
        glVertex2i(-400, 0);     

    glEnd();
    glFlush();

}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    axis();

    delay(2000);

    beforeTotate();
    glFlush();

    afterRotate();
    glFlush();

}

int main(int argc, char** argv)
{
    printf("Input Point serially :  \n");
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd);

    scanf("%lf",&A);

    A = A * ((3.1415)/180.0);
    Xa = xa*cos(A) - ya*sin(A);
    Ya = xa*sin(A) + ya*cos(A);
    Xb = xb*cos(A) - yb*sin(A);
    Yb = xb*sin(A) + yb*cos(A);
    Xc = xc*cos(A) - yc*sin(A);
    Yc = xc*sin(A) + yc*cos(A);
    Xd = xd*cos(A) - yd*sin(A);
    Yd = xd*sin(A) + yd*cos(A);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(2 * maxWD, 2 * maxHT);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Rectangle ratating");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}

/*

100 50
300 50
100 10
300 10
35

 */

