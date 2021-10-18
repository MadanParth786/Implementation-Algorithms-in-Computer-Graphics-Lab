#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
float x1,y1,x2,y2;
void line()
{

    glClearColor(1,0,0,0);
    glColor3f(1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    float m,c,y;
    m=(y2-y1)/(x2-x1);
    c=y1-m*x1;
    glBegin(GL_POINTS);
    for(float x=x1;x<=x2;x+=0.002){
        y=m*x+c;
        glVertex2f(x,y);
    }
    glEnd();
    printf("m=%f\n",m);
    glFlush();
}


int main(int argc, char ** argv) {
     printf("Enter the Starting coordinates : ");
     scanf("%f%f",&x1,&y1);
     printf("Enter the end coordinates : ");
    scanf("%f%f",&x2,&y2);
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,400 );
    glutCreateWindow("Experiment 2_y=mx+c_line");
    glutDisplayFunc(line);
    glutMainLoop();
return 0;
}


