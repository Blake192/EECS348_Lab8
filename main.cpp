/***********************************************************************
 * EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE       CCCCCCCCCCCCC   SSSSSSSSSSSSSSS       333333333333333          444444444       888888888  
 * E::::::::::::::::::::EE::::::::::::::::::::E    CCC::::::::::::C SS:::::::::::::::S     3:::::::::::::::33       4::::::::4     88:::::::::88  
 * E::::::::::::::::::::EE::::::::::::::::::::E  CC:::::::::::::::CS:::::SSSSSS::::::S     3::::::33333::::::3     4:::::::::4   88:::::::::::::88  
 * EE::::::EEEEEEEEE::::EEE::::::EEEEEEEEE::::E C:::::CCCCCCCC::::CS:::::S     SSSSSSS     3333333     3:::::3    4::::44::::4  8::::::88888::::::8  
 *   E:::::E       EEEEEE  E:::::E       EEEEEEC:::::C       CCCCCCS:::::S                             3:::::3   4::::4 4::::4  8:::::8     8:::::8  
 *   E:::::E               E:::::E            C:::::C              S:::::S                             3:::::3  4::::4  4::::4  8:::::8     8:::::8  
 *   E::::::EEEEEEEEEE     E::::::EEEEEEEEEE  C:::::C               S::::SSSS                  33333333:::::3  4::::4   4::::4   8:::::88888:::::8  
 *   E:::::::::::::::E     E:::::::::::::::E  C:::::C                SS::::::SSSSS             3:::::::::::3  4::::444444::::444  8:::::::::::::8  
 *   E:::::::::::::::E     E:::::::::::::::E  C:::::C                  SSS::::::::SS           33333333:::::3 4::::::::::::::::4 8:::::88888:::::8  
 *   E::::::EEEEEEEEEE     E::::::EEEEEEEEEE  C:::::C                     SSSSSS::::S                  3:::::34444444444:::::4448:::::8     8:::::8  
 *   E:::::E               E:::::E            C:::::C                          S:::::S                 3:::::3          4::::4  8:::::8     8:::::8  
 *   E:::::E       EEEEEE  E:::::E       EEEEEEC:::::C       CCCCCC            S:::::S                 3:::::3          4::::4  8:::::8     8:::::8  
 * EE::::::EEEEEEEE:::::EEE::::::EEEEEEEE:::::E C:::::CCCCCCCC::::CSSSSSSS     S:::::S     3333333     3:::::3          4::::4  8::::::88888::::::8  
 * E::::::::::::::::::::EE::::::::::::::::::::E  CC:::::::::::::::CS::::::SSSSSS:::::S     3::::::33333::::::3        44::::::44 88:::::::::::::88  
 * E::::::::::::::::::::EE::::::::::::::::::::E    CCC::::::::::::CS:::::::::::::::SS      3:::::::::::::::33         4::::::::4   88:::::::::88  
 * EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE       CCCCCCCCCCCCC SSSSSSSSSSSSSSS         333333333333333           4444444444     888888888  
 *   
 * EECS 348 LAB 8
 * DESCRIPTION: IMPLEMENT MATRIX OPERATIONS IN C++
 * INPUTS: Reads matrix size and two matrices from user specified file.  
 * OUTPUTS: Shows next email & number of unread emails 
 * ALL COLLABS: Blake Pennel, template files from github, ChatGPT o3-mini-high (help with creation based on template files)
 * AUTHORS: Blake Pennel 
 * CREATION DATE: 03/31/2025 
 ***********************************************************************/  
#include "matrix.hpp"               // include the header file for the Matrix class
#include <iostream>                 // include iostream for console input/output
#include <fstream>                  // include fstream for file input/output
#include <stdexcept>                // include stdexcept for exception handling
#include <string>                   // include string for std::string
#include <sstream>                  // include sstream for std::istringstream
#include <limits>                   // include limits for numeric_limits

