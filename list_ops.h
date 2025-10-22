#include "vector.h"

#ifndef list_ops_h
#define list_ops_h

//Displays menu outlining commands and format for vector opperations
void help_menu();

//Clears vector list
void clear(vector vect_list[], int num_vects);

//Finds a vector in the vector list
int find_vect(vector vect_list[], char name[], int num_vects);

//Displays information about passed in vector
void vect_info(vector *vect);

//Lists all vectors in list
void list_vects(vector vect_list[], int num_vects);

#endif