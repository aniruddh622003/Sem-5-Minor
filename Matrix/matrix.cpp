#include "matrix.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter Matrix Size (m x n): ";
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> mat1 = input_matrix(m, n);
    std::vector<std::vector<int>> mat2 = input_matrix(m, n);
    std::vector<std::vector<int>> res = add_matrix(m, n, mat1, mat2);
    print_matrix(m, n, mat1);
    print_matrix(m, n, mat2);
    print_matrix(m, n, res);
    return 0;
}