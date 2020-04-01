#include "final.h"

static double synaptic_weights[3];


void red(double ar[]) {
    srand(1);
	synaptic_weights[0] = 2 * (double)rand()/RAND_MAX - 1;
	synaptic_weights[1] = 2 * (double)rand()/RAND_MAX - 1;
	synaptic_weights[2] = 2 * (double)rand()/RAND_MAX - 1;


	double training_set_inputs[4][3] = { {0, 0, 0},
										 {1, 1, 1},             // R - G - B
										 {1, 0, 1},
										 {0, 1, 1}
									   };
	double training_set_outputs[4] = {0,1,1,0};

    train(training_set_inputs, training_set_outputs, 10000);

	printf("Percent red:  %lf \n", 100*analyze(ar));

}

void green (double ar[]){
    srand(1);
	synaptic_weights[0] = 2 * (double)rand()/RAND_MAX - 1;
	synaptic_weights[1] = 2 * (double)rand()/RAND_MAX - 1;
	synaptic_weights[2] = 2 * (double)rand()/RAND_MAX - 1;


	double training_set_inputs[4][3] = { {0, 0, 0},
										 {1, 1, 1},             // R - G - B
										 {1, 0, 1},
										 {0, 1, 1}
									   };
	double training_set_outputs[4] = {0,1,0,1};

    train(training_set_inputs, training_set_outputs, 10000);

	printf("Percent green:  %lf \n", 100*analyze(ar));


}

void blue (double ar[]) {
    srand(1);
	synaptic_weights[0] = 2 * (double)rand()/RAND_MAX - 1;
	synaptic_weights[1] = 2 * (double)rand()/RAND_MAX - 1;
	synaptic_weights[2] = 2 * (double)rand()/RAND_MAX - 1;


	double training_set_inputs[4][3] = { {0, 0, 0},
										 {1, 1, 1},             // R - G - B
										 {1, 0, 1},
										 {0, 1, 1}
									   };
	double training_set_outputs[4] = {0,1,1,1};

    train(training_set_inputs, training_set_outputs, 10000);

	printf("Percent blue:  %lf \n", 100*analyze(ar));

}
