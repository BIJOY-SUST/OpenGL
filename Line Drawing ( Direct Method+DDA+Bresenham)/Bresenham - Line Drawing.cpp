#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>

void initial_value(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D (0.0,640.0,0.0,480.0);
}

float xs=50,ys=50,xe=400,ye=400,x,y;

int Round(float no){
    if(no-int(no)>=0.5)
        return int(no)+1;
    else
        return int(no);
}

void directMethod(){

    float ydiff = ye-ys;
    float xdiff = xe-xs;

    float  d1 = 2*(ydiff) - xdiff;

    x = xs;
    y = ys;

    while(x != xe+1 and y != ye+1){
        glColor3f(0,0,1);
        glPointSize(10);
        glBegin(GL_POINTS);
        glVertex2i(Round(x),Round(y));
        glEnd();
        if(d1<0){
            x = x+1;
            y=y;
            d1 = d1 + 2*(ydiff);
        }
        else{
            x = x+1;
            y = y+1;
            d1 = 2*(ydiff) - 2*(xdiff);
        }
    }

    glutPostRedisplay();
}

void displayMe(void){

    glClear(GL_COLOR_BUFFER_BIT);

    directMethod();

    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Direct Method Line Drawing");

    glutDisplayFunc(displayMe);
    initial_value();
    glutIdleFunc(directMethod);
    glutMainLoop();
}
