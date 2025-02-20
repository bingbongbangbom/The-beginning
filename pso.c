#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function definition (moved outside main)
float function(float a, float b) {
    return ((20 + (a)*(a) - 10 * cos(2 * M_PI * (a))) + b*b - 10 * cos(2 * M_PI * b));
}

int main(void) {
    clock_t start_time = clock();

    srand(time(NULL));
    const int iterations = 100;
    const int number_of_particles = 81;

    float inertia = 0.7;
    float personal_weight_1 = 1.5;
    float global_weight_1 = 1.5;

    //float convergance_BIG_CHUNGUS[3][81] = {0}; // Used for plotting if i learn that

    float position[3][81] = {0};
    float velocity_vector[3][81] = {0};

    // Initialize particle positions OBS particles inside Area: -81 < x 81, -81 < y <81
    int i = 0;
    for (int x = 0; x < 9; x++) {
        for (int y = 1; y <= 9; y++) {
            float x_val = x * 18 - 81;
            float y_val = y * 18 - 81;
            float z_val = function(x_val, y_val);

            // Assign values to position array
            position[0][i] = x_val;
            position[1][i] = y_val;
            position[2][i] = z_val;

            i++;  // Increment index
        }
    }

    // Global best initialization
    float best_value = 1000000000000000;
    float gbest_position[3][1] = {0};
    float pbest_position[3][81] = {0};

for (int counter = 0; counter < iterations; counter++) {
    // Find the best value

    for (int i = 0; i < number_of_particles; i++) {
        float current_norm = position[2][i];
        if (current_norm < best_value) {
            best_value = current_norm;
            gbest_position[0][0] = position[0][i];
            gbest_position[1][0] = position[1][i];
            gbest_position[2][0] = position[2][i];
        }
    }

    for (int i = 0; i < number_of_particles; i++) {
        if(position[2][i] < pbest_position[2][i]) {
            pbest_position[0][0] = position[0][i];
            pbest_position[1][0] = position[1][i];
            pbest_position[2][0] = position[2][i];
        }
    }

    for (int i = 0; i < number_of_particles; i++) {

        float r1 = (float)rand() / (float)32767;
        float r2 = (float)rand() / (float)32767;

        //Update velocity
        velocity_vector[0][i] = inertia * velocity_vector[0][i] + personal_weight_1 * r1 * (pbest_position[0][0] - position[0][i])
        + global_weight_1 * r2 * (gbest_position[0][0] - position[0][i]);

        velocity_vector[1][i] = inertia * velocity_vector[1][i] + personal_weight_1 * r1 * (pbest_position[1][0] - position[1][i])
        + global_weight_1 * r2 * (gbest_position[0][0] - position[0][i]);

        // Update position
        position[0][i] += velocity_vector[0][i];
        position[1][i] += velocity_vector[1][i];
        position[2][i] = function(position[0][i] , position[1][i]);
    }

// For looking at all the iterations

    // Print best position
    //printf("Best Position: (%.16f, %.16f, %.16f) with norm %.16f\n",
           //gbest_position[0][0], gbest_position[1][0], gbest_position[2][0], best_value);

    //printf("Iterations: %d\n", counter+1);
}
    clock_t end_time = clock();

    // Calculate the elapsed time in seconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    // Print best position
    printf("Best Position: (%.16f, %.16f, %.16f) \n",
    gbest_position[0][0], gbest_position[1][0], gbest_position[2][0]) ;



    printf("Iterations: %d\n", iterations);
    printf("Runtime: %f", elapsed_time);
    return 0;
}

