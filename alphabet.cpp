#include "alphabet.h"
#include "tat_utils.h"
#include <iostream>
#include <map>

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
float kern = 3*mx;
// every function pointer will be stored as this type
typedef void (*voidFunctionType)(void); 
std::map<char, voidFunctionType> alphabet_map;

void init_alphabet(){
    alphabet_map.insert(std::make_pair('a', (voidFunctionType) draw_a));
    alphabet_map.insert(std::make_pair('b', (voidFunctionType) draw_b));
    alphabet_map.insert(std::make_pair('c', (voidFunctionType) draw_c));
    alphabet_map.insert(std::make_pair('d', (voidFunctionType) draw_d));
    alphabet_map.insert(std::make_pair('e', (voidFunctionType) draw_e));
    alphabet_map.insert(std::make_pair('f', (voidFunctionType) draw_f));
    alphabet_map.insert(std::make_pair('g', (voidFunctionType) draw_g));
    alphabet_map.insert(std::make_pair('h', (voidFunctionType) draw_h));
    alphabet_map.insert(std::make_pair('i', (voidFunctionType) draw_i));
    alphabet_map.insert(std::make_pair('j', (voidFunctionType) draw_j));
    alphabet_map.insert(std::make_pair('k', (voidFunctionType) draw_k));
    alphabet_map.insert(std::make_pair('l', (voidFunctionType) draw_l));
    alphabet_map.insert(std::make_pair('m', (voidFunctionType) draw_m));
    alphabet_map.insert(std::make_pair('n', (voidFunctionType) draw_n));
    alphabet_map.insert(std::make_pair('o', (voidFunctionType) draw_o));
    alphabet_map.insert(std::make_pair('p', (voidFunctionType) draw_p));
    alphabet_map.insert(std::make_pair('q', (voidFunctionType) draw_q));
    alphabet_map.insert(std::make_pair('r', (voidFunctionType) draw_r));
    alphabet_map.insert(std::make_pair('s', (voidFunctionType) draw_s));
    alphabet_map.insert(std::make_pair('t', (voidFunctionType) draw_t));
    alphabet_map.insert(std::make_pair('u', (voidFunctionType) draw_u));
    alphabet_map.insert(std::make_pair('v', (voidFunctionType) draw_v));
    alphabet_map.insert(std::make_pair('w', (voidFunctionType) draw_w));
    alphabet_map.insert(std::make_pair('x', (voidFunctionType) draw_x));
    alphabet_map.insert(std::make_pair('y', (voidFunctionType) draw_y));
    alphabet_map.insert(std::make_pair('z', (voidFunctionType) draw_z));
    alphabet_map.insert(std::make_pair(' ', (voidFunctionType) draw_space));
    alphabet_map.insert(std::make_pair('_', (voidFunctionType) draw_underscore));
    alphabet_map.insert(std::make_pair('0', (voidFunctionType) draw_0));
    alphabet_map.insert(std::make_pair('1', (voidFunctionType) draw_1));
    alphabet_map.insert(std::make_pair('2', (voidFunctionType) draw_2));
    alphabet_map.insert(std::make_pair('3', (voidFunctionType) draw_3));
    alphabet_map.insert(std::make_pair('4', (voidFunctionType) draw_4));
    alphabet_map.insert(std::make_pair('5', (voidFunctionType) draw_5));
    alphabet_map.insert(std::make_pair('6', (voidFunctionType) draw_6));
    alphabet_map.insert(std::make_pair('7', (voidFunctionType) draw_7));
    alphabet_map.insert(std::make_pair('8', (voidFunctionType) draw_8));
    alphabet_map.insert(std::make_pair('9', (voidFunctionType) draw_9));
}

void draw_string(std::string s){
    for (char const &c: s) {
        alphabet_map[c]();
        glTranslatef(kern, 0, 0);
    }
}

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
    glPushMatrix();
    glRotatef(180.f, 0, 0, 1.f);
    draw_a();
    glPopMatrix();
    
}

