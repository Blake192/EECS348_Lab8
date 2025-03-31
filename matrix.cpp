#include "matrix.hpp"    // the header for Matrix class
#include <iostream>      // for std::cout
#include <iomanip>       // for std::setw
#include <stdexcept>     // for std::out_of_range
#include <string>        // for std::string and std::to_string
#include <vector>        // if not already transitively included

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

Matrix::Matrix(size_t N) {
    // initialize an empty NxN matrix
    // we'll use a list of list of ints for a 2D array (matrix)
    data = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
    // ^ A vector of N rows, each one being a vector of zeros, for example:
    // For N=4 we get:
    // [
    //   [0, 0, 0, 0],
    //   [0, 0, 0, 0],
    //   [0, 0, 0, 0],
    //   [0, 0, 0, 0]
    // ]
}

void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= data.size() || j >= data[i].size()) {
        throw std::out_of_range("Index out of bounds");
    }
    data[i][j] = n;
}

// e.g. for a member function:
void Matrix::print_matrix() const {
    // determine the maximum width needed for alignment
    int max_width = 0;
    for (const std::vector<int>& row : data) {
        for (int val : row) {
            int len = std::to_string(val).length();
            if (len > max_width)
                max_width = len;
        }
    }

    // add some padding
    const int padding = 1;
    int column_width = max_width + padding;

    for (const std::vector<int>& row : data) {
        for (int val : row) {
            std::cout << std::setw(column_width) << val;
        }
        std::cout << "\n";
    }
}
