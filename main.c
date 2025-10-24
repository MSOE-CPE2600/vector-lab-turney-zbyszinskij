/*
* Filename: main.c
* Author: James Zbyszinski
* Class: CPE2600
* Section: 111
* Date: 10/1/2025
* Description: Main program
* Compile instructions: Makefile
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"
#include "list_ops.h"

int main(int argc, char* argv[]){

    int vect_array_size = 10;

    char input[50];
    char token[5][15]; 
    vector *vectors = malloc(vect_array_size * sizeof(vector));

    clear(vectors, vect_array_size);
    int num_vects = 0;

    help_menu();
    printf("Enter help to see this menu again or quit to quit the program\n");

    while(strcmp(token[0], "quit")){

        char *token_char;

        printf("vect_calc >> ");
        fgets(input, 50, stdin);

        int token_index = 0;
        token_char = strtok(input, " ");
        strcpy(token[token_index], token_char);

        while(token_char != NULL && token_index <= 5){

            token_char = strtok(NULL, " ");

            if(token_char != NULL){
               token_index++;
               strcpy(token[token_index], token_char); 
            }
        }

        // Remove the new line character from the last token
        token[token_index][strlen(token[token_index])-1] = '\0';

        if(token_index == 0){

            //Check for commands
            if(!strcmp(token[0], "help")){
                help_menu();
            } 
            else if(!strcmp(token[0], "clear")){
                clear(vectors, vect_array_size);
                num_vects = 0;
            } 
            else if(!strcmp(token[0], "list")){
                list_vects(vectors, vect_array_size);
            }
            else{

                int index = find_vect(vectors, token[0], num_vects);

                if(strcmp(token[0], "quit") && index == -1){
                    fprintf(stdout, "command or vector not found\n");
                } 
                else if(strcmp(token[0], "quit")){
                    vect_info(&vectors[index]);
                }

            }
        }
        else if (token_index == 1){
            if(!strcmp(token[0], "save")){

                FILE *save_file;
                
                save_file = fopen(strcat(token[1], ".csv"), "w");

                for(int i = 0; i < num_vects; i++){
                    vector save_vector = vectors[i];
                    if (i != num_vects - 1){
                        fprintf(save_file, "%s, %f, %f, %f\n",
                            save_vector.name, save_vector.x, save_vector.y, save_vector.z);
                    }
                    else{
                        fprintf(save_file, "%s, %f, %f, %f",
                        save_vector.name, save_vector.x, save_vector.y, save_vector.z);
                    }
                }

                fclose(save_file);

            }
            else if(!strcmp(token[0], "load")){
                FILE *load_file = fopen(strcat(token[1], ".csv"), "r");
                if(load_file != NULL){
                    clear(vectors, vect_array_size);
                    num_vects = 0;
                    int line_index = 0;
                    while(feof(load_file) == 0){
                        fgets(input, 50, load_file);
                        token_index = 0;
                        token_char = strtok(input, ",");
                        strcpy(token[token_index], token_char);
                        while(token_char != NULL && token_index < 5){
                            token_char = strtok(NULL, ",");
                            if(token_char != NULL){
                                token_index++;
                                strcpy(token[token_index], token_char);
                            }
                        }
                    // remove new line char from last token
                    token[token_index][strlen(token[token_index])-1] = '\0';
                    float x = atof(token[1]);
                    float y = atof(token[2]);
                    float z = atof(token[3]);
                    if(num_vects % vect_array_size == 0){
                        vectors = realloc(vectors, (num_vects + vect_array_size) * sizeof(vector));
                    }
                    new_vect((vectors + line_index), token[0], x, y, z);
                    num_vects++;
                    line_index++;
                    }
                    fclose(load_file);
                    list_vects(vectors, num_vects);
                } else{
                    fprintf(stdout, "file not found\n");
                }
            }
            else{
                printf("Invalid command\n");
            }
        }
        else if(token_index == 2){

            int index1 = find_vect(vectors, token[0], num_vects);
            int index2 = find_vect(vectors, token[2], num_vects);

            vector answer = {"ans", 0, 0, 0};

            if(index1 != -1 && index2 != -1){
                
                if(!strcmp(token[1], "+")){
                    answer = add(&vectors[index1], &vectors[index2]);
                    strcpy(answer.name, "ans");
                    vect_info(&answer);
                } 
                else if(!strcmp(token[1], "-")){
                    answer = sub(&vectors[index1], &vectors[index2]);
                    strcpy(answer.name, "ans");
                    vect_info(&answer);
                } 
                else if(!strcmp(token[1], ".")){
                    float dot = dot_prod(&vectors[index1], &vectors[index2]);
                    printf(" ans = %f\n", dot);
                } 
                else if(!strcmp(token[1], "x")){
                    answer = cross_prod(&vectors[index1], &vectors[index2]);
                    strcpy(answer.name, "ans");
                    vect_info(&answer);
                } 
                else{
                    printf("invalid no save operand\n");
                }

            } 
            else if((index1 != -1 || index2 != -1) && !strcmp(token[1], "*")){

                    if(index1 != -1){
                        float scale = atof(token[2]);
                        answer = scale_mult(scale, &vectors[index1]);
                        strcpy(answer.name, "ans");
                        vect_info(&answer);
                    } 
                    else if(index2 != -1){
                        float scale = atof(token[0]);
                        answer = scale_mult(scale, &vectors[index2]);
                        strcpy(answer.name, "ans");
                        vect_info(&answer);
                    } 
                    else{
                        printf("invalid no save scale\n");
                    }
            } 
            else{
                fprintf(stdout, "invalid no save calc\n");
            }

        } 
        else if(token_index == 3){

            int ans_index = find_vect(vectors, token[0], num_vects);
            vector *answer = NULL;

            if(ans_index == -1){
                if(num_vects < vect_array_size){
                    answer = &vectors[num_vects];
                    strcpy(vectors[num_vects].name, token[0]);
                    num_vects++;
                }
            } 
            else{
                answer = &vectors[ans_index];
            }

            if (answer == NULL){

                if (num_vects >= vect_array_size){
                    int new_array_size = vect_array_size + 10;
                    vector* temp_array = realloc(vectors,  new_array_size * sizeof(vector));
                    if (temp_array != NULL){
                        vectors = temp_array;
                        vect_array_size = new_array_size;
                    }
                    else{
                        printf("Failed to reallocate memory");
                    }
                }

                ans_index = find_vect(vectors, token[0], num_vects);

                if(ans_index == -1){
                    if(num_vects < vect_array_size){
                        answer = &vectors[num_vects];
                        strcpy(vectors[num_vects].name, token[0]);
                        num_vects++;
                    }
                } 
                else{
                    answer = &vectors[ans_index];
                }
            }

             
            if (answer!= NULL){
                float x = atof(token[2]);
                float y = atof(token[3]);

                if(num_vects <= vect_array_size){ 

                    if(!(x == 0 && y == 0) && !strcmp(token[1], "=")){
                        answer->x = x;
                        answer->y = y; 
                        answer->z = 0;
                        vect_info(answer);
                    } 
                    else{
                        printf("invalid assign command z=0\n");
                    }
                }
            }
            else{
                printf("Something went wrong\n");
            }

        } 
        else if(token_index == 4){

            int index1 = find_vect(vectors, token[2], num_vects);
            int index2 = find_vect(vectors, token[4], num_vects);
            int ans_index = find_vect(vectors, token[0], num_vects);

            vector *answer = NULL;

            if(ans_index == -1){
                if(num_vects < vect_array_size){
                    answer = &vectors[num_vects];
                    strcpy(vectors[num_vects].name, token[0]);
                    num_vects++;
                }
            } 
            else{
                answer = &vectors[ans_index];
            }

            if (answer == NULL){
                if (num_vects >= vect_array_size){
                    int new_array_size = vect_array_size + 10;
                    vector* temp_array = realloc(vectors,  new_array_size * sizeof(vector));
                    if (temp_array != NULL){
                        vectors = temp_array;
                        vect_array_size = new_array_size;
                        printf("size: %d\n", vect_array_size);
                    }
                    else{
                        printf("Failed to reallocate memory");
                    }
                }

                ans_index = find_vect(vectors, token[0], num_vects);

                if(ans_index == -1){
                    if(num_vects < vect_array_size){
                        answer = &vectors[num_vects];
                        strcpy(vectors[num_vects].name, token[0]);
                        num_vects++;
                    }
                } 
                else{
                    answer = &vectors[ans_index];
                }
            }

            if(answer != NULL){

                if(num_vects <= vect_array_size){
                
                    if(!strcmp(token[1], "=") && index1 == -1 && index2 == -1){
                        float x = atof(token[2]);
                        float y = atof(token[3]);
                        float z = atof(token[4]);
                        answer->x = x;
                        answer->y = y;
                        answer->z = z;
                        vect_info(answer);
                    }
                    else if(index1 != -1 || index2 != -1){
                    
                        vector temp_result;

                        if(index1 != -1 && index2 != -1){ 
                            if(!strcmp(token[3], "+")){
                                temp_result = add(&vectors[index1], &vectors[index2]); 
                            } 
                            else if(!strcmp(token[3], "-")){
                                temp_result = sub(&vectors[index1], &vectors[index2]); 
                            } 
                            else if(!strcmp(token[3], "x")){
                                temp_result = cross_prod(&vectors[index1], &vectors[index2]); 
                            } 
                            else{
                                printf("invalid save operand\n");
                            }
                        }
                        else if(!strcmp(token[3], "*")){ 
                            if(index1 != -1){
                                float scale = atof(token[4]);
                                temp_result = scale_mult(scale, &vectors[index1]);
                            }
                            else if(index2 != -1){
                                float scale = atof(token[2]);
                                temp_result = scale_mult(scale, &vectors[index2]);
                            }
                            else{
                                printf("invalid save scale\n");
                            }
                        }
                        else{
                            printf("invalid save command\n");
                        }
                    
                        answer->x = temp_result.x;
                        answer->y = temp_result.y;
                        answer->z = temp_result.z;

                        vect_info(answer);
                    } 
                    else{
                        printf("Invalid input. Please try again.\n");
                    }
                }

            }
            else{
                printf("Something went wrong\n");
            }
        } 
        else{
            printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}