#pragma once
#include "../Matrix/matrix.hpp"
#include <random>

std::vector<std::vector<float>> inititaliseLayer(int in, int out)
{
    std::vector<std::vector<float>> weightMatrix;
    std::vector<float> bias;
    for (int i = 0; i < out; i++)
    {
        bias.push_back(rand() % 100);
    }
    weightMatrix.push_back(bias);
    for (int i = 0; i < in; i++)
    {
        std::vector<float> weights;
        for (int j = 0; j < in; j++)
        {
            weights.push_back(rand() % 100);
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

void start()
{
    std::cout << "Hello World!\n";
}