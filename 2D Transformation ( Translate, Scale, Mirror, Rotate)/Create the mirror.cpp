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


void mirror_x(int tx, int ty)
{
    glColor3f(1.0, 0.0, 0.0);





    glBegin(GL_LINE_LOOP);
        glVertex2i(xa,  ya*(-1));
        glVertex2i(xb, yb*(-1));
        glVertex2i(xd,yd*(-1));
        glVertex2i(xc, yc*(-1));

    glEnd();
}
void mirror_y(int tx, int ty)
{
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_LINE_LOOP);
        glVertex2i(xa*(-1),  ya);
        glVertex2i(xb*(-1), yb);
        glVertex2i(xd*(-1),yd);
        glVertex2i(xc*(-1), yc);

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

    mirror_x(tx, ty);
    glFlush();

    mirror_y(tx, ty);
    glFlush();

}

int main(int argc, char** argv)
{
    printf("Input Point serially :  \n");
    scanf("%d %d %d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd);
    
    

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(2 * maxWD, 2 * maxHT);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Rectangle mirroring");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}

/*

100 50
300 50
100 10
300 10
*/

