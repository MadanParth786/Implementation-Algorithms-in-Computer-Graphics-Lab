//Experiment 03
//3> Draw an ellipse using mid point algorithm:

#include<windows.h>
#include<GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int rx,ry;
int xCenter,yCenter;
void myinit(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D (0.0,640.0,0.0,480.0);
 }
 void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  glEnd();
}

void ellipMidPointalgo()
{
    float x = 0;
    float y = ry;
    float p1 = ry * ry - (rx * rx)* ry + (rx * rx) * (0.25) ;
    float dx = 2 * (ry * ry) * x;
    float dy = 2 * (rx * rx) * y;
    while(dx < dy)
    {
         setPixel(xCenter + x  ,  yCenter+y);
         setPixel( xCenter - x,   yCenter + y);
         setPixel( xCenter + x  , yCenter - y );
         setPixel( xCenter - x  , yCenter - y);
        if(p1 < 0)
        {
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dx =  2 * (ry * ry) * x;
            dy =  2 * (rx * rx) * y;
             p1 = p1 + dx - dy +(ry * ry);
        }
    }
    //region 02
    float p2 = (ry * ry )* ( x +  0.5) * ( x +  0.5) +  ( rx * rx) * ( y - 1) * ( y - 1) - (rx * rx )* (ry * ry);


    while(y > 0)
    {
         setPixel(xCenter + x  ,  yCenter+y);
         setPixel( xCenter - x,   yCenter + y);
         setPixel( xCenter + x  , yCenter - y );
         setPixel( xCenter - x  , yCenter - y);
        if(p2 > 0)
        {
            x = x;
            y = y - 1;
            dy = 2 * (rx * rx) * y;
            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dy = dy - 2 * (rx * rx) ;
            dx = dx + 2 * (ry * ry) ;
            p2 = p2 + dx -
            dy + (rx * rx);
        }
    }

}
void display()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0.0,1.0,0.0);
     glPointSize(2.0);


     ellipMidPointalgo();
     glFlush(); // send all output to the display
}

int main(int argc,char** argv)
{
    printf("Draw Ellipse Using Mid Point Theorem:  ");
    printf("\nEnter Center Of Ellipse  \n");
    printf("x = ");
    scanf("%d",&xCenter);
    printf("y = ");
    scanf("%d",&yCenter);

    printf("Enter a Semi Major Axix : ");
    scanf("%d",&rx);
    printf("Enter a Semi Minor Axis: ");
    scanf("%d",&ry);
	glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
	myinit();
    glutDisplayFunc(display);
    glutMainLoop();

}
