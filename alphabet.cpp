#include "tat_graphics.h"
#include "tat_utils.h"
#include <iostream>

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

float mx = 0.5;


void draw_a(){
    // set up coords
    int numvtx = 10;
    float v[][2] = {{-mx, mx},
                {mx, mx},
                {mx, mx},
                {mx, -mx},
                {mx, -mx},
                {-mx, -mx},
                {-mx, -mx},
                {-mx, 0},
                {-mx, 0},
                {mx, 0}};
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_b(){
    int numvtx = 8;
    float v[][2] = {
                {-mx, mx},
                {-mx, -mx},
                {-mx, -mx},
                {mx, -mx},
                {mx, -mx},
                {mx, 0},
                {mx, 0},
                {-mx, 0},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_c(){
    int numvtx = 6;
    float v[][2] = {
                {mx, mx},
                {-mx, mx},
                {-mx, mx},
                {-mx, -mx},
                {-mx, -mx},
                {mx, -mx},
                
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_d(){
    int numvtx = 8;
    float v[][2] = {
                {mx, mx},
                {mx, -mx},
                {mx, -mx},
                {-mx, -mx},
                {-mx, -mx},
                {-mx, 0},
                {-mx, 0},
                {mx, 0},
                
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_e(){
    glRotatef(180.f, 0, 0, 1.f);
    draw_a();
    
}