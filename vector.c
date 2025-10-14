/*
* Filename: vector.c
* Author: James Zbyszinski
* Class: CPE2600
* Section: 111
* Date: 10/1/2025
* Description: Vector definitions
*/


#include"vector.h"

#include<stdlib.h>
#include<string.h>

vector* new_vect(vector *save, char name[], float x, float y, float z){

    strcpy(save->name, name);
    save->x = x;
    save->y = y;
    save->z = z;

    return save;
}

vector add(vector *a, vector *b){

    vector result;

    result.x = a->x + b->x;
    result.y = a->y + b->y;
    result.z = a->z + b->z;

    return result;

}

vector sub(vector *a, vector *b){

    vector result;

    result.x = a->x - b->x;
    result.y = a->y - b->y;
    result.z = a->z - b->z;

    return result;
}

vector scale_mult(float x, vector *vect){

    vector result;

    result.x = x * vect->x;
    result.y = x * vect->y;
    result.z = x * vect->z;

    return result;
}

float dot_prod(vector *a, vector *b){
    
    float x_product;
    float y_product;
    float z_product;
    float result;

    x_product = a->x * b->x;
    y_product = a->y * b->y;
    z_product = a->z * b->z;

    result = x_product + y_product + z_product;

    return result;

}

vector cross_prod(vector *a, vector *b){

    vector result;
    float resx;
    float resy;
    float resz;

    resx = (a->y * b->z) - (a->z * b->y);
    resy = (a->z * b->x) - (a->x * b->z);
    resz = (a->x * b->y) - (a->y * b->x);

    result.x = resx;
    result.y = resy;
    result.z = resz;

    return result;
}