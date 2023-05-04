#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vector.h"

int checkvecsumint(int x1, int y1, int z1, int x2, int y2, int z2)
{
    Exception er = OK;
    int *x11, *y11, *z11;
    x11 = (int *)malloc(sizeof(int));
    y11 = (int *)malloc(sizeof(int));
    z11 = (int *)malloc(sizeof(int));
    (*x11) = x1;
    (*y11) = y1;
    (*z11) = z1;
    int *x12, *y12, *z12;
    x12 = (int *)malloc(sizeof(int));
    y12 = (int *)malloc(sizeof(int));
    z12 = (int *)malloc(sizeof(int));
    (*x12) = x2;
    (*y12) = y2;
    (*z12) = z2;
    Vector3D *vec1 = create_vec((void *)x11, (void *)y11, (void *)z11, &er);
    Vector3D *vec2 = create_vec((void *)x12, (void *)y12, (void *)z12, &er);
    Vector3D *res = vec_sum(vec1, vec2, INT, &er);
    if ((x1 + x2 == *((int *)res->x)) || (y1 + y2 == *((int *)res->y)) || (z1 + z2 == *((int *)res->z)))
    {
        return 0;
    }
    else
    {
        printf("Meow, test failed -_-\n");
        return 1;
    }
}

int checkvecsumfloat(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float *x11, *y11, *z11;
    Exception er = OK;
    x11 = (float *)malloc(sizeof(float));
    y11 = (float *)malloc(sizeof(float));
    z11 = (float *)malloc(sizeof(float));
    (*x11) = x1;
    (*y11) = y1;
    (*z11) = z1;
    float *x12, *y12, *z12;
    x12 = (float *)malloc(sizeof(float));
    y12 = (float *)malloc(sizeof(float));
    z12 = (float *)malloc(sizeof(float));
    (*x12) = x2;
    (*y12) = y2;
    (*z12) = z2;
    Vector3D *vec1 = create_vec((void *)x11, (void *)y11, (void *)z11, &er);
    Vector3D *vec2 = create_vec((void *)x12, (void *)y12, (void *)z12, &er);
    Vector3D *res = vec_sum(vec1, vec2, FLT, &er);
    if ((x1 + x2 == *((float *)res->x)) || (y1 + y2 == *((float *)res->y)) || (z1 + z2 == *((float *)res->z)))
    {
        return 0;
    }
    else
    {
        printf("Meow, test failed -_-\n");
        return 1;
    }
}

int checkscalarint(int x1, int y1, int z1, int x2, int y2, int z2)
{
    int *x11, *y11, *z11;
    Exception er = OK;
    x11 = (int *)malloc(sizeof(int));
    y11 = (int *)malloc(sizeof(int));
    z11 = (int *)malloc(sizeof(int));
    (*x11) = x1;
    (*y11) = y1;
    (*z11) = z1;
    int *x12, *y12, *z12;
    x12 = (int *)malloc(sizeof(int));
    y12 = (int *)malloc(sizeof(int));
    z12 = (int *)malloc(sizeof(int));
    (*x12) = x2;
    (*y12) = y2;
    (*z12) = z2;
    Vector3D *vec1 = create_vec((void *)x11, (void *)y11, (void *)z11, &er);
    Vector3D *vec2 = create_vec((void *)x12, (void *)y12, (void *)z12, &er);
    void *res = vec_scalarproduct(vec1, vec2, INT, &er);
    if (x1 * x2 + y1 * y2 + z1 * z2 == *(int *)res)
    {
        return 0;
    }
    else
    {
        printf("Meow, test failed -_-\n");
        return 1;
    }
}

int checkscalarfloat(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float *x11, *y11, *z11;
    Exception er = OK;
    x11 = (float *)malloc(sizeof(float));
    y11 = (float *)malloc(sizeof(float));
    z11 = (float *)malloc(sizeof(float));
    (*x11) = x1;
    (*y11) = y1;
    (*z11) = z1;
    float *x12, *y12, *z12;
    x12 = (float *)malloc(sizeof(float));
    y12 = (float *)malloc(sizeof(float));
    z12 = (float *)malloc(sizeof(float));
    (*x12) = x2;
    (*y12) = y2;
    (*z12) = z2;
    Vector3D *vec1 = create_vec((void *)x11, (void *)y11, (void *)z11, &er);
    Vector3D *vec2 = create_vec((void *)x12, (void *)y12, (void *)z12, &er);
    void *res = vec_scalarproduct(vec1, vec2, FLT, &er);
    if (x1 * x2 + y1 * y2 + z1 * z2 == *(float *)res)
    {
        return 0;
    }
    else
    {
        printf("Meow, test failed -_-\n");
        return 1;
    }
}

int main()
{
    int kol = 0, mist = 0;
    printf("Testing is started.\n");
    assert(checkvecsumint(1, 1, 1, 2, 2, 3)==0);
    assert(checkvecsumint(-1, 1, -100, 5, -2, -19)==0);
    assert(checkvecsumint(0, 0, 0, 0, 0, 0)==0);
    assert(checkvecsumint(-231, 983, -1145, 5213, -2984, -19234)==0);
    assert(checkscalarint(1, 1, 1, 2, 2, 3)==0);
    assert(checkscalarint(-1, 1, -100, 5, -2, -19)==0);
    assert(checkscalarint(0, 0, 0, 0, 0, 0)==0);
    assert(checkscalarint(-231, 983, -1145, 5213, -2984, -19234)==0);
    assert(checkscalarfloat(1.32, -3.12, 9.23, -0.1313, -4.21, -9.093)==0);
    assert(checkscalarfloat(1.0, -3.0, 9.0, 0.0, -4.0, -9.0)==0);
    assert(checkscalarfloat(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)==0);
    assert(checkscalarfloat(1.532, -213.213, -21.412, 31.42, -23.12, -98.12)==0);
    assert(checkvecsumfloat(1.32, -3.12, 9.23, -0.1313, -4.21, -9.093)==0);
    assert(checkvecsumfloat(1.0, -3.0, 9.0, 0.0, -4.0, -9.0)==0);
    assert(checkvecsumfloat(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)==0);
    assert(checkvecsumfloat(1.532, -213.213, -21.412, 31.42, -23.12, -98.12)==0);
    assert(checkvecsumint(rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__)==0);
    assert(checkvecsumint(rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__)==0);
    assert(checkvecsumint(rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__)==0);
    assert(checkscalarint(rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__)==0);
    assert(checkscalarint(rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__)==0);
    assert(checkscalarint(rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__, rand()%__INT_MAX__)==0);
    printf("Programm passed all tests\n");
}