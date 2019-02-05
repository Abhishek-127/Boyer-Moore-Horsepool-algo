#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <sys/timeb.h>

#include "q1.h"
#include "q2.h"


int main(int argc ,char **argv){
    
    
    char *choice;
    choice = calloc(100, sizeof(char));
    printf("Enter your choice: \n");
    FILE *fptr = NULL;
    
    while(choice[0] != '6'){
        printf("1. Run Brute Force Algorithm to Find Anagrams\n");
        printf("2. Presort to find Anagrams\n");
        printf("3. Brute Force String Search\n");
        printf("4. Run Horsepool Algorithm\n");
        printf("5. Run Boyer-Moore Algorithm\n");
        printf("6. Exit\n");

        fgets(choice, 100, stdin);

        if(choice[0] == '1'){
            part1("data_4.txt", fptr);
        }
        else if(choice[0] == '2'){
            runq2("data_4.txt");
        }

        else if(choice[0] == '3'){
            runa2("data_5.txt");
        }
        else if(choice[0] == '4'){
            run2b("data_5.txt");
        }
        else if(choice[0] == '5'){
            run2c("data_5.txt");
        }
        else if(choice[0] == '6'){

        }
        else{
            printf("Invalid Input\n");
            
        }

    }


    free(choice);
    return 0;
}