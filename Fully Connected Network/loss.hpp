#pragma once
#include <vector>
#include <cmath>

std::vector<std::vector<float>> create_loss_vector(int m, int n, float loss)
{
    std::vector<std::vector<float>> loss_vector;
    for (int i = 0; i < m; i++)
    {
        std::vector<float> row;
        for (int j = 0; j < n; j++)
        {
            row.push_back(loss);
        }
        loss_vector.push_back(row);
    }
    return loss_vector;
}

float simpleLoss(int m, int n, std::vector<std::vector<float>> y_pred, std::vector<std::vector<float>> y_true)
{
    float loss = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (y_true[i][j] > y_pred[i][j])
            {
                loss += y_true[i][j] - y_pred[i][j];
            }
            else
            {
                loss += y_pred[i][j] - y_true[i][j];
            }
            // loss += y_true[i][j] - y_pred[i][j];
        }
    }
    return loss;
}

float MSELoss(int m, int n, std::vector<std::vector<float>> y_pred, std::vector<std::vector<float>> y_true)
{
    float loss = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            loss += pow((float)(y_true[i][j] - y_pred[i][j]), 2);
        }
    }
    return loss / (m * n);
}