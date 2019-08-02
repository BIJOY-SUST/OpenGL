#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>

void initial_value(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D (0.0,640.0,0.0,480.0);
}

float xs=50,ys=50,xe=400,ye=400,x,y , ek_laf , delx,dely;

int Round(float no){
    if(no-int(no)>=0.5)
        return int(no)+1;
    else
        return int(no);
}

void dda(){

    float ydiff = ye-ys;
    float xdiff = xe-xs;
    if (abs(xdiff) > abs(ydiff))
        ek_laf = abs(xdiff);                
    else
        ek_laf = abs(ydiff);             

    delx = xdiff/ek_laf;           
    dely = ydiff/ek_laf;          

    x = xs;              
    y = ys;            

    for(int i=0; i<ek_laf; i++){
        x = x+delx;       
        y = y+dely;
        glColor3f(0,0,1); 
        glPointSize(10);
        glBegin(GL_POINTS); 
        glVertex2i(Round(x),Round(y));
        glEnd();
    }

    glutPostRedisplay();

}

void displayMe(void){

    glClear(GL_COLOR_BUFFER_BIT);

    dda();

    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("DDA Line Drawing");

    glutDisplayFunc(displayMe);
    initial_value();
    glutIdleFunc(dda);
    glutMainLoop();
}
