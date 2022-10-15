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

// int *add_matrix(int m, int n, int *mat1, int *mat2)
// {
//     int result[m][n];
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             result[i][j] = *((mat1 + i * n) + j) + *((mat2 + i * n) + j);
//         }
//     }
//     return (int *)result;
// }