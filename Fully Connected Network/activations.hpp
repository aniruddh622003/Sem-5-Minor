#pragma once
#include <vector>
#include <cmath>

std::vector<std::vector<float>> linear(std::vector<std::vector<float>> input, int m, int n)
{
    return input;
}

std::vector<std::vector<float>> sigmoid(std::vector<std::vector<float>> input, int m, int n)
{
    float val;
    std::vector<std::vector<float>> res;
    for (int i = 0; i < m; i++)
    {
        std::vector<float> row;
        for (int j = 0; j < n; j++)
        {
            val = 1 / (1 + exp(-input[i][j]));
            row.push_back(val);
        }
        res.push_back(row);
    }
    return res;
}
