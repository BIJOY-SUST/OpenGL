#include <iostream>
#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int pntX1,pntY1,r;

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

	floodFill_4dir(pntX1, pntY1, oldColor, newColor);
}
void pointPlot( Point pC ,  GLfloat x, GLfloat y){
	glBegin(GL_POINTS);
	glVertex2i(x+pC.x, y+pC.y);
	glEnd();
}
void draw_circle(Point pC, GLfloat radius) {




// Bresenham's doesn't work correctly , cause somewhere it skip the point. So the circle doesn't color completely..!
	
	// GLint x = 0;
	// GLint y = radius;
	// float decision_parameter = 3 - 2*r;
	// pointPlot( pC, x, y);

	// while (x <= y){
	// 	if (decision_parameter < 0){
	// 		x++; 
	// 		decision_parameter += 4*x+6;
	// 	}
	// 	else{
	// 		y--;
	// 		x++;
	// 		decision_parameter += 4*(x-y)+10;
	// 	}
	// 	pointPlot(pC,x, y);
	// 	pointPlot(pC,x, -y);
	// 	pointPlot(pC,-x, y);
	// 	pointPlot(pC,-x, -y);
	// 	pointPlot(pC,y, x);
	// 	pointPlot(pC,-y, x);
	// 	pointPlot(pC,y, -x);
	// 	pointPlot(pC,-y, -x);
	// }
	

// Using Trigonometric

	GLfloat step = 1/radius;
	GLfloat x, y;

	for(GLfloat theta = 0; theta <= 360; theta += step) {
		x =  (radius * cos(theta));
		y =  (radius * sin(theta));
		pointPlot(pC,x, y);
	}
}

void displayMe(void) {
	Point pt = {pntX1, pntY1};
	int radius = r;

	glClear(GL_COLOR_BUFFER_BIT);
	// glBegin(GL_POINTS);
		draw_circle(pt, radius);
	// glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	cout<<"Enter the coordinates of the center :" << endl;

	cout<<"X-coordinate : "; 
	cin>>pntX1;
	cout<<"Y-coordinate : "; 
	cin>>pntY1;
	cout<<"Enter radius : "; 
	cin >> r;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow ("Circle Drawing using FloodFill");

	initial_value();

	glutDisplayFunc(displayMe);
	glutMouseFunc(clickTheMouse);
	glutMainLoop();

	return 0;
}