void draw_f(){
    int numvtx = 6;
    float v[][2] = {
                {mx, mx},
                {-mx/2, mx},
                {mx, 0},
                {-mx, 0},
                {-mx/2, mx},
                {-mx/2, -mx},
                
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_g(){
    glPushMatrix();
    glRotatef(180.f, 0, 1.f, 0.f);
    draw_e();
    glPopMatrix();
    
}

void draw_h(){
    int numvtx = 6;
    float v[][2] = {
                {-mx, mx},
                {-mx, -mx},
                //{-mx, -mx},
                //{mx, -mx},
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

void draw_i(){
    int numvtx = 8;
    float v[][2] = {
                {0, mx},
                {0, mx*4/5},
                {-mx, mx*2/5},
                {0, mx*2/5},
                {0, mx*2/5},
                {0, -mx},
                {-mx, -mx},
                {mx, -mx},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_j(){
    int numvtx = 8;
    float v[][2] = {
                {0, mx},
                {0, mx*4/5},
                {-mx, mx*2/5},
                {0, mx*2/5},
                {0, mx*2/5},
                {0, -mx},
                {0, -mx},
                {-mx, -mx},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_k(){
    int numvtx = 6;
    float v[][2] = {
                {-mx, mx},
                {-mx, -mx},
                {mx, mx*2.f/5},
                {-mx, -mx*1.f/5},
                {-mx, -mx*1.f/5},
                {mx, -mx},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_l(){
    int numvtx = 6;
    float v[][2] = {
                {-mx, mx},
                {0, mx},
                {0, mx},
                {0, -mx},
                {0, -mx},
                {mx, -mx},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_m(){
    int numvtx = 8;
    float v[][2] = {
                {-mx, mx},
                {mx, mx},
                {-mx, mx},
                {-mx, -mx},
                {0, mx},
                {0, -mx},
                {mx, mx},
                {mx, -mx},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_n(){
    int numvtx = 6;
    float v[][2] = {
                {-mx, mx},
                {mx, mx},
                {-mx, mx},
                {-mx, -mx},
                //{0, mx},
                //{0, -mx},
                {mx, mx},
                {mx, -mx},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}
void draw_o(){
    int numvtx = 8;
    float v[][2] = {
                {-mx, mx},
                {mx, mx},
                {-mx, mx},
                {-mx, -mx},
                {mx, mx},
                {mx, -mx},
                {-mx, -mx},
                {mx, -mx},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_p(){
    glPushMatrix();
    glRotatef(180.f, 0,0,1.f);
    draw_d();
    glPopMatrix();
}

void draw_q(){
    glPushMatrix();
    glRotatef(180.f, 1,0,0.f);
    draw_d();
    glPopMatrix();
}

void draw_r(){
    int numvtx = 4;
    float v[][2] = {
                {mx, mx},
                {-mx, mx},
                {-mx, mx},
                {-mx, -mx},
                
                
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_s(){
    int numvtx = 10;
    float v[][2] = {
                {mx, mx},
                {-mx, mx},
                {-mx, mx},
                {-mx, 0},
                {-mx, 0},
                {mx, 0},
                {mx, 0},
                {mx, -mx},
                {mx, -mx},
                {-mx, -mx},
                
                
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_t(){
    int numvtx = 6;
    float v[][2] = {
                {-mx, mx*3/5},
                {mx, mx*3/5},
                {-mx/2, mx},
                {-mx/2, -mx},
                {-mx/2, -mx},
                {mx, -mx},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_u(){
    glPushMatrix();
    glRotatef(180.f, 1, 0, 0);
    draw_n();
    glPopMatrix();
}

void draw_v(){
    int numvtx = 4;
    float v[][2] = {
                {-mx, mx},
                {0, -mx},
                {0, -mx},
                {mx, mx},
                
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_w(){
    glPushMatrix();
    glRotatef(180.f, 1, 0, 0);
    draw_m();
    glPopMatrix();
}

void draw_x(){
    int numvtx = 4;
    float v[][2] = {
                {-mx, mx},
                {mx, -mx},
                {mx, mx},
                {-mx, -mx},
                
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_y(){
    int numvtx = 4;
    float v[][2] = {
                {-mx, mx},
                {0, 0},
                {mx, mx},
                {-mx, -mx},
                
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_z(){
    int numvtx = 6;
    float v[][2] = {
                {-mx, mx},
                {mx, mx},
                {mx, mx},
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

void draw_space(){};

void draw_underscore(){
    int numvtx = 2;
    float v[][2] = {
                {-mx, -mx},
                {mx, -mx},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_0(){
int numvtx = 10;
    float v[][2] = {
                {-mx, mx},
                {mx, mx},
                {-mx, mx},
                {-mx, -mx},
                {mx, mx},
                {mx, -mx},
                {-mx, -mx},
                {mx, -mx},
                {0, mx/4},
                {0, -mx/4},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();    
}

void draw_1(){
    int numvtx = 6;
    float v[][2] = {
                {-mx, mx},
                {0, mx},
                {0, mx},
                {0, -mx},
                {-mx, -mx},
                {mx, -mx},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_2(){
    glPushMatrix();
    glRotatef(180.f, 0, 1, 0);
    draw_s();
    glPopMatrix();
}

void draw_3(){
    glPushMatrix();
    glRotatef(-90.f, 0, 0, 1);
    draw_m();
    glPopMatrix();
}

void draw_4(){
    // set up coords
    glPushMatrix();
    glRotatef(180, 0, 0, 1);
    draw_h();
    glPopMatrix();
}

void draw_5(){
    draw_s();
}

void draw_6(){
    draw_b();
}

void draw_7(){
    int numvtx = 4;
    float v[][2] = {
                {-mx, mx},
                {mx, mx},
                {mx, mx},
                {-mx, -mx},
                
                
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_8(){
    int numvtx = 10;
    float v[][2] = {
                {-mx, mx},
                {mx, mx},
                {-mx, mx},
                {-mx, -mx},
                {mx, mx},
                {mx, -mx},
                {-mx, -mx},
                {mx, -mx},
                {mx, 0},
                {-mx, 0},
                };
    glBegin(GL_LINES);
        for(int j=0; j<numvtx; j++){
            glVertex3f(v[j][0], v[j][1], 0.0);
        }
        
    glEnd();
}

void draw_9(){
    // set up coords
    glPushMatrix();
    glRotatef(180, 0, 0, 1);
    draw_b();
    glPopMatrix();
}