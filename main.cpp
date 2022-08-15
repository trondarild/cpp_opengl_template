/******************************************************************************


*******************************************************************************/

#include <iostream>
#include <string>
#include "tat_math.h"
#include "tat_utils.h"
#include "tat_graphics.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#endif


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
        char *title = "hello";
        
        //glColor3i(200, 200, 200);
        //square(0, 0, 0.25);
        float **top = create_matrix(2, 1);
        top[0][0] = 0.6;
        top[0][1] = 0.7;

        drawColGrid(0, 0, 0.1, 0.025, "", top, 2, 1);
        destroy_matrix(top);
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