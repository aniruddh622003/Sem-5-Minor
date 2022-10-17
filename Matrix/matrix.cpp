#include "matrix.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter m, n, a and b: ";
    int m, n, a, b;
    std::cin >> m >> n >> a >> b;
    std::vector<std::vector<int>> mat1 = input_matrix(m, n);
    std::vector<std::vector<int>> mat2 = input_matrix(a, b);
    std::vector<std::vector<int>> res = convolve(m, n, mat1, a, b, mat2);
    print_matrix(m, n, mat1);
    // std::cout << trace(m, n, mat1) << "\n";
    print_matrix(a, b, mat2);
    print_matrix(2, 2, res);
    return 0;
}