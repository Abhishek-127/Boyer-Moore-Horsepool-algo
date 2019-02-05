#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/timeb.h>
#include <stdbool.h>

#include "q2.h"

void shiftTable(int *sT, char *str){
    int m = 0;

    if(str !=  NULL){
        m = strlen(str) - 1;
    }

    int size = 400;
    for(int i = 0; i < size - 1; i++){
        if(m >= 0){
            sT[i] = m;
        }
    }
    for(int j = 0; j < m - 1; j++){

        int index = str[j] - 32;

        int final = 0;
        final  = m;
        final--;
        final -= j;
        sT[index] = final;
    }
}


void horspoolSearchForPattern(int *sT, char *str, char **line){

    int found = 0;
    int count = 0;
    int patternShift = 0;
    int numRight = 0;
    int flag =0;
    int m = 0;
    if(str != NULL){
        m = strlen(str)-1;
    }

    int size_of_loop = 44049;
    for(int i = 0; i < size_of_loop; i++){
        int n = 0;

        if(line[i] != NULL){
             n = strlen(line[i]);
        }

        if( str != NULL && line[i] != NULL && strlen(str) <= strlen(line[i])) {
            int j = 0;
           // bool cond = true;
            while(j < n - m){
                
                patternShift = patternShift + 1;

                count = 0;
                if(count < 0){
                    count++;
                }
                numRight = 0;
                int k = 0;

                for(k = m-1; k >= 0; k = k - 1){
                    if(line[i][j+k] == str[k]){
                        if(flag != 1)
                            numRight = numRight + 1;
                            count = count + 1;
                        
                    }
                    else{
                        flag = 1;
                    }
                }
                k = m - 1 - numRight;
                if(count == m){
                    found = found + 1;
                }
                int index = 0;
                index = (unsigned char)line[i][j+k] - 32;
                j = j + sT[index];
                
            }
        }
    }

   printHorsePool(found, str, patternShift);

}


void printHorsePool(int found, char *str, int patternShift){

     printf("----------------------\n");
    printf("Horspool Algorithm\n");
    printf("----------------------\n");
    printf("%d occurences of %s\n", found, str);
    printf("Number of pattern shifts: %d\n", patternShift);

}

void run2b(char *filename){

    struct timeb start, end;                          
    //int diff;                                               

    FILE* fp = fopen("data_5.txt", "r");
    char **line;
    line = calloc(44049+10, sizeof(char*));
    for(int i = 0; i < 44049+10; i++){
        line[i] = calloc(250, sizeof(char));
    }
    
    char *str;
    str = calloc(250, sizeof(char));
    int *sT;
    sT = calloc(400, sizeof(int));
    int count = 0;

    
    while (!feof(fp))
    {
        fgets(line[count], 150, fp);
        count++;
    }
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);
 

    shiftTable(sT, str);
    ftime(&start);
    horspoolSearchForPattern(sT, str, line);
    ftime(&end);

    int secs = 0;
    int mills = 0;

    secs = end.time - start.time;
    mills = end.millitm - start.millitm;
    if(mills < 0){
        mills = mills * -1;
    }

    // diff = (int) (1000.0 * (end.time - start.time) 
    //     + (end.millitm - start.millitm));

    printf("Execution time is: %d.%d seconds\n", secs, mills);    

    fclose(fp);

    free(str);
    for(int i = 0; i < 44049+10; i++){
        free(line[i]);
    }
    free(line);
    free(sT);
}