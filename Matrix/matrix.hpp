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
            std::cout << mat[i][j] << " ";
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