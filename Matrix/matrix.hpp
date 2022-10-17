#pragma once
#include <iostream>
#include <vector>

void print_hello()
{
    std::cout << "Hello World!\n";
}

std::vector<std::vector<int>> input_matrix(int m, int n)
{
    int val;
    std::vector<std::vector<int>> mat;
    for (int i = 0; i < m; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < n; j++)
        {
            std::cin >> val;
            row.push_back(val);
        }
        mat.push_back(row);
    }
    return mat;
}

void print_matrix(int m, int n, std::vector<std::vector<int>> mat)
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

int get_element_at_index(std::vector<std::vector<int>> mat, int row, int col)
{
    return mat[row - 1][col - 1];
}

std::vector<std::vector<int>> add_matrix(int m, int n, std::vector<std::vector<int>> mat1, std::vector<std::vector<int>> mat2)
{
    int val;
    std::vector<std::vector<int>> mat;
    for (int i = 0; i < m; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < n; j++)
        {
            val = mat1[i][j] + mat2[i][j];
            row.push_back(val);
        }
        mat.push_back(row);
    }
    return mat;
}

std::vector<std::vector<int>> multiply_matrix(int m, int n, int o, std::vector<std::vector<int>> mat1, std::vector<std::vector<int>> mat2)
{
    int val;
    std::vector<std::vector<int>> res;
    for (int i = 0; i < m; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < o; j++)
        {
            int val = 0;
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

std::vector<std::vector<int>> transpose(int m, int n, std::vector<std::vector<int>> mat)
{
    std::vector<std::vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < m; j++)
        {
            row.push_back(mat[j][i]);
        }
        res.push_back(row);
    }
    return res;
}

int trace(int m, int n, std::vector<std::vector<int>> mat)
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

std::vector<std::vector<int>> scalar_multiply(int m, int n, std::vector<std::vector<int>> mat, int scalar)
{
    int val;
    std::vector<std::vector<int>> res;
    for (int i = 0; i < m; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < n; j++)
        {
            val = mat[i][j] * scalar;
            row.push_back(val);
        }
        res.push_back(row);
    }
    return res;
}

std::vector<std::vector<int>> convolve(int m, int n, std::vector<std::vector<int>> base, int a, int b, std::vector<std::vector<int>> filter)
{
    int val;
    std::vector<std::vector<int>> res;
    for (int i = 0; i < m - a + 1; i++)
    {
        std::vector<int> row;
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