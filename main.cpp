#include "matrix.hpp"
#include <iostream>


int main(int argc, char* argv[]) {
    // Create a 3x3 matrix for testing
    Matrix mat(3);

    // Fill it with some values (including a big one)
    mat.set_value(0, 0, 1);
    mat.set_value(0, 1, 23);
    mat.set_value(0, 2, 4567);
    mat.set_value(1, 0, -89);
    mat.set_value(1, 1, 100);
    mat.set_value(1, 2, 7);
    mat.set_value(2, 0, 42);
    mat.set_value(2, 1, 0);
    mat.set_value(2, 2, 5);

    std::cout << "Matrix test output:\n";
    mat.print_matrix();

    return 0;
}
