#ifndef Q1_H
#define Q1_H

#include <sys/timeb.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void  part1(char *filename, FILE *fptr);
void  part1b(char  *filename, FILE *fptr);

char* createString();

int calcDiff(void *a, void *b);

char *sortStr(char *str);

void sortArray(char **myArray, int num_numbers);
void swap(int* a, int* b);
int partition (int arr[], int low, int high);
//void quickSort(int arr[], int low, int high);
void quickSort(char str[], int min, int max) ;

typedef struct{
    int *number;
    int length;
}Ori;

void createOri();

typedef struct object
{
    int index;
    char *signature;
}Object;

Object *createObject();

void findAnagrams(char *str, Object *elements, char **array);
void sortObjects(Object element[], int min, int max) ;

#endif