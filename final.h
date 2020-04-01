#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void allcolor();
void quarter();
void by4();

double dot_product (double *a, double *b, uint16_t n);
double sigmoid(double x);
double desigmoid(double x);                                     // NEURON
void train(double input[][3], double *output, uint32_t n);
double analyze(double input[]);

void red (double *ar);
void green(double ar[]);
void blue (double ar[]);

