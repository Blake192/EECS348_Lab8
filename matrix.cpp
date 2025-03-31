#include "matrix.hpp"    // include the header file that defines the Matrix class and its interface
#include <iostream>      // include library for console output (std::cout)
#include <iomanip>       // include library for formatted output (std::setw)
#include <stdexcept>     // include library for standard exceptions (std::out_of_range, std::invalid_argument)
#include <string>        // include library for string operations (std::to_string)
#include <vector>        // include library for std::vector

// --- Functions in the order of matrix.hpp ---

// constructor: creates an n x n matrix filled with zeros
Matrix::Matrix(std::size_t N) {
    // create a 2d vector with n rows and n columns, each element initialized to 0
    data = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
    // example: for n=4, data becomes a 4x4 matrix of zeros
}

// constructor: initializes the matrix with a given 2d vector
Matrix::Matrix(std::vector<std::vector<int>> nums) : data(nums) {
    // using initializer list to assign the provided vector 'nums' to 'data'
}

// overload operator+: adds two matrices element-wise and returns the result
Matrix Matrix::operator+(const Matrix &rhs) const {
    // check if the dimensions of both matrices match
    if (data.size() != rhs.data.size() || data[0].size() != rhs.data[0].size()) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    std::size_t N = data.size(); // get the number of rows (matrix is assumed square)

    // yo, set up a new matrix of zeros to hold the addition result
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

    // loop over each row
    for (std::size_t i = 0; i < N; ++i) {
        // loop over each column in the current row
        for (std::size_t j = 0; j < data[i].size(); ++j) {
            // add the corresponding elements from both matrices
            result[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    // return a new Matrix object created from the result of the addition
    return Matrix(result);
}

// overload operator*: multiplies two matrices using the standard algorithm and returns the product
Matrix Matrix::operator*(const Matrix &rhs) const {
    // check if dimensions are compatible for multiplication
    if (data.size() != rhs.data.size() || data[0].size() != rhs.data[0].size()) {
        throw std::invalid_argument("Matrix dimensions must match for multiplication");
    }
    std::size_t N = data.size(); // get the matrix dimension

    // yo, set up a result matrix full of zeros for multiplication
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

    // outer loop: iterate over each row of the first matrix
    for (std::size_t i = 0; i < N; ++i) {
        // for each row, iterate over each column of the second matrix
        for (std::size_t j = 0; j < N; ++j) {
            int sum = 0;  // initialize the sum for the dot product of row i and column j
            // perform the dot product: multiply corresponding elements and add them up
            for (std::size_t k = 0; k < N; ++k) {
                sum += data[i][k] * rhs.data[k][j];
            }
            // store the computed sum in the result matrix at (i, j)
            result[i][j] = sum;
        }
    }
    // return a new Matrix object created from the multiplication result
    return Matrix(result);
}

// set_value: updates the element at position (i, j) with the value n
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    // check if the indices are within bounds
    if (i >= data.size() || j >= data[i].size()) {
        throw std::out_of_range("Index out of bounds");
    }
    // set the element at (i, j) to n
    data[i][j] = n;
}

// get_value: retrieves the element at position (i, j)
int Matrix::get_value(std::size_t i, std::size_t j) const {
    // check if the indices are valid
    if (i >= data.size() || j >= data[i].size()) {
        throw std::out_of_range("Index out of bounds");
    }
    // return the value at (i, j)
    return data[i][j];
}

// get_size: returns the dimension (number of rows/columns) of the square matrix
int Matrix::get_size() const {
    return static_cast<int>(data.size());
}

// sum_diagonal_major: calculates the sum of the main (major) diagonal elements
int Matrix::sum_diagonal_major() const {
    int sum = 0;                   // initialize sum to 0
    std::size_t N = data.size();   // get the size of the matrix
    // loop over each row and add the element where row index equals column index
    for (std::size_t i = 0; i < N; ++i) {
        sum += data[i][i];
    }
    return sum;                    // return the computed sum
}

// sum_diagonal_minor: calculates the sum of the secondary (minor) diagonal elements
int Matrix::sum_diagonal_minor() const {
    int sum = 0;                   // initialize sum to 0
    std::size_t N = data.size();   // get the matrix dimension
    // loop over each row and add the element from the secondary diagonal (col index: N - 1 - i)
    for (std::size_t i = 0; i < N; ++i) {
        sum += data[i][N - 1 - i];
    }
    return sum;                    // return the computed sum
}

// swap_rows: swaps the rows at indices r1 and r2 in the matrix
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    // check if the provided row indices are within valid range
    if (r1 >= data.size() || r2 >= data.size()) {
        throw std::out_of_range("Row index out of bounds");
    }
    // swap the two rows using std::swap
    std::swap(data[r1], data[r2]);
}

// swap_cols: swaps the columns at indices c1 and c2 in the matrix
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    std::size_t N = data.size();  // get the number of rows
    // check if the matrix is non-empty and column indices are valid
    if (N == 0 || c1 >= data[0].size() || c2 >= data[0].size()) {
        throw std::out_of_range("Column index out of bounds");
    }
    // loop through each row to swap the elements in columns c1 and c2
    for (std::size_t i = 0; i < N; ++i) {
        std::swap(data[i][c1], data[i][c2]);
    }
}

// print_matrix: prints the matrix to the console with formatted alignment
void Matrix::print_matrix() const {
    int max_width = 0;  // initialize to store the maximum width of any element
    // loop through each row to find the maximum width needed for any element
    for (const std::vector<int>& row : data) {
        for (int val : row) {
            int len = std::to_string(val).length();  // get the length of the element as a string
            if (len > max_width)
                max_width = len;  // update max_width if this element is wider
        }
    }
    const int padding = 1;                   // define a padding value to add space between columns
    int column_width = max_width + padding;  // compute the total column width

    // so, now we print each row with the computed spacing so everything lines up nicely
    for (const std::vector<int>& row : data) {
        for (int val : row) {
            std::cout << std::setw(column_width) << val; // print each element with setw for alignment
        }
        std::cout << "\n";  // after each row, move to a new line
    }
}
