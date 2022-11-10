#include "tat_graphics.h"
#include "tat_utils.h"
#include "alphabet.h"
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

void square(float x, float y, float dim)
{
    rect(x, y, x+dim, y+dim);
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

void fill_hsv(float h, float s, float v)
{
    // conv to rgb
    int r, g, b;
    //std::cout<< "h: "<< h << ", s: " << s << ", v: " << v << "\n";
    hsv_rgb(r, g, b, h, s, v);
    //std::cout<< "r: "<< r << ", g: " << g << ", b: " << b << "\n";
    glColor3ub(r, g, b);
}

void fill(int grey)
{
    glColor3ub(grey, grey, grey);
}

void draw_col_grid(float x1, float y1, float dim, float margin, std::string title, float** top, int sizex, int sizey){
  /**
  x1 - topleft corner x
  y1 - topleft corner y
  dim - scale dim of individual square
  margin - between square margin
  top - array of values: pos and neg values drawn differently

  Example:
  float** top = zeros(2,2);
  drawColGrid(0, 0, 0.05, 0.025, "test", top, 2, 2);
  destroy_matrix(top);
  */
  int exccol[] = {217, 122, 122};
  int inhcol[]= {122, 122, 217};
  
  // TODO implement text
  glPushMatrix();

  glPushMatrix();
  glTranslatef(0.02, -0.04, 0);
  glPushAttrib(GL_COLOR_BUFFER_BIT);
  fill(150);
  glPushAttrib(GL_LINE_BIT);
  glLineWidth(0.03125f);
  text(title, 0,0);
  glPopAttrib();
  glPopAttrib();
  glPopMatrix();
  
  //glPushStyle();
  //colorMode(HSB);
  glPushMatrix();
  float y=y1;
  // float margin = 10;
  for(int j=0; j<sizey; j++){
    float x=x1;
    for(int i=0; i<sizex; i++){
      //pushStyle();
      if(top[j][i] > 0) fill_hsv(hue(exccol), saturation(exccol), top[j][i]);
      else if(top[j][i] < 0) fill_hsv(hue(inhcol), saturation(inhcol), top[j][i]);
      else fill(0);
      square(x, y, dim);
      //popStyle();
      x+= dim+margin;
    }
    y+= dim+margin;
  }
  glPopMatrix();
  glPopMatrix(); //text

}

void barchart_array(
  float xf1, 
  float yf1, 
  float xscale, 
  float yscale, 
  float *clr, 
  float aymax,
  std::string legend,
  float *data,
  int sz
  ){
  /**
   * @brief Draw a barchart array
   * xf1 - xpos
   * yf1 - ypos
   * xscale - 
   * yscale - 
   * clr - array of 3 with color
   * aymax - max value for y axis
   * data - array of data
   * sz - lenght of array
   * 
   * Example:
   * float* data = zeros(3);
   * data[0] = 0.1; data[1] = 0.2; data[3] = 0.5;
   * float* clr = zeros(3);
   * barchart_array(0, 0, 1, 1, clr, 1.f, "test", data, 3);
   * destroy_array(data);
   * destroy_array(clr);
   * 
   */

   glPushAttrib(GL_COLOR_BUFFER_BIT); 
   //Declare a float variabe for the max y axis value.
   float ymax=aymax;
   
   //Declare a float variable for the minimum y axis value.
   float ymin = 0;
   
   //Set the stroke color to a medium gray for the axis lines.
   //stroke(175);
   //glLineWidth(4.f);
   fill(170);

   
   //draw the axis lines.
   line(xf1-0.03,yf1-0.02,xf1+xscale,yf1-0.02);  
   line(xf1-0.03,yf1-0.02,xf1-.03,yf1+yscale); 
     
   //turn off strokes for the bar charts 
   //noStroke(); 
    
   //loop the chart drawing once.
   for (int c1 = 0; c1 < 1; c1++){  
   
     //Set the start x point value.
     float xfstart = xf1;  
     //Count the number of rows in the file.
     //for (int i = 0; i < lines.length; i++) {
       
       //For each line split values separated by columns into pieces.
       //String[] pieces = split(lines[i], ',');
       
       //Set the max Y axis value to be 10 greater than the max value in the pieces array.
       // ymax = 1.5* max(data);
       
       //Count the number of pieces in the array.
       float xcount = sz;
       
       //Draw the minimum and maximum Y Axis labels. 
       glPushAttrib(GL_COLOR_BUFFER_BIT);
       fill(150);
       glPushAttrib(GL_LINE_BIT);
       glLineWidth(0.03125f);
       // textFont(h1);
       //fill (100);
       //textAlign(RIGHT, CENTER);
       //text(int(ymax), xf1-8, yf1-yscale);
       //text(int(ymin), xf1-8, yf1);
       text(legend, xf1+0.087, yf1-0.058);
       glPopAttrib();
       glPopAttrib();
       
       //Draw each column in the data series.
       for (int i2 = 0; i2 < xcount; i2++) {
         
         //Get the column value and set it has the height.
         float yheight = data[i2];
         
         //Declare the variables to hold column height as scaled to the y axis.     
         float ypct;
         float ysclhght;
         
         //calculate the scale of given the height of the chart.
         ypct = yheight / ymax;
         
         //Calculate the scale height of the column given the height of the chart.
         ysclhght = yscale * ypct;
         
         //If the column height exceeds the chart height than truncate it to the max value possible.
         if(ysclhght > yscale){
           ysclhght = yscale;
         }
         
         //Determine the width of the column placeholders on the X axis.
         float xcolumns = xscale / xcount;
         
         //Set the width of the columns to 5 pixels less than the column placeholders.
         float xwidth = xcolumns - 0.05;
         
         //Set the fill color of the columns.
         fill_hsv (clr[0], clr[1], clr[2]);
         
         //Draw the columns to scale.
         //quad(xf1, yf1, xf1, yf1-ysclhght, xf1 + xwidth, yf1-ysclhght, xf1 + xwidth, yf1);
         rect(xf1, yf1, xf1 + xwidth, yf1+ysclhght);
         
         //Draw the labels.
         // textFont(l1);
         //textAlign(CENTER, CENTER);
         //fill (100);
         
         //Decide where the labels will be placed.
         /*
         if (labelplacement < 1) {
           //Above the columns.
           text(nf(data[i2], 0, 2), xf1 + (xwidth / 2), yf1 - (ysclhght + 8));
         } else {
           //Below the columns.
           text(data[i2], xf1 + (xwidth / 2), yf1 + 8);
         }
         */
         //increment the x point at which to draw a column.
         xf1 = xf1 + xcolumns;
       //}
    }
  }
  //popStyle();
  glPopAttrib();
}

void text(std::string s, float x, float y, float sx, float sy){
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(sx, sy, 0);
  draw_string(s);
  glPopMatrix(); 
}

void text(std::string s, float x, float y){
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(0.021, 0.025, 0);
  draw_string(s);
  glPopMatrix(); 
}