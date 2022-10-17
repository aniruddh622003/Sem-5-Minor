#include "matrix.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter m, n and o: ";
    int m, n, o;
    std::cin >> m >> n >> o;
    std::vector<std::vector<int>> mat1 = input_matrix(m, n);
    std::vector<std::vector<int>> mat2 = input_matrix(n, o);
    std::vector<std::vector<int>> res = multiply_matrix(m, n, o, mat1, mat2);
    print_matrix(m, n, mat1);
    print_matrix(m, n, mat2);
    print_matrix(m, n, res);
    return 0;
}