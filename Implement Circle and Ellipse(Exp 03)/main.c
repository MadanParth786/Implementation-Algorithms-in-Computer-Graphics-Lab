//2> Implement Mid point theorem to display circle
#include<windows.h>
#include<GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int xc, yc, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+xc, y+yc);
	glEnd();
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float p = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		if (p < 0)
		{
			x++;
			p += 2*x+1;
		}
		else
		{
			y--;
			x++;
			p += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}
void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	midPointCircleAlgo();

	glFlush ();
}
void init ()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


int main(int argc, char* argv[]) {

      printf("2> Applying Mid Point Algorithm of circle: ");
      printf("\n");

      printf("Enter the coordinates of the circle's centre: ");

      scanf("%d %d",&xc,&yc);

      printf("Enter the radius of the circle: ");

      scanf("%d",&r);

      glutInit(&argc, argv);
	  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	  glutInitWindowSize (640, 480);
	  glutInitWindowPosition (100, 150);

      glutCreateWindow("Mid point Algo of  Circle");

      init();

      glutDisplayFunc(myDisplay);

      glutMainLoop();

}

