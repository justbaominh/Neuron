#include <stdio.h>
#include <stdlib.h>

#include "final.h"
double synaptic_weights[3];
double defSW = 0.1;
double alpha = 1;
double dot (double *a, double *b, uint16_t n) {
    double re = 0;
    for (uint16_t i = 0; i < n; i++) {
        re += a[i] * b[i];
    }
    return re;
}
double sigmoid(double x){
	double re;
	re = 1/(1+exp(-x));
	return re;
}
double sigmoid_derivative(double x){
    double re;
	re = x * (1 - x);
	return re;
}
void think_train(double input[][3], double output[]){
		double result1, result2, result3, result4;

		result1 = dot(&input[0][0],synaptic_weights,3);
		result2 = dot(&input[1][0],synaptic_weights,3);
		result3 = dot(&input[2][0],synaptic_weights,3);
		result4 = dot(&input[3][0],synaptic_weights,3);

		output[0] = sigmoid(result1);
		output[1] = sigmoid(result2);
		output[2] = sigmoid(result3);
		output[3] = sigmoid(result4);
}

void train(double training_set_inputs[][3], double training_set_outputs[], uint32_t n){
    synaptic_weights[0] = defSW;
	synaptic_weights[1] = defSW;
	synaptic_weights[2] = defSW;
	for(uint32_t i = 0; i < n; i++){

		double error[4];
		double output[4];

		think_train(training_set_inputs, output);

		error[0] = training_set_outputs[0] - output[0];
		error[1] = training_set_outputs[1] - output[1];
		error[2] = training_set_outputs[2] - output[2];
		error[3] = training_set_outputs[3] - output[3];

		error[0] *= sigmoid_derivative(output[0]);
		error[1] *= sigmoid_derivative(output[1]);
		error[2] *= sigmoid_derivative(output[2]);
		error[3] *= sigmoid_derivative(output[3]);

		double transpose[3][4];

		transpose[0][0] = training_set_inputs[0][0];
		transpose[0][1] = training_set_inputs[1][0];
		transpose[0][2] = training_set_inputs[2][0];
		transpose[0][3] = training_set_inputs[3][0];

		transpose[1][0] = training_set_inputs[0][1];
		transpose[1][1] = training_set_inputs[1][1];
		transpose[1][2] = training_set_inputs[2][1];
		transpose[1][3] = training_set_inputs[3][1];

		transpose[2][0] = training_set_inputs[0][2];
		transpose[2][1] = training_set_inputs[1][2];
		transpose[2][2] = training_set_inputs[2][2];
		transpose[2][3] = training_set_inputs[3][2];

		double adjustments[3];

		adjustments[0] = dot(error, &transpose[0][0], 4);
		adjustments[1] = dot(error, &transpose[1][0], 4);
		adjustments[2] = dot(error, &transpose[2][0], 4);

		synaptic_weights[0] += adjustments[0] * alpha;
		synaptic_weights[1] += adjustments[1] * alpha;
		synaptic_weights[2] += adjustments[2] * alpha;
	}
}
//void train(double input[][3], double *output, uint32_t n){
//
//    for (uint32_t i = 0; i < n; i++) {
//
//    double res[4];
//    for (uint8_t i = 0; i < 4; i++) {
//        double temp[3];
//        for(uint8_t j = 0; j < 3; j++) temp[j] = input[i][j];
//
//        double dot = dot_product(temp, synaptic_weights, 3);
//        double re = sigmoid(dot);
//        res[i] = re;
//        // double dot = dot_product(&input[i][0], synaptic_weights, 3);
//        }
//
//    double errors[4];
//    for (uint8_t i = 0; i < 4; i++) {
//        errors[i] = res[i] - output[i];
//
//        }
//
//    for (uint8_t i = 0; i < 4; i++) {
//        errors[i] *= desigmoid(res[i]);
//
//        }
//
//    double T[3][4];
//    for (uint8_t i = 0; i < 4; i++)
//    for (uint8_t j = 0; j < 3; j++) {
//        T[j][i] = input[i][j];
//        }
//
//    double delta[3];
//    for (uint8_t i = 0; i < 3; i++) {
//        double temp[4];
//        for (uint8_t j = 0; j < 4; j++) temp[j] = T[i][j];
//        delta[i] = dot_product(temp, errors, 4);
//
//        }
//    }
//}
double reLu(double x) {
    if (x > 0) return x;
    else return 0.01 * x;
}
double analyze(double input[]) {
	double result = dot(input, synaptic_weights, 3);
    result = sigmoid(result);
	return result;
}

