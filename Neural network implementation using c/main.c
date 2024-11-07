#include <stdio.h>
#include <math.h>

// Sigmoid activation function
double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

int main() {
    // Inputs
    double x1 = 0.6;
    double x2 = 0.8;

    // Weights for input to hidden layer 1
    double w1_1 = 0.2;
    double w2_1 = 0.3;
    double w1_2 = 0.4;
    double w2_2 = 0.5;

    // Weights for hidden layer 1 to hidden layer 2
    double w1_h2 = 0.6;
    double w2_h2 = 0.7;

    // Weights for hidden layer 2 to output layer
    double w_out_h2 = 0.8;
    double w_out_h1 = 0.9;

    // Calculate the weighted sums for hidden layer 1
    double z1_1 = (w1_1 * x1) + (w2_1 * x2);
    double z1_2 = (w1_2 * x1) + (w2_2 * x2);

    // Apply sigmoid activation function for hidden layer 1
    double h1_1 = sigmoid(z1_1);
    double h1_2 = sigmoid(z1_2);

    // Calculate the weighted sum for hidden layer 2
    double z2 = (w1_h2 * h1_1) + (w2_h2 * h1_2);

    // Apply sigmoid activation function for hidden layer 2
    double h2 = sigmoid(z2);

    // Calculate the output layer
    double z_out = (w_out_h2 * h2) + (w_out_h1 * h1_1); // You can also use h1_2 if you want to include both hidden neurons

    // Apply sigmoid activation function for output
    double output = sigmoid(z_out);

    // Classify based on the output
    int classification = (output >= 0.5) ? 1 : 0;

    // Print results
    printf("Output: %.4f\n", output);
    printf("Classification: %d\n", classification);

    return 0;
}