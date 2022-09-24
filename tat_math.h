
#define PI           3.14159265358979323846 
#define TWO_PI 2*PI

float* reset_array(float *r, int size);
float sum(float *a, int size);

float *soft_max_exp(float *r, float *a, int size);
float *soft_max_pw(float *r, float *a, float pw, int size);
float random(float low, float high);
float* random(float low, float high, int sz);
float** random(float low, float high, int sx, int sy);
float **rand_topology(float fill, int sx, int sy);
float floor(float val, float floor);
float ceiling(float val, float ceiling);