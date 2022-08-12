/******************************************************************************


*******************************************************************************/

#include <iostream>
#include <string>
#include "tat_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//#ifndef MACOSX
//#include <GL/gl.h>
//#include <GL/glu.h>
//#else
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

//#endif
#include "tat_graphics.h"


float i = 0;
void setup()
{
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Test");
}

void update()
{
    i -= 1;
    glutPostRedisplay();
}

void draw()
{
    glClearColor(0.2, 0.2, 0.2, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_LINE_SMOOTH);

    glPushMatrix();
    //glScalef(0.5, 0.5, 0.5);
    //glTranslatef(0.1f, 0.1f, 0);
    glLineWidth(4.f);
    glPushMatrix();
        glTranslatef(cos(0.1*i), -0.25f, 0);
        //glRotatef(i, 0, 0, 1);
        glColor3f(0.90f, 0.350f, 0.90f);
        //glRectf(0, 0, 0.5, 0.5);
        circle(1, -1, 0.5, 100);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.25, -0.25, 0);
        glColor3f(0.9, 0.9, 0.2);
        rect(0, 0, 0.5, 0.5);
    glPopMatrix();

    glPushMatrix();
        //glTranslatef(-0.25, -0.25, 0);
        glColor3f(0.9, 0.5, 0.2);
        line(-0.5,-0.50, 0.5, 0.5);
    glPopMatrix();
    
    glPopMatrix(); // scale

    glFlush();
    glutSwapBuffers();
    //i+=1;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    setup();
    glutDisplayFunc(draw);
    glutIdleFunc(update);

    glutMainLoop();    
    return 0;
}