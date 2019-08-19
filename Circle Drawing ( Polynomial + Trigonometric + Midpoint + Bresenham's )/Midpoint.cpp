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
	int x = 0;
	int y = r;
	float decision_parameter = 5/4 - r;
	pointPlot(x, y);

	while (y > x){
		if (decision_parameter < 0){
			x++; 
			decision_parameter += 2*x+1;
		}
		else{
			y--;
			x++;
			decision_parameter += 2*(x-y)+1;
		}
		pointPlot(x, y);
		pointPlot(x, -y);
		pointPlot(-x, y);
		pointPlot(-x, -y);
		pointPlot(y, x);
		pointPlot(-y, x);
		pointPlot(y, -x);
		pointPlot(-y, -x);
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
	glutCreateWindow ("Midpoint Circle Drawing Alogrithms");
	

	initial_value();
	glutDisplayFunc(displayMe);
	glutMainLoop();

	return 0; 
}