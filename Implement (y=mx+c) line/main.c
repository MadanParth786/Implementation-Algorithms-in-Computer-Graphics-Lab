//Implement y=mx+c line
#include<iostream>
#include<GL/glut.h>
using namespace std;

void init() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Straight Line");
}
void display()
{
	glClearColor(1,1,1,1);
	glColor3f(1, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	// Line
	float x1, x2, y1, y2;
	cout<<"enter x1: ";
    cin>>x1;
    cout<<"enter x2: ";
    cin>>x2;
    cout<<"enter y1: ";
    cin>>y1;
    cout<<"enter y2: ";
    cin>>y2;

	float m, c, y;
	m = (y2 - y1) / (x2 - x1);
	c = (y1 - m) * x1;

	glBegin(GL_POINTS);
	for (float x = x1; x <= x2; x = x + 0.001) {
		y = m * x + c;
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
