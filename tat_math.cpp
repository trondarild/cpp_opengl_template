#include <iostream>
#include <cmath> 
#include "tat_math.h"
#include "tat_utils.h"
using namespace std;

float* reset_array(float *r, int size) {
    for (int i=0; i < size; ++i)
        r[i] = 0;
    return r;
}

float sum(float *a, int size){
    float retval = 0;
    for (int i=0; i < size; ++i)
        retval += a[i];
    return retval;
}



float *
soft_max_exp(float *r, float *a, int size)
{
    // TODO check if vector op exists
    for (int i=0; i < size; ++i)
        r[i] = exp(a[i]);
    float s=0;
    for (int i=0; i < size; ++i)
        s += r[i];
    if(s>0){
        for (int i=0; i < size; ++i)
            r[i] = r[i]/s;
    }
    else
        reset_array(r, size);
    return r;
}

float *
soft_max_pw(float *r, float *a, float pw, int size)
{
    // TODO check if vector op exists
    for (int i=0; i < size; ++i)
        r[i] = pow(a[i], 2);
    float s=0;
    for (int i=0; i < size; ++i)
        s += r[i];
    if(s>0){
        cout << "s: " << s << "\n";
        for (int i=0; i < size; ++i)
            r[i] = r[i]/s;
    }
    else
        reset_array(r, size);
    return r;
}

float random(float low, float high){
    return low + (high-low)*((float)rand()/RAND_MAX);
}

float* random(float low, float high, int sz){
    float *retval = zeros(sz);
    for (int i = 0; i < sz; i++)
    {
        retval[i] = random(low, high);
    }
    return retval;
    
}
float** random(float low, float high, int sx, int sy){
    float **retval = zeros(sx, sy);
    for (int j = 0; j < sy; j++)
    {
        for (int i = 0; i < sx; i++)
        {
            retval[j][i] = random(low, high);
        }
    }
    return retval;
}

float **rand_topology(float fill, int sx, int sy){
    float **retval = zeros(sx, sy);
    for (int j = 0; j < sy; j++)
    {
        for (int i = 0; i < sx; i++)
        {
            if(random(0.f, 1.f) < fill) retval[j][i]  = 1.f;
        }
        
    }
    return retval;    
}

float **apply_rand_topology(float** matrix, float fill, int sx, int sy){
    reset_array(matrix[0], sx*sy);
    for (int j = 0; j < sy; j++)
    {
        for (int i = 0; i < sx; i++)
        {
            matrix[j][i] = random(0, 1) < fill ? 1.f : 0.f;
        }
    }
    return matrix;
    
}