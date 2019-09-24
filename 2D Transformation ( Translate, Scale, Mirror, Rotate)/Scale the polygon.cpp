#include<bits/stdc++.h>
#include <GL/glut.h>
#include<stdlib.h>
#include <time.h>

#define maxWD 400
#define maxHT 400

int xa, ya, xb, yb, xc, yc, xd, yd, tx, ty;

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


void translate_rec(int tx, int ty)
{
    glColor3f(1.0, 0.0, 0.0);
    xa *=tx;
    xb *=tx;
    xc *=tx;
    xd *=tx;
    
    ya *=ty;
    yb *=ty;
    yc *=ty;
    yd *=ty;

    glBegin(GL_LINE_LOOP);
        glVertex2i(xa,  ya);
        glVertex2i(xb, yb);
        glVertex2i(xd,yd);
        glVertex2i(xc, yc);

    glEnd();
}

void draw_rec() {


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
    
    glBegin(GL_LINE_LOOP);
        glVertex2i(xa,  ya);
        glVertex2i(xb, yb);
        glVertex2i(xd,yd);
        glVertex2i(xc, yc);

    glEnd();
    glFlush();


}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    draw_rec();

    delay(2000);

    translate_rec(tx, ty);
    glFlush();
}

int main(int argc, char** argv)
{
    printf("Input Point serially :  \n");
    scanf("%d %d %d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd);

    printf("Translate point tx and ty : \n");
    scanf("%d %d", &tx, &ty);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(2 * maxWD, 2 * maxHT);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Rectangle scaling");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}

/*

30 120
120 120
30 30
120 30
3 3

 */

