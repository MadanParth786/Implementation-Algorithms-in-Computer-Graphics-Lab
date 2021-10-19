#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include<conio.h>

double radius,a,b;
void init(){
    gluOrtho2D(-500,500,-500,500);

}
void bresenham_circle(void){
    double x,y,p;
    x=0;
    y=radius;
    p=1-radius;
    while(y>x){
        if(p<0){
            p+=(2*x)+3;
        }
        else{
            p+=(2*x)-(2*y)+5;
            y-=1;
        }
        x+=1;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(a+x,b+y);
        glVertex2f(a-x,b+y);
        glVertex2f(a+x,b-y);
        glVertex2f(a-x,b-y);
        glVertex2f(a+y,b+x);
        glVertex2f(a-y,b+x);
        glVertex2f(a+y,b-x);
        glVertex2f(a-y,b-x);
    }
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    printf("Implement Bresenham Algorithm For Circle: ");
    printf("\n");
    printf("Enter the centre of the circle:");
    scanf("%lf %lf",&a,&b);
    printf("Enter the radius of the circle:");
    scanf("%lf",&radius);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Bresenham Circle");
    gluOrtho2D(-500,500,-500,500);
    glutDisplayFunc(bresenham_circle);
    glutMainLoop();
    return 0;
}
