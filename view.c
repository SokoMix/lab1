#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void readcoordinates(void **x, void **y, void **z, int type, const char* viv)
{
    if (type == INT)
    {
        int *x1, *y1, *z1;
        x1 = (int *)malloc(sizeof(int));
        y1 = (int *)malloc(sizeof(int));
        z1 = (int *)malloc(sizeof(int));
        printf("%s", viv);
        int er = scanf("%d%d%d", x1, y1, z1);
        while (er != 3)
        {
            printf("Input error. Try one more time.\n");
            scanf("%*[^\n]");
            printf("%s", viv);
            er = scanf("%d%d%d", x1, y1, z1);
        }
        (*x) = (void *)(x1);
        (*y) = (void *)(y1);
        (*z) = (void *)(z1);
    }
    else if (type == FLT)
    {
        float *x1, *y1, *z1;
        x1 = (float *)malloc(sizeof(float));
        y1 = (float *)malloc(sizeof(float));
        z1 = (float *)malloc(sizeof(float));
        printf("%s", viv);
        int er = scanf("%f%f%f", x1, y1, z1);
        while (er != 3)
        {
            printf("Input error. Try one more time.\n");
            scanf("%*[^\n]");
            printf("%s", viv);
            er = scanf("%f%f%f", x1, y1, z1);
        }
        (*x) = (void *)(x1);
        (*y) = (void *)(y1);
        (*z) = (void *)(z1);
    }
}

int view()
{
    Exception exc = OK;
    int type, action;
    void *res;
    Vector3D *vector1, *vector2, *vectorres;
    printf("Supported types of numbers:\n1) Integer\n2) Float\n");
    printf("Enter type: ");
    int er = scanf("%d", &type);
    while (er < 1 || type < 1 || type > 2)
    {
        printf("Input error. Try one more time.\n");
        scanf("%*[^\n]");
        printf("Enter type: ");
        er = scanf("%d", &type);
    }
    void *x1, *y1, *z1, *x2, *y2, *z2;
    readcoordinates(&x1, &y1, &z1, type, "Enter coordinates for first vector in format x, y, z: ");
    vector1 = create_vec(x1, y1, z1, &exc);
    if (exc != OK)
        return (int) exc;
    readcoordinates(&x2, &y2, &z2, type, "Enter coordinates for second vector in format x, y, z: ");
    vector2 = create_vec(x2, y2, z2, &exc);
    if (exc != OK)
        return (int) exc;
    printf("Choose action:\n1) Vectors sum\n2) Scalar product\nEnter action: ");
    er = scanf("%d", &action);
    while (er != 1 || action < 1 || action > 2)
    {
        printf("Input error. Try one more time.\n");
        scanf("%*[^\n]");
        printf("Choose action:\n1) Vectors sum\n2) Scalar product\nEnter action: ");
        er = scanf("%d", &action);
    }
    if (er == 1 && action >= 1 && action <= 2)
    {
        if (action == SUM)
        {
            vectorres = vec_sum(vector1, vector2, type, &exc);
            if (exc != OK)
                return (int) exc;
            printf("Sum of vectors:\n");
            print_vec(vectorres, type);
            vectorclear(vectorres);
        }
        else if (action == SCALAR)
        {
            if (type == INT)
            {
                res = vec_scalarproduct(vector1, vector2, type, &exc);
                if (exc != OK)
                    return (int) exc;
                printf("Scalar product: %d\n", (*(int *)res));
            }
            else
            {
                res = vec_scalarproduct(vector1, vector2, type, &exc);
                if (exc != OK)
                    return (int) exc;
                printf("Scalar product: %f\n", (*(float *)res));
            }
        }
    }
    vectorclear(vector1);
    vectorclear(vector2);
    return (int) exc;
}    