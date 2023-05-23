#include <string>

void circle(float cx, float cy, float r, int num_segments);
void circle(float x, float y, float r);
void rect(float x1, float y1, float x2, float y2);
void square(float x, float y, float dim);
void line(float x1, float y1, float x2, float y2);
void line(float *x, float *y, int size);
void scatter(float *x, float *y, float r, int size);
void fill_hsv(float h, float s, float v);
void fill(int grey);
void draw_col_grid(float x1, float y1, float dim, float margin, std::string title, float** top, int sizex, int sizey);
void barchart_array(float xf1,  float yf1,  float xscale,  float yscale,  float *clr,  float aymax, std::string legend, float *data, int sz);
void text(std::string s, float x, float y, float sx, float sy);
void text(std::string s, float x, float y);
