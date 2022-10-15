#include "matrix.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter Matrix Size (m x n): ";
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> mat1 = input_matrix(m, n);
    // std::vector<std::vector<int>> mat2 = input_matrix(m, n);
    // int *res = add_matrix(m, n, (int *)mat1, (int *)mat2);
    print_matrix(m, n, mat1);
    return 0;
}