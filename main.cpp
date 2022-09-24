/******************************************************************************


*******************************************************************************/

#include <iostream>
#include <string>
#include "tat_math.h"
#include "tat_utils.h"
#include "tat_graphics.h"
#include "tat_neurosim.h"
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
int dx = 10;
int dy = 10;
float sqsz = 0.05;
SpikingPopulation pop("TestPop", dx*dy, NeuronType::eIntrinsically_bursting, 10);
//SpikingPopulation pop;
float **topology;
void setup()
{
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Test");
    topology = rand_topology(0.7, dx, dy);
    //topology[1][1] = 0.5;
    pop.setInternalTopology(topology, dx, dy);
    
}

void update()
{
    t += 1;
    
    FloatList dir;
    dir.push_back(40.f);
    dir.push_back(20.f);
    pop.setDirect(dir);
    pop.tick();
    glutPostRedisplay();
}

void draw()
{

    glClearColor(0.2, 0.2, 0.2, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_LINE_SMOOTH);

    glLineWidth(4.f);
    glPushMatrix();
        //char *title = "hello";
        
        //glColor3i(200, 200, 200);
        //square(0, 0, 0.25);
        float **grid = zeros(dx, dy);
        int count = 0;
                for (int j = 0; j < dy; j++)
        {
            for (int i = 0; i < dx; i++)
            {
                grid[j][i] = map(pop.getOutput()[count++], -100.f, 80, 0, 1);
            }
            
        }
                
        //grid[0][0] = map(pop.getOutput()[0], -80.f, 80, 0, 1);
        //grid[0][1] = map(pop.getOutput()[1], -80.f, 80, 0, 1);;

        drawColGrid(0, 0, sqsz, 0.025, "", grid, dx, dy);
                destroy_matrix(grid);
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