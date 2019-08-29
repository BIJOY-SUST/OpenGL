#include <iostream>
#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int stx1,sty1,enx2,eny2;

struct Point {
	GLint x;
	GLint y;
};

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

void initial_value() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void floodFill_4dir(GLint x, GLint y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);

	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		setPixelColor(x, y, newColor);
		floodFill_4dir(x+1, y, oldColor, newColor);
		floodFill_4dir(x, y+1, oldColor, newColor);
		floodFill_4dir(x-1, y, oldColor, newColor);
		floodFill_4dir(x, y-1, oldColor, newColor);
	}
	return;
}

void clickTheMouse(int button, int state, int x, int y)
{
	Color newColor = {1.0f, 0.0f, 0.0f};
	Color oldColor = {1.0f, 1.0f, 1.0f};
	GLfloat pntstx1 = (stx1+enx2)/2;
	GLfloat pntsty1 = (sty1+eny2)/2;
	floodFill_4dir(pntstx1, pntsty1, oldColor, newColor);
}
void pointPlot(GLfloat x, GLfloat y){
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_boundary(Point st, Point en) {  

    for(GLfloat i=st.x; i<=en.x; i = i + 0.002){

    	pointPlot(i,st.y);

    }       
    for(GLfloat i=st.x; i<=en.x; i = i + 0.002){

    	pointPlot(i,en.y);

    }    

    for(GLfloat i=st.y; i<=en.y; i = i + 0.002){

    	pointPlot(en.x,i);

    }
    for(GLfloat i=st.y; i<=en.y; i = i + 0.002){

    	pointPlot(st.x,i);

    }

}

void displayMe(void) {
	Point st = {stx1,sty1};
	Point en = {enx2,eny2};

	glClear(GL_COLOR_BUFFER_BIT);
	// glBegin(GL_POINTS);
		draw_boundary(st, en);
	// glEnd();
	glFlush();
}

int main(int argc, char** argv)
{

	cout<<"Enter lower left coordinate of Rectangle : "; 
	cin>>stx1>>sty1;
	cout<<"Enter upper right coordinate of Rectangle : "; 
	cin>>enx2>>eny2;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow ("Rectangle Drawing using FloodFill");

	initial_value();

	glutDisplayFunc(displayMe);
	glutMouseFunc(clickTheMouse);
	glutMainLoop();

	return 0;
}