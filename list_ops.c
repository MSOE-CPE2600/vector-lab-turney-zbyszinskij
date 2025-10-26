/*
* Filename: list_ops.c
* Author: James Zbyszinski
* Class: CPE2600
* Section: 111
* Date: 10/1/2025
* Description: Provides definitions for functions used in calculator
*/

#include <stdio.h>
#include <string.h>

#include "list_ops.h"
#include "vector.h"

//Display Menu
void help_menu(){

    printf(" Vector Operations:\n   Addition: +\n   Subtraction: -\n   Scaler Multiplication: *\n");
    printf("   Dot Product: .\n   Cross Product: x\n");
    printf(" Commands:\n   quit: quits program\n   list: lists all vectors\n");
    printf("   clear: clears all vectors in the list\n   <vector name>: prints vector info\n");
    printf("   save <file_name>: write list to a file named by the user (remember to add the extension)\n");
    printf("   load <file_name>: load list from a file named by user (remember to add the extension)\n");
    printf(" Declaring new vetors:\n");
    printf("   name = x y: sets vector with given x and y values but set z equal to 0\n");
    printf("   name = x y z: sets vector with given x, y, and z values\n");

}


//Clear Vector List
void clear(vector vect_list[], int num_vects){

    for(int i = 0; i < num_vects; i++){

        strcpy(vect_list[i].name, "0");
        vect_list[i].x = 0.0;
        vect_list[i].y = 0.0;
        vect_list[i].z = 0.0;

    }
}

//Find vector in vector list
int find_vect(vector vect_list[], char name[], int num_vects){

    for(int i = 0; i < num_vects; i++){
        if(!strcmp(vect_list[i].name, name)){
            return i;
        }
    }

    return -1;
}

//Display information about passed in vector
void vect_info(vector *vect){
    fprintf(stdout, "%4s = %f, %f, %f\n", vect->name, vect->x, vect->y, vect->z);
}

//Display all vectors stored in the vector list
void list_vects(vector vect_list[], int num_vects){
    
    for(int i = 0; i < num_vects; i++){
        fprintf(stdout, "%4s = %f, %f, %f\n", vect_list[i].name, vect_list[i].x, vect_list[i].y, vect_list[i].z);
    }
}
