#include<bits/stdc++.h>
#include <GL/glut.h>
#include<stdlib.h>
using namespace std;

int n = 0, highY = -1010, lowY = 1010;

struct Vertex {
	int x;
	int y;
} vertex[1010];

void initial_value() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}



int getIntersectionPoint ( Vertex v1, Vertex v2, int y ) {
    if( v1.y == y )
        return v1.x;
    if( v2.y == y )
        return v2.x;
    if( v1.x == v2.x )
        return v1.x;

    float x;
    float dx = v2.x - v1.x;
    float dy = v2.y - v1.y;
    float m = dy/dx;
    float c;
    c = v1.y - m*v1.x;
    x = ( (float)y - c )/m;
    int X = round(x);
    return X;
}

void lol() {

	int tempX[100], tempIndex, finalIndex;
    for(int i = lowY; i <= highY; i++){
        tempIndex = 0;
        for(int j = 0; j < n; j++){
            if(vertex[j].y == i){
                int ny1, ny2;
                if(j==0){
                	 ny1 = vertex[1].y, ny2  = vertex[n-1].y;
                }
                else if(j==n-1){
                	 ny1 = vertex[0].y, ny2  = vertex[n-2].y;
                }
                else{
                	 ny1 = vertex[j-1].y, ny2 = vertex[j+1].y;
                }
                if((ny1>i and i>ny2) or (ny1<i and i<ny2) ){
                    tempX[tempIndex++] = vertex[j].x;
                }
            }
            else if(j != n-1){
                int y1 = vertex[j].y;
                int y2 = vertex[j+1].y;
                int y = i;
                if((y1>i and i>y2) or (y1<i and i<y2) ){
                    int x = getIntersectionPoint(vertex[j], vertex[j+1], y);
                    tempX[tempIndex++] = x;
                }
            }
            else{
                int y1 = vertex[j].y;
                int y2 = vertex[0].y;
                int y = i;
                if((y1>i and i>y2) or (y1<i and i<y2) ){
                    int x = getIntersectionPoint(vertex[j], vertex[0], y);
                    tempX[tempIndex++] = x;
                }
            }

        }
        sort(tempX, tempX+tempIndex);
            glBegin(GL_LINES);
            for(int k = 0; k<tempIndex; k+=2){
                float ok = i;
                float okk=tempX[k];
                float okk2=tempX[k+1];

                glVertex2f(okk,ok);
                glVertex2f(okk2, ok);

            }
            glEnd();


    }
}
// void clickTheMouse(int button, int state, int x, int y) {

// 	lol();

// }


void draw_polygon() {

	glBegin(GL_LINE_LOOP);
		for(int i=0;i<n;i++){
			glVertex2i(vertex[i].x, vertex[i].y);
		}			

	glEnd();
	
}

void displayMe(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	draw_polygon();
	lol();
	glFlush();
}

int main(int argc, char** argv) {

	printf("Enter number of vertexs( N > 2) : ");
	cin >> n;
	if (n < 3) {
		printf("Enter number of vertexs( N > 2) : ");
		return 0;
	}
	for (int i = 0; i < n; i++) {

		scanf("%d %d", &vertex[i].x, &vertex[i].y);

		if (vertex[i].y > highY ) highY = vertex[i].y;
		if (vertex[i].y < lowY ) lowY = vertex[i].y;


	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow ("Ploygon coloring...!");

	initial_value();

	glutDisplayFunc(displayMe);
	// glutMouseFunc(clickTheMouse);
	glutMainLoop();

	return 0;

}
/*
6
150 150
180 180
210 150
230 300
130 250
100 180

*/