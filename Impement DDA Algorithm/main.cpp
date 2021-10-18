//Implementing the DDA Algorithm for straight line
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;

void drawline(void)
{
  float dy,dx,len,x,y,Xin,Yin;
  dx=x2-x1;
  dy=y2-y1;

   if(abs(dx)>abs(dy))
  {
   len = abs(dx);
  }
  else{
  len = abs(dy);

  }
  Xin = dx/len;
  Yin = dy/len;

 x=x1;
 y=y1;
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();

  for (int i=1 ;i<=len;i++)
 {
 x= x + Xin;
 y= y + Yin;

 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
 }

 glFlush();
}

void init(void)
{
 glClearColor(0.7,0.7,0.7,0.7);
 glPointSize(4.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
 printf("Enter the Starting coordinates : ");
 scanf("%f%f",&x1,&y1);
 printf("Enter the end coordinates : ");
 scanf("%f%f",&x2,&y2);

 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100,100);
 glutCreateWindow ("DDA Line Algorithm");
 init();
 glutDisplayFunc(drawline);
 glutMainLoop();

return 0;
}
