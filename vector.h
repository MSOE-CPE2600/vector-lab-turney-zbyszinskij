/*
* Filename: vector.h
* Author: James Zbyszinski
* Class: CPE2600
* Section: 111
* Date: 10/1/2025
* Description: Vector structure
*/

#ifndef vector_h
#define vector_h


typedef struct {
  char name[10];
  float x;
  float y;
  float z;
} vector;

vector* new_vect(vector *save, char name[], float x, float y, float z);
vector add(vector *a, vector *b);
vector sub(vector *a, vector *b);
vector scale_mult(float x, vector *vect);
float dot_prod(vector *a, vector *b);
vector cross_prod(vector *a, vector *b);



#endif