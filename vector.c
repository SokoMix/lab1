#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vector3D *create_vec(void *x, void *y, void *z, Exception *exception)
{
    Vector3D *newvec = (Vector3D *) malloc(sizeof(Vector3D));
    if (!newvec)
        (*exception) = MEM_ER;
    newvec->x = x;
    newvec->y = y;
    newvec->z = z;
    return newvec;
}

void *sum_argument(void *arg1, void *arg2, int type, Exception *exception)
{
    Exception er = OK;
    if (!arg1 || !arg2) er = ARG_EMPTY;
    void *res;
    if (type == INT)
    {
        int *sum = (int *)malloc(sizeof(int));
        if (!sum)
            er = MEM_ER;
        (*sum) = *((int *)arg1) + *((int *)arg2);
        res = (void *) sum;
    }
    else if (type == FLT)
    {
        float *sum = (float *)malloc(sizeof(float));
        if (!sum)
            er = MEM_ER;
        (*sum) = *((float *)arg1) + *((float *)arg2);
        res = (void *) sum;
    }
    if (*exception == OK && er != OK) 
        (*exception) = er;
    return res;
}

void *dot_argument(void *arg1, void *arg2, int type, Exception *exception)
{
    Exception er = OK;
    if (!arg1 || !arg2) er = ARG_EMPTY;
    void *res;
    if (type == INT)
    {
        int *product = (int *)malloc(sizeof(int));
        if (!product)
            er = MEM_ER;
        (*product) = *((int *)arg1) * *((int *)arg2);
        res = (void *)product;
    }
    else if (type == FLT)
    {
        float *product = (float *)malloc(sizeof(float));
        if (!product)
            er = MEM_ER;
        (*product) = *((float *)arg1) * *((float *)arg2);
        res = (void *)product;
    }
    if (*exception == OK && er != OK) 
        (*exception) = er;
    return res;
}

Vector3D *vec_sum(Vector3D *vec1, Vector3D *vec2, int type, Exception *exception)
{
    (*exception) = OK;
    Exception er = OK;
    Vector3D *newvec = create_vec(sum_argument(vec1->x, vec2->x, type, &er), sum_argument(vec1->y, vec2->y, type, &er), sum_argument(vec1->z, vec2->z, type, &er), &er);
    if (er != OK)
        (*exception) = er;
    return newvec;
}

void *vec_scalarproduct(Vector3D *vec1, Vector3D *vec2, int type, Exception *exception)
{
    Exception er = OK;
    void *res;
    if (!vec1 || !vec2)
        er = VEC_EMPTY;
    if (type == INT)
    {
        int *product = (int *)malloc(sizeof(int));
        if (!product)
            er = MEM_ER;
        (*product) = *((int *)vec1->x) * *((int *)vec2->x);
        (*product) += *((int *)vec1->y) * *((int *)vec2->y);
        (*product) += *((int *)vec1->z) * *((int *)vec2->z);
        res = (void *)product;
    }
    else if (type == FLT)
    {
        float *product = (float *)malloc(sizeof(float));
        if (!product)
            er = MEM_ER;
        (*product) = *((float *)vec1->x) * *((float *)vec2->x);
        (*product) += *((float *)vec1->y) * *((float *)vec2->y);
        (*product) += *((float *)vec1->z) * *((float *)vec2->z);
        res = (void *)product;
    }
    (*exception) = er;
    return res;
}

void vectorclear(Vector3D *vec)
{
    free(vec->x);
    free(vec->y);
    free(vec->z);
    free(vec);
}

int print_vec(Vector3D *vec, int type)
{
    if (!vec)
        return VEC_EMPTY;
    if (type == INT)
    {
        int x, y, z;
        x = *((int *)(vec->x));
        y = *((int *)(vec->y));
        z = *((int *)(vec->z));
        printf("x: %d y: %d z: %d\n", x, y, z);
    }
    else if (type == FLT)
    {
        float x, y, z;
        x = *((float *)(vec->x));
        y = *((float *)(vec->y));
        z = *((float *)(vec->z));
        printf("x: %f y: %f z: %f\n", x, y, z);
    }
    return 0;
}
