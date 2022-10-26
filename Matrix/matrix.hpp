#pragma once
#include <iostream>
#include <vector>

void print_hello()
{
    std::cout << "Hello World!\n";
}

std::vector<std::vector<float>> input_matrix(int m, int n)
{
    float val;
    std::vector<std::vector<float>> mat;
    for (int i = 0; i < m; i++)
    {
        std::vector<float> row;
        for (int j = 0; j < n; j++)
        {
            std::cin >> val;
            row.push_back(val);
        }
        mat.push_back(row);
    }
    return mat;
}

void print_matrix(int m, int n, std::vector<std::vector<float>> mat)
{
    std::cout << "\nPrinting Matrix -> \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << '\n';
    }
}

int get_element_at_index(std::vector<std::vector<float>> mat, int row, int col)
{
    return mat[row - 1][col - 1];
}

std::vector<std::vector<float>> add_matrix(int m, int n, std::vector<std::vector<float>> mat1, std::vector<std::vector<float>> mat2)
{
    float val;
    std::vector<std::vector<float>> mat;
    for (int i = 0; i < m; i++)
    {
        std::vector<float> row;
        for (int j = 0; j < n; j++)
        {
            val = mat1[i][j] + mat2[i][j];
            row.push_back(val);
        }
        mat.push_back(row);
    }
    return mat;
}

std::vector<std::vector<float>> multiply_matrix(int m, int n, int o, std::vector<std::vector<float>> mat1, std::vector<std::vector<float>> mat2)
{
    float val;
    std::vector<std::vector<float>> res;
    for (int i = 0; i < m; i++)
    {
        std::vector<float> row;
        for (int j = 0; j < o; j++)
        {
            float val = 0;
            for (int k = 0; k < n; k++)
            {
                val += mat1[i][k] * mat2[k][j];
            }
            row.push_back(val);
        }
        res.push_back(row);
    }
    return res;
}

std::vector<std::vector<float>> transpose(int m, int n, std::vector<std::vector<float>> mat)
{
    std::vector<std::vector<float>> res;
    for (int i = 0; i < n; i++)
    {
        std::vector<float> row;
        for (int j = 0; j < m; j++)
        {
            row.push_back(mat[j][i]);
        }
        res.push_back(row);
    }
    return res;
}

int trace(int m, int n, std::vector<std::vector<float>> mat)
{
    int trace = 0;
    if (m != n)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            trace += mat[i][i];
        }
    }
    return trace;
}

std::vector<std::vector<float>> scalar_multiply(int m, int n, std::vector<std::vector<float>> mat, float scalar)
{
    float val;
    std::vector<std::vector<float>> res;
    for (int i = 0; i < m; i++)
    {
        std::vector<float> row;
        for (int j = 0; j < n; j++)
        {
            val = mat[i][j] * scalar;
            row.push_back(val);
        }
        res.push_back(row);
    }
    return res;
}

int dot_product(int m, int n, std::vector<std::vector<float>> mat1, std::vector<std::vector<float>> mat2)
{
    float val = 0;
    int temp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp = mat1[i][j] * mat2[i][j];
            val += temp;
        }
    }
    return val;
}

std::vector<std::vector<float>> convolve(int m, int n, std::vector<std::vector<float>> base, int a, int b, std::vector<std::vector<float>> filter)
{
    float val;
    std::vector<std::vector<float>> res;
    for (int i = 0; i < m - a + 1; i++)
    {
        std::vector<float> row;
        for (int j = 0; j < n - b + 1; j++)
        {
            val = 0;
            for (int x = 0; x < a; x++)
            {
                for (int y = 0; y < b; y++)
                {
                    val += base[i + x][j + y] * filter[a - x - 1][b - y - 1];
                }
            }
            row.push_back(val);
        }
        res.push_back(row);
    }
    return res;
}