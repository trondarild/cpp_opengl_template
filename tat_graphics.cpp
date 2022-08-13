#include "tat_graphics.h"
#include <cmath> 
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#endif

void circle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}
void circle(float x, float y, float r) {
        float i = 0.0f;
        
        glBegin(GL_TRIANGLE_FAN);
        
        glVertex2f(x, y); // Center
        for(i = 0.0f; i <= 360; i++)
                glVertex2f(r*cos(M_PI * i / 180.0) + x, r*sin(M_PI * i / 180.0) + y);
        
        glEnd();
}

void rect(float x1, float y1, float x2, float y2)
{
    glRectf(x1, y1, x2, y2);
}

void line(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
        glVertex3f(x1, y1, 0.0);
        glVertex3f(x2, y2, 0.0);
    glEnd();
}

void line(float *x, float *y, int size)
{
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<size; i++)
    {
        glVertex3f(x[i], y[i], 0.0);
    }
    glEnd();
}

void scatter(float *x, float *y, float r, int size)
{
    for(int i=0; i<size; i++)
    {
        circle(x[i], y[i], r);
    }
}