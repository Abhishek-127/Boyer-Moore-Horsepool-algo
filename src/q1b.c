#include "q1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


void  part1b(char  *filename, FILE *fptr){
   
    char *anagram_test;
    char *str;
    char *temp;
    //int anagram_count = 0;
    anagram_test = createString();
    str = createString();
    temp =  createString();

    int num_lines = 0;
    fptr = fopen(filename, "r");
    while(fgets(temp, 150, fptr)){
        num_lines++;
    }
    printf("The number of lines is %d\n", num_lines);
    fclose(fptr);
    int num_numbers = 0;
    num_numbers = num_lines * 5;

    // create the array of str;

    char **myArray;

    myArray = calloc(num_numbers + 10, sizeof(char*));
    for(int i = 0; i < num_numbers + 10; i++){
        myArray[i] = calloc(25, sizeof(char));
    }

    fptr = fopen(filename, "r");
    int counter = 0;
    for(int i = 0; i < num_numbers; i++){
        fscanf(fptr, "%s", str);
        str = sortStr(str);
        strcpy(myArray[counter], str);
        printf("*** %s\n", myArray[counter]);
        counter++;
        
    }
    // turn into ints;
    int *intArray;
    Ori *ori = calloc(30000, sizeof(Ori));
    for(int i = 0; i < 30000; i++){
        ori[i].number = calloc(1, sizeof(int));
        ori[i].number = NULL;
        ori[i].length = 0;
    }
    
    intArray = calloc(counter + 10, sizeof(int*));
    
    //sortArray(myArray, counter);

    for(int i = 0; i < counter; i++){
        ori[i].length = strlen(myArray[i]);
        intArray[i] = atoi(myArray[i]);
        ori[i].number = &intArray[i];
    }

    //quickSort(intArray, 0, 30000);

    printf("Please enter the string you wish to  find anagrams for: ");
    printf("\n");

    fgets(anagram_test, 100, stdin);
    anagram_test[strlen(anagram_test) - 1] = '\0';
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

    // sort the anagram word;
    
    anagram_test = sortStr(anagram_test);
    int l = strlen(anagram_test);
    int ana_to_find = atoi(anagram_test);
    

    struct timeb start, end;
    ftime(&start);
    int c = 0;
    for(int i = 0; i < 30000; i++){
        if(intArray[i] == ana_to_find){
            while(intArray[i] == ana_to_find){

                //c++;
                for(int j = 0; j < 30000; j++){
                    if(ori[j].number == &intArray[i] && ori[j].length == l){
                        c++;
                        break;
                    }
                }
                i++;
            }
            break;
        }
    }
    ftime(&end);

    printf("Num ana is %d\n", c);
    //for(int i = 0; i < 30000; i++){

    //     free(myArray[i]);
    //     free(ori[i].number);
        

    // }

    // free(intArray);
    // free(ori);
    


}


char *sortStr(char *str){
    int n  = 0;
    if(str != NULL){
        n = strlen(str);
    }
    int i, j;
    char temp = 'q';
   for (i = 0; i < n-1; i++){      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) {
           int a  = str[j] - '0';
           int b = str[j + 1] - '0';
           if (a > b){
              //swap(&arr[j], &arr[j+1])
              temp = str[j];
              str[j] = str[j +  1];
              str[j + 1] = temp;
           }
       }
    }

    return str;
}  


void sortArray(char **myArray, int num_numbers){

     int i, j;
     char *temp = calloc(250, sizeof(char));
   
   for (i = 0; i < num_numbers-1; i++){      
 
       // Last i elements are already in place   
       for (j = 0; j < num_numbers-i-1; j++) {
           
           if (atoi(myArray[j]) > atoi(myArray[j + 1])){
              strcpy(temp, myArray[j]);
              strcpy(myArray[j], myArray[j + 1]);
              strcpy(myArray[j + 1], temp);
              
           }
       }
    }

}


void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int temp;
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++){
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot){
            i++;    // increment index of smaller element
            temp = arr[i];
            arr[i]  = arr[j];
            arr[j] = temp;
            //swap(&arr[i], &arr[j]);
        }
    }
    temp = arr[i +  1];
    arr[1 + i] = arr[high];
    arr[high] = temp;
   // swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
// void quickSort(int arr[], int low, int high){
//     if (low < high){
//         /* pi is partitioning index, arr[p] is now
//            at right place */
//         int pi = partition(arr, low, high);
 
//         // Separately sort elements before
//         // partition and after partition
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }


Object *createObject(){
    Object *obj;
    obj = calloc(30000, sizeof(Object));

    for(int i = 0; i < 30000; i++){
        obj[i].signature = calloc(150, sizeof(char));
    }

    return obj;
}




void runq2(char *filename){

    FILE *fptr = NULL;
    part1("data_4.txt",fptr);

}






