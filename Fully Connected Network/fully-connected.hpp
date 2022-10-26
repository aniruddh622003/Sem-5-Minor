#pragma once
#include "../Matrix/matrix.hpp"
#include <random>

std::vector<std::vector<float>> inititaliseLayer(int in, int out)
{
    std::vector<std::vector<float>> weightMatrix;
    std::vector<float> bias;
    for (int i = 0; i < out; i++)
    {
        float val = (rand() % 100) / 100.0 - 0.5;
        bias.push_back(val);
    }
    weightMatrix.push_back(bias);
    for (int i = 0; i < in; i++)
    {
        std::vector<float> weights;
        for (int j = 0; j < out; j++)
        {
            float val = (rand() % 100) / 100.0 - 0.5;
            weights.push_back(val);
        }
        weightMatrix.push_back(weights);
    }
    return weightMatrix;
}

std::vector<std::vector<float>> layerForward(std::vector<std::vector<float>> layer_input, std::vector<std::vector<float>> weightMatrix, int m, int n, int o)
{
    std::vector<std::vector<float>> output = multiply_matrix(m, n, o, layer_input, weightMatrix);
    return output;
}

// Weights -> m x n; Loss -> 1 x n; Inputs -> 1 x m (All including bias)
// This function can be improved using matrix maniulations
std::vector<std::vector<float>> getChangeMatrix(int m, int n,
                                                std::vector<std::vector<float>> loss,
                                                std::vector<std::vector<float>> inputs,
                                                float learning_rate,
                                                char activation)
{
    // 1. We have error
    // 2. Get d(activation)
    // 3. Get input (1 for bias)
    std::vector<std::vector<float>> change_matrix;
    for (int i = 0; i < m; i++)
    {
        std::vector<float> row;
        for (int j = 0; j < n; j++)
        {
            float val = inputs[0][i] * loss[0][j];
            row.push_back(val);
        }
        change_matrix.push_back(row);
    }
    // print_matrix(m, n, change_matrix);
    change_matrix = scalar_multiply(m, n, change_matrix, (learning_rate));
    return change_matrix;
}

std::vector<std::vector<float>> backpropError(int m, int n,
                                              std::vector<std::vector<float>> weights,
                                              std::vector<std::vector<float>> loss,
                                              char activation)
{

    // We have loss vector like [ X  X  X  X  X ]
    // Weight matrix is 4x5
    // We return prev layer loss like [ X  X  X ]

    std::vector<std::vector<float>> prev_layer_error;
    // prev layer loss[i] = avg(weight[i][j]*loss[j])
    std::vector<float> row;
    for (int i = 1; i < m; i++)
    {
        float val = 0;
        for (int j = 0; j < n; j++)
        {
            val += weights[i][j] * loss[0][j];
        }
        val /= n;
        row.push_back(val);
    }
    prev_layer_error.push_back(row);
    return prev_layer_error;
}