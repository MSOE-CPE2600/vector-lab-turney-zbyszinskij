#include "vector.h"

#ifndef list_ops_h
#define list_ops_h

void help_menu();
void clear(vector vect_list[], int num_vects);
int find_vect(vector vect_list[], char name[], int num_vects);
void vect_info(vector *vect);
void list_vects(vector vect_list[], int num_vects);

#endif