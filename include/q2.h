#ifndef Q2_H
#define Q2_H

void bruteForceSearchForPattern(char *str, char **line, char *filename);
void print2a(int found, char *str, int patternShift);

void runa2(char *filename);

void runq2(char *filename);


void run2b(char *filename);
void horspoolSearchForPattern(int *sT, char *str, char **line);
void shiftTable(int *sT, char *str);
void printHorsePool(int found, char *str, int patternShift);



void bmSearchForPattern(int *bST, int *gST, char *str, char **line, int var);
void badShiftTable(int *sT, char *str, int dummy);
void goodShiftTable(int *sT, char *str, int dummy);
void suffixes(char *x, int m, int *suff);
void printBoyerMoore(int found, char *str, int patternShift);
void run2c(char *filename);





#endif