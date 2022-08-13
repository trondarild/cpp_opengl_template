/******************************************************************************


*******************************************************************************/

#include <iostream>
#include <string>
#include "tat_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#ifdef MACOSX
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include "tat_graphics.h"


float t = 0;
void setup()
{
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Test");
    
}

void update()
{
    t += 1;
    glutPostRedisplay();
}

void draw()
{
    glClearColor(0.2, 0.2, 0.2, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_LINE_SMOOTH);

    glLineWidth(4.f);
    glPushMatrix();
        glColor3f(0.80f, 0.80f, 0.80f);
        circle(0, 0, 0.25);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
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