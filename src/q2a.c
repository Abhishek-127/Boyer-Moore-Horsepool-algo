#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <ctype.h>
#include <stdbool.h>
#include "q2.h"


void bruteForceSearchForPattern(char *str, char **line, char *filename){
    int found; 
    int count;
    int patternShift;
    found = 0;
    count = 0;
    patternShift = 0;

    int m = 0;
    if(str != NULL){
        m = strlen(str) - 1;
    }
   // m = strlen(str)-1;
   int size = 44049;

    for(int i = 0; i<size; i++)
    {   
         int n = 0;
        if(line[i] != NULL){
           n = strlen(line[i]);
        }
        bool check = false;
        if(str != NULL && line[i] != NULL){
            if(strlen(str) <= strlen(line[i])){
                check = true;
            }
        }

        if(check == true) //If the pattern is shorter or equal to the size of the line
        {   
            int num;
            num = 0;
            num = n-m;
            for(int j = 0; j<num; j++) //Looking through the line
            {
                patternShift++;
                count = 0;
                int k = 0;
                bool cond = true;
                if(k < m){
                    cond = true;
                }
                else{
                    false;
                }
                if(cond == true){

                }
                for(k = 0; k < m; k++){
                    if(line[i][j+k] == str[k])
                        count++;
                        if(k < m){
                            cond = true;
                        }
                        else{
                            false;
                        }
                       
                }
                bool check2 = false;
                if(count == m){
                    check2 = true;
                }
                if(check2 == true){
                    found++;
                    //break;
                }
            }
        }
    }
    print2a(found, str, patternShift);
   
}

void print2a(int found, char *str, int patternShift){
    printf("\n----------------------\n");
    printf("Brute Force Algorithm\n");
    printf("----------------------\n");
    printf("%d occurences of %s\n", found, str);
    printf("Number of pattern shifts: %d\n", patternShift);

}

void runa2(char *filename){

     
    struct timeb start, end;                          
    //int diff = 0;                                             

    FILE* fp = fopen("data_5.txt", "r");
    char **line;
    line = calloc(44049, sizeof(char *));
    for(int i = 0; i < 44049; i++){
        line[i] = calloc(150, sizeof(char));
    }

    char *str;
    str = calloc(250, sizeof(char));
    int count = 0;

    char *temp;
    temp = calloc(250, sizeof(char));
    while (fgets(temp, 200, fp)){
        
        strncpy(line[count], temp, 150);
        count++;
    }
    
    
    printf("Enter the string: ");
    fgets(str, 150, stdin);
    ftime(&start);
    bruteForceSearchForPattern(str, line, filename);
    ftime(&end);

    int secs = end.time - start.time;
   // secs *= 1000;

    int mills = end.millitm - start.millitm;
    if(mills < 0){
        mills *= -1;
    }
    
    printf("Execution time is: %d.%d Seconds\n", secs, mills);

    fclose(fp);

    free(temp);
    free(str);
    for(int i = 0; i < 44049; i++){
        free(line[i]);
    }
    free(line);
    
}
