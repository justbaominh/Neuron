#include "final.h"

static double synaptic_weights[3];

//defSW;
double red(double ar[]) {
	double training_set_inputs[4][3] = { {1, 0, 0},
										 {0, 1, 0},             // R - G - B
										 {0, 0, 1},
										 {1, 1, 1}
									   };
	double training_set_outputs[4] = {1,0,0,1};

    train(training_set_inputs, training_set_outputs, 1000);

	//printf("Percent red:  %lf \n", 100*analyze(ar));
	return 100*analyze(ar);
}

double green (double ar[]){
    double training_set_inputs[4][3] = { {1, 0, 0},
										 {0, 1, 0},             // R - G - B
										 {0, 0, 1},
										 {1, 1, 1}
									   };
	double training_set_outputs[4] = {0,1,0,1};

    train(training_set_inputs, training_set_outputs, 1000);

	//printf("Percent green:  %lf \n", 100*analyze(ar));
	return 100*analyze(ar);
}

double blue (double ar[]) {
	double training_set_inputs[4][3] = { {1, 0, 0},
										 {0, 1, 0},             // R - G - B
										 {0, 0, 1},
										 {1, 1, 1}
									   };
	double training_set_outputs[4] = {0,0,1,1};

    train(training_set_inputs, training_set_outputs, 1000);

	//printf("Percent blue:  %lf \n", 100*analyze(ar));
	return 100*analyze(ar);
}

void rgb (double ar[]) {
    printf("%lf %lf %lf\n", ar[0], ar[1], ar[2]);
    double tr, tg, tb;
    tr = red(ar);
    tg = green(ar);
    tb = blue(ar);
    double tt = tr + tg + tb;
    tr = tr / tt;
    tg = tg / tt;
    tb = tb / tt;
    printf("Percent red: %lf\n", tr);
    printf("Percent green: %lf\n", tg);
    printf("Percent blue: %lf\n", tb);
    printf("*\n");
}
