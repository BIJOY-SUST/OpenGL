#include<bits/stdc++.h>
#include <GL/glut.h>
#include<stdlib.h>
#include <time.h>
using namespace std;
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
    glPointSize(2);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400, maxWD, -400, maxHT);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}


void translate_rec(int tx, int ty)
{
    glColor3f(1.0, 0.0, 0.0);
    
    if(tx>=xa and ty>=ya and tx<=xb and ty<=yb){
        glBegin(GL_POINTS);
        glVertex2i(tx,ty);
        glEnd();
        cout<<"Inside"<<endl;
    }
    else{
        cout<<"Outside"<<endl;
    }

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
        glVertex2i(xa, yb);
        glVertex2i(xb,yb);
        glVertex2i(xb, ya);

    glEnd();
    glFlush();


}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);

    draw_rec();

    delay(2000);

    translate_rec(tx, ty);

    glFlush();
}

int main(int argc, char** argv)
{
    printf("Input lower left point :  \n");
    scanf("%d %d", &xa, &ya);
    printf("Input upper right point :  \n");
    scanf("%d %d", &xb, &yb);

    printf("Input random point tx and ty : \n");
    scanf("%d %d", &tx, &ty);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(2 * maxWD, 2 * maxHT);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Point Clipping");
    myInit();

    glutDisplayFunc(myDisplay);
    
    glutMainLoop();
}

/*

30 30
120 120
30 30

 */

