#include <iostream>
#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

double pntX1, pntY1, r;
void initial_value (void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void pointPlot(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}
void midPointCircleAlgo(){
	double x = r;
	double y = 0;
	double limit = 45;
	pointPlot(floor(x),floor(y));
	
	double cnt = 0;

	while(cnt<=limit){
		
		x = cos(cnt*3.1416/180.0);
		x = x*r;

		y = sin(cnt*3.1416/180.0);
		y = y*r;

		int x2 = floor(x);
		int y2 = floor(y);

		pointPlot(x2, y2);
		pointPlot(x2, -y2);
		pointPlot(-x2, y2);
		pointPlot(-x2, -y2);
		pointPlot(y2, x2);
		pointPlot(-y2, x2);
		pointPlot(y2, -x2);
		pointPlot(-y2, -x2);

		cnt++;
	}
}
void displayMe(void){
	glClear (GL_COLOR_BUFFER_BIT);

	midPointCircleAlgo();

	glFlush ();
}

int main(int argc, char** argv){

	cout<<"Enter the coordinates of the center :" << endl;

	cout<<"X-coordinate : "; 
	cin>>pntX1;
	cout<<"Y-coordinate : "; 
	cin>>pntY1;
	cout<<"Enter radius : "; 
	cin >> r;

	glutInit(&argc, argv);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow ("Trigonometric Circle Drawing Alogrithms");
	

	initial_value();
	glutDisplayFunc(displayMe);
	glutMainLoop();

	return 0; 
}