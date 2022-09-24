#include <vector>


typedef std::vector<float> FloatList;

float *create_array(int size);
float **create_matrix(int sizex, int sizey);
float* zeros(int size);
float** zeros(int x, int y);
float* ones(int size);
void destroy_array(float *a);
void destroy_matrix(float **a);
void rgb_hsv(double &rh, double &rs, double &rv, double r, double g, double b );
void rgb2hsv(float &rh, float &rs, float &rv, double r, double g, double b );
void hsv_rgb(int &rr, int &rg, int &rb, float H, float S,float V);
float hue(int r, int g, int b);
float hue(int *rgb);
float saturation(int r, int g, int b);
float saturation(int *rgb);
void print_matrix(const char * name, float ** m, int sizex, int sizey, int decimals);
float map(float a, float from_min, float from_max, float to_min, float to_max);
void println(std::string s);
void println();
void print_array(std::string s, FloatList *l);
void print_array(float *a, int size);
