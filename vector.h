#ifndef VECTOR
#define VECTOR
#define INT 1
#define FLT 2
#define SUM 1
#define SCALAR 2

typedef struct Vector3D
{
    void *x, *y, *z;
} Vector3D;

typedef enum Exception
{
    OK,
    MEM_ER,
    VEC_EMPTY,
    ARG_EMPTY
} Exception;

Vector3D *create_vec(void *x, void *y, void *z, Exception *exception);
int print_vec(Vector3D *vec, int type);
Vector3D *vec_sum(Vector3D *vec1, Vector3D *vec2, int type, Exception *exception);
void *vec_scalarproduct(Vector3D *vec1, Vector3D *vec2, int type, Exception *exception);
void vectorclear(Vector3D *vec);

#endif