int main() {                                            // main function: entry point of the program
    std::string filename;                             // declare a string to store the input file name
    std::cout << "Enter the input file name: ";       // prompt the user for the file name
    std::cin >> filename;                             // read the file name from the console

    std::ifstream inFile(filename);                   // open the specified file in an input file stream
    if (!inFile) {                                    // check if the file failed to open
        std::cerr << "Error: could not open file " << filename << std::endl;  // output an error message if the file cannot be opened
        return 1;                                     // exit the program with error code 1
    }                                                 // end of file open check

    int N;                                            // declare an integer to hold the matrix size
    inFile >> N;                                      // read the matrix size from the file
    if (N <= 0) {                                     // verify that the matrix size is greater than zero
        std::cerr << "Error: invalid matrix size" << std::endl;  // output an error message if the matrix size is invalid
        return 1;                                     // exit the program with error code 1
    }                                                 // end of matrix size check

    Matrix matrix1(N);                                // create the first matrix of size N x N, initialized with zeros
    Matrix matrix2(N);                                // create the second matrix of size N x N, initialized with zeros

    for (int i = 0; i < N; i++) {                     // loop over each row for matrix1
        for (int j = 0; j < N; j++) {                 // loop over each column for matrix1
            int value;                              // declare an integer to temporarily store a value from the file
            inFile >> value;                        // read an integer value from the file
            matrix1.set_value(i, j, value);         // set the value at position (i, j) in matrix1 to the read value
        }                                           // end inner loop for matrix1 columns
    }                                               // end outer loop for matrix1 rows

    for (int i = 0; i < N; i++) {                     // loop over each row for matrix2
        for (int j = 0; j < N; j++) {                 // loop over each column for matrix2
            int value;                              // declare an integer to temporarily store a value from the file
            inFile >> value;                        // read an integer value from the file
            matrix2.set_value(i, j, value);         // set the value at position (i, j) in matrix2 to the read value
        }                                           // end inner loop for matrix2 columns
    }                                               // end outer loop for matrix2 rows

    inFile.close();                                 // close the input file

    std::cout << "\nInitial Matrix 1:\n";           // output header for Matrix 1
    matrix1.print_matrix();                         // print the contents of matrix1
    std::cout << "\nInitial Matrix 2:\n";           // output header for Matrix 2
    matrix2.print_matrix();                         // print the contents of matrix2

    int choice = 0;                                 // declare an integer to store the user's menu choice
    do {                                            // begin menu loop that continues until the user chooses to exit
        std::cout << "\nMenu:\n";                    // output the menu header
        std::cout << "1. Display Matrix 1\n";         // display menu option 1
        std::cout << "2. Display Matrix 2\n";         // display menu option 2
        std::cout << "3. Add Matrices (Matrix1 + Matrix2)\n";   // display menu option 3
        std::cout << "4. Multiply Matrices (Matrix1 * Matrix2)\n"; // display menu option 4
        std::cout << "5. Display Sum of Diagonals of Matrix 1\n";   // display menu option 5
        std::cout << "6. Swap Rows in Matrix 1\n";    // display menu option 6
        std::cout << "7. Swap Columns in Matrix 1\n";   // display menu option 7
        std::cout << "8. Update an Element in Matrix 1\n"; // display menu option 8
        std::cout << "9. Exit\n";                     // display menu option 9 (exit)
        std::cout << "Enter your choice: ";           // prompt the user to enter a menu choice
        std::cin >> choice;                           // read the user's menu choice

        if (std::cin.fail()) {                        // check if reading the choice failed (non-integer)
            std::cin.clear();                         // clear the error state of std::cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard invalid input
            std::cout << "Invalid choice. Please enter an integer.\n";  // inform the user
            continue;                                 // jump back to the top of the menu loop
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // clear the input buffer

        switch (choice) {                             // begin switch statement to process the menu choice
            case 1: {                               // if the user selects option 1
                std::cout << "\nMatrix 1:\n";         // output header for Matrix 1
                matrix1.print_matrix();              // print matrix1
                break;                               // exit the switch statement for option 1
            }
            case 2: {                               // if the user selects option 2
                std::cout << "\nMatrix 2:\n";         // output header for Matrix 2
                matrix2.print_matrix();              // print matrix2
                break;                               // exit the switch statement for option 2
            }
            case 3: {                               // if the user selects option 3 (addition)
                try {                              // begin try block to catch exceptions during addition
                    Matrix sum = matrix1 + matrix2;   // compute the sum of matrix1 and matrix2
                    std::cout << "\nResult of Matrix1 + Matrix2:\n";  // output header for addition result
                    sum.print_matrix();            // print the resulting sum matrix
                } catch (std::exception &e) {        // catch block for addition exceptions
                    std::cerr << "Error in addition: " << e.what() << std::endl;  // output error message
                }
                break;                               // exit the switch statement for option 3
            }
            case 4: {                               // if the user selects option 4 (multiplication)
                try {                              // begin try block to catch exceptions during multiplication
                    Matrix product = matrix1 * matrix2; // compute the product of matrix1 and matrix2
                    std::cout << "\nResult of Matrix1 * Matrix2:\n";  // output header for multiplication result
                    product.print_matrix();        // print the resulting product matrix
                } catch (std::exception &e) {        // catch block for multiplication exceptions
                    std::cerr << "Error in multiplication: " << e.what() << std::endl;  // output error message
                }
                break;                               // exit the switch statement for option 4
            }
            case 5: {                               // if the user selects option 5 (display diagonal sums)
                std::cout << "\nSum of Major Diagonal (Matrix1): " 
                          << matrix1.sum_diagonal_major() << std::endl;  // display sum of major diagonal
                std::cout << "Sum of Minor Diagonal (Matrix1): " 
                          << matrix1.sum_diagonal_minor() << std::endl;  // display sum of minor diagonal
                break;                               // exit the switch statement for option 5
            }
            case 6: {                               // if the user selects option 6 (swap rows)
                int r1, r2;                        // declare integers to hold the two row indices
                bool valid = false;                // flag to indicate valid input
                std::string line;                  // string to store the input line
                while (!valid) {                   // loop until valid input is provided
                    std::cout << "\nEnter two row indices to swap (e.g., 0 1, range: 0 to " << N - 1 << "): ";  // prompt with example
                    std::getline(std::cin, line);  // read the entire line of input
                    if (line.empty()) {            // check if no input was received
                        std::cout << "No input received. ";  // inform the user
                        continue;                // continue to prompt again
                    }
                    std::istringstream iss(line); // create a stream from the input line
                    if (!(iss >> r1 >> r2)) {     // check if two integers were provided
                        std::cerr << "Invalid input. Please enter two integers separated by a space.\n";  // output error message
                        continue;                // continue to prompt again
                    }
                    try {                        // try to swap the rows
                        matrix1.swap_rows(r1, r2);  // attempt to swap rows in matrix1
                        valid = true;            // set valid flag if swap is successful
                    } catch (std::exception &e) {  // catch exceptions if indices are out-of-range
                        std::cerr << "Error swapping rows: " << e.what()
                                  << "\nPlease try again.\n";  // output error message and re-prompt
                    }
                }
                std::cout << "\nMatrix 1 after swapping rows (" << r1 << ") and (" << r2 << "):\n";  // output header after swap
                matrix1.print_matrix();            // print matrix1 after swapping rows
                break;                               // exit the switch statement for option 6
            }
            case 7: {                               // if the user selects option 7 (swap columns)
                int c1, c2;                        // declare integers to hold the two column indices
                bool valid = false;                // flag to indicate valid input
                std::string line;                  // string to store the input line
                while (!valid) {                   // loop until valid input is provided
                    std::cout << "\nEnter two column indices to swap (e.g., 0 1, range: 0 to " << N - 1 << "): ";  // prompt with example
                    std::getline(std::cin, line);  // read the entire line of input
                    if (line.empty()) {            // check if no input was received
                        std::cout << "No input received. ";  // inform the user
                        continue;                // continue to prompt again
                    }
                    std::istringstream iss(line); // create a stream from the input line
                    if (!(iss >> c1 >> c2)) {     // check if two integers were provided
                        std::cerr << "Invalid input. Please enter two integers separated by a space.\n";  // output error message
                        continue;                // continue to prompt again
                    }
                    try {                        // try to swap the columns
                        matrix1.swap_cols(c1, c2);  // attempt to swap columns in matrix1
                        valid = true;            // set valid flag if swap is successful
                    } catch (std::exception &e) {  // catch exceptions if indices are out-of-range
                        std::cerr << "Error swapping columns: " << e.what()
                                  << "\nPlease try again.\n";  // output error message and re-prompt
                    }
                }
                std::cout << "\nMatrix 1 after swapping columns (" << c1 << ") and (" << c2 << "):\n";  // output header after swap
                matrix1.print_matrix();            // print matrix1 after swapping columns
                break;                               // exit the switch statement for option 7
            }
            case 8: {                               // if the user selects option 8 (update an element)
                int row, col, newVal;              // declare integers for row index, column index, and new value
                bool valid = false;                // flag to indicate valid input
                std::string line;                  // string to store the input line
                while (!valid) {                   // loop until valid input is provided
                    std::cout << "\nEnter (row col newValue) for Matrix1 (e.g., 2 3 99, range: 0 to " << N - 1 << "): ";  // prompt with example
                    std::getline(std::cin, line);  // read the entire line of input
                    if (line.empty()) {            // check if no input was received
                        std::cout << "No input received. ";  // inform the user
                        continue;                // continue to prompt again
                    }
                    std::istringstream iss(line); // create a stream from the input line
                    if (!(iss >> row >> col >> newVal)) {  // check if three integers were provided
                        std::cerr << "Invalid input. Please enter three integers separated by spaces.\n";  // output error message
                        continue;                // continue to prompt again
                    }
                    try {                        // try to update the element
                        matrix1.set_value(row, col, newVal);  // attempt to set the new value at (row, col) in matrix1
                        valid = true;            // set valid flag if update is successful
                    } catch (std::exception &e) {  // catch exceptions if indices are out-of-range
                        std::cerr << "Error updating element: " << e.what()
                                  << "\nPlease try again.\n";  // output error message and re-prompt
                    }
                }
                std::cout << "\nMatrix 1 after updating element at (" << row << ", " << col << "):\n";  // output header after update
                matrix1.print_matrix();            // print matrix1 after updating the element
                break;                               // exit the switch statement for option 8
            }
            case 9: {                               // if the user selects option 9 (exit)
                std::cout << "Exiting program." << std::endl;  // output an exit message
                break;                               // exit the switch statement for option 9
            }
            default: {                              // if the user's menu choice is invalid
                std::cout << "Invalid choice. Please try again." << std::endl;  // output an invalid choice message
                break;                               // exit the switch statement for default case
            }
        }  // end switch statement
    } while (choice != 9);  // repeat the menu loop until the user chooses to exit (choice 9)

    return 0;  // return 0 to indicate successful execution of the program
}  // end of main function
