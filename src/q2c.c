#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/timeb.h>

#include "q2.h"




void goodShiftTable(int *sT, char *str, int dummy){
    
    int size = 0;
    if(str != NULL){
        size = strlen(str);
        size -= 1;
    }
    int m = 0;
    int j = 0;
    int numRight = 0;
    int count = 0;

    int suffixIndex = 0;
    char suffix[size];
    for(int i = 0; i < size; i++){
        suffix[i] = '\0';
    }

    for(int i = size-1; i >= 0; i--){
        if(size >= 0){
            sT[i] = size;
        }
    }

    for(int i = size-1; i >= 0; i--){
        m = i;
        suffixIndex = i;
        j = 0;
        while(m <= size-1){

            suffix[j] = str[m];
            j = j + 1;
            m = m + 1;
        }
        int k = 0;
        int length = 0; 
        int l = 0;

        count = 0; 
        for(int i = size-j-1; i >= 0; i = i - 1){
            length = 0;
            numRight = 0;
            k = 0;
            l = 0;
            //m = i-(j-1);
            i = i - (j - 1);
            m = m - i; 
            while(m <= i){
                
                if(m >= 0){
                    if(str[m] == suffix[l]){
                        numRight = numRight + 1;
                        k = k + 1;
                        length = length + 1;
                    }
                    else{

                        length = length + 1;
                    }       
                }
                m = m + 1;
                l = l + 1;
            }
            count = count + 1;
            if(numRight == length){
                sT[suffixIndex] = count;
                sT[suffixIndex] += j;
                sT[suffixIndex] -= numRight;
                break;
            }
        }
    }
}



void bmSearchForPattern(int *bST, int *gST, char *str, char **line, int var){

    int found = 0;
    int count = 0;
    int patternShift = 0;
    int numRight = 0;
    int flag = 0;

    int m = 0;
    if(str != NULL){ 

        m = strlen(str);
        m -= 1;
    }

    int size = 44049;
    for(int i = 0; i < size; i++)
    {
        int n = 0;
        if(line[i] != NULL){

            n = strlen(line[i]);
        }

        if( str != NULL && line[i] != NULL && strlen(str) <= strlen(line[i])) {
            int j = 0;
            while(j < n - m){

                patternShift = patternShift + 1;
                count = 0;
                flag = 0;
                numRight = 0;
                int k = 0;
                for(k = m - 1; k >= 0; k = k - 1){
                    if(line[i][j+k] == str[k]){
                        if(flag != 1)
                            numRight = numRight + 1;
                        count = count + 1;
                    }
                    else
                        flag = 1;
                }

                k = m;
                k = k - 1;
                k = k - numRight;
                if(count == m){
                    found++;
                }
                int index = 0;
                index = (unsigned char)line[i][j+k] - 32;
               // printf("%d\n", index);
                int badValue = 0;
                int  goodValue = 0;
                if(gST != NULL){
                    goodValue = gST[m-numRight];
                }
                if(bST != NULL && bST[index]-numRight > 0){ 
                    badValue = bST[index];
                    badValue = badValue-numRight;
                }
                else{
                    badValue = 1;
                }

                if(badValue >= goodValue){

                    j = j + badValue;
                }
                else{

                    j = j + goodValue;
                }

            }
        }
    }
    printBoyerMoore(found, str, patternShift);
    
}




void run2c(char *filename){

    struct timeb start, end;                          
    //int diff;                                               

    FILE* fp = fopen("data_5.txt", "r");
    char **line;
    line = calloc(44049 + 50, sizeof(char *));
    for(int i = 0; i < 44049 + 50; i++){
        line[i] = calloc(150, sizeof(char));
    }
   

    char *str;
    str = calloc(2500, sizeof(char));
    
    
    int *bST;
    bST = calloc(400, sizeof(int));
    int *gST;
    gST = calloc(400, sizeof(int));
    int count = 0;

    for(int i = 0; i < 400; i++){
        gST[i] = 0;
        bST[i] = 0;
    }

    //Reading in file to array
    while (!feof(fp))
    {
        fgets(line[count], 100, fp);
        count++;
    }
    
        printf("Enter a string: ");
        fgets(str, 250, stdin);

    badShiftTable(bST, str, 1);
    goodShiftTable(gST, str, 0);
    ftime(&start);
    bmSearchForPattern(bST, gST, str, line, 1);
    ftime(&end);

    int secs = 0;
    int mills  = 0;
    secs = end.time - start.time;
    mills = end.millitm - start.millitm;

    if(mills < 0){
        mills *= -1;
    }
    

    printf("Execution time is: %d.%d seconds\n", secs, mills);

    fclose(fp);
    free(str);
    free(bST);
    free(gST);
    for(int i = 0; i < 44049 + 50; i++){
        free(line[i]);
    }
    free(line);
   

}


void badShiftTable(int *sT, char *str, int dummy){

    int m = 0;
    if(str != NULL){
        m =  strlen(str);
        m = m-1;
    }
    int size = 400;
    for(int i = 0; i < size - 1; i++)
    {   
        if(size >= 0){
            sT[i] = m;
        }
    }
    for(int j = 0; j < m - 1;j++)
    {   
        if(j >= 0){
            int index = str[j] - 32;
            sT[index] = m-1-j;
        }
    }
}


void printBoyerMoore(int found, char *str, int patternShift){

    printf("----------------------\n");
    printf("Boyer-Moore Algorithm\n");
    printf("----------------------\n");
    printf("%d occurences of %s\n", found, str);
    printf("Number of pattern shifts: %d\n", patternShift);

}
 
