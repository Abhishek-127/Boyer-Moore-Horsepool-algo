#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/timeb.h>
#include "q1.h"

void  part1(char *filename, FILE *fptr){

    char *anagram_test;
    char *str;
    char *temp;
    anagram_test = createString();
    str = createString();
    temp = createString();
    fptr = fopen(filename, "r");

    // get a string;
    printf("Please enter the string you wish to  find anagrams for: ");
    printf("\n");

    fgets(anagram_test, 100, stdin);
    if(anagram_test == NULL){
        printf("Error!  Please enter a string\n");
        while(anagram_test == NULL){
            fgets(anagram_test, 100, stdin);
            if(isspace(anagram_test[strlen(anagram_test) -1])){
                anagram_test[strlen(anagram_test) - 1] = '\0';
            }
            
        }
    }

    if(isspace(anagram_test[strlen(anagram_test) -1])){
        anagram_test[strlen(anagram_test) - 1] = '\0';
    }

    int length_anagram;
    length_anagram = strlen(anagram_test);

    // count the number of lines;
    int num_lines = 0;
    while(fgets(str, 200,fptr)){
        num_lines++;
    }
    fclose(fptr);
    int num_numbers  = num_lines * 5;
  //  printf("There are %d\n", num_numbers);

    fptr = fopen(filename, "r");

    int i;
    int counter = 0;
    int anagram_count = 0;

    struct timeb start, end;
    ftime(&start);

    for(i = 0; i < num_numbers; i++){
        fscanf(fptr, "%s", str);

        int length_string;
        length_string = 0;
        if(str !=  NULL){
            length_string = strlen(str);
        }

        counter = 0;
        bool flag = false;

        temp = strcpy(temp,str);

        if(length_string == length_anagram){
            for(size_t i = 0; i < length_anagram; i++){
                flag = true;
                for(size_t j = 0; j < length_string; j++){
                    if(anagram_test[i] == temp[j]){
                        flag  = false;
                        temp[j] = '#';
                        counter++;
                        break;
                    }
                }
                if(flag == true){
                    break;
                }
            }
            if(flag == false){
                printf("%s is an anagram\n", str);
                anagram_count++;
            }
        }

    }
    fclose(fptr);

     ftime(&end);
     int secs = 0;
     secs = end.time - start.time;
     //secs *= 1000;
     int mills = 0;
     mills = end.millitm - start.millitm;
     if(mills < 0){
         mills = mills * -1;
     }
     printf("\n------------------------------------------------------\n");
     printf("There are %d Anagrams of the string %s\n",  anagram_count, anagram_test);
     printf("Time is %d.%d seconds\n", secs, mills);
     printf("--------------------------------------------------------\n");

     free(anagram_test);
     free(str);
     free(temp);
}

char* createString(){
    char *str;
    str = calloc(250, sizeof(char));
    return str;
}

int calcDiff(void *a, void *b){
    int time = 0;
    
    return time;
}