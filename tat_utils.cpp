#include "tat_utils.h"

float* create_array(int size)
{
    return new float[size];
}

float* zeros(int size)
{
    float *retval = create_array(size);
    for (int i = 0; i < size; i++) retval[i] = 0.f;
    return retval;
}

float* ones(int size)
{
    float *retval = create_array(size);
    for (int i = 0; i < size; i++) retval[i] = 1.f;
    return retval;
}

void destroy_array(float *a)
{
    delete[] a;
}