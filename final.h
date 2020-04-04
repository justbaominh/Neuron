#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define RESET  "\x1B[0m"    // I coded this project on Codeblocks ver 17.12.
#define RED  "\x1B[31m"     // However, the compiler can not execute these code
#define GREEN  "\x1B[32m"   // like "\x1B[0m". I tried to use textcolor which I found on the
#define YELLOW  "\x1B[33m"  // the Internet but it would not succeed. You can check the code
#define BLUE  "\x1B[34m"    // in "identifycolor.c" from line 74 to line 78.
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"


void allcolor(char *file, char *hf, char *res);
 // in procedure.c

double dot(double *a, double *b, uint16_t n);//
double sigmoid(double x);//
double sigmoid_derivative(double x);//                                     // in neuron.c
void train(double input[][3], double *output, uint32_t n);//
double analyze(double input[]);//

double red (double *ar);//
double green(double ar[]); //      in identify color
double blue (double ar[]);//
void rgb(double ar[],char *res);//


void compare(char *res1, char *res2);   // in compare.c
double per (double a, double b);
