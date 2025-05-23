#include <gtest/gtest.h>

#include "matrix.hpp"

TEST(MatrixImplementation, GetSize_3) {
    Matrix matrix({
        { 25, 35, 45 },
        { 15, 45, 45 },
        { 80, 80, 80 },
    });

    EXPECT_EQ(matrix.get_size(), 3);
}

TEST(MatrixImplementation, GetSize_4) {
    Matrix matrix({
        { 25, 35, 45, 28 },
        { 15, 45, 45, 34 },
        { 80, 80, 80, 11 },
        { 4,   8,  9, 11 },
    });

    EXPECT_EQ(matrix.get_size(), 4);
}

TEST(MatrixImplementation, GetValue_Basic) {
    std::vector<std::vector<int>> expected = {
        { 0, 1, 2 },
        { 3, 4, 5 },
        { 6, 7, 8 },
    };

    Matrix matrix(expected);

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; j < expected[i].size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, GetValue_Random) {
    std::vector<std::vector<int>> expected = {
        { 25, 35, 45, 28 },
        { 15, 45, 45, 34 },
        { 80, 80, 80, 11 },
        { 4,   8,  9, 11 },
    };

    Matrix matrix(expected);

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; j < expected[i].size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, SetValue_Basic) {
    std::vector<std::vector<int>> initial = {
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 },
    };
    std::vector<std::vector<int>> expected = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
    };

    Matrix matrix(initial);

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; j < expected[i].size(); j++) {
            matrix.set_value(i, j, expected[i][j]);
        }
    }

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; j < expected[i].size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, SetValue_Random) {
    std::vector<std::vector<int>> initial = {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    };
    std::vector<std::vector<int>> expected = {
        { 15, 22, 33, 44 },
        { 55, 22, 33, 44 },
        { 45, 22, 33, 11 },
        { 15, 22, 37, 44 },
    };

    Matrix matrix(initial);

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; j < expected[i].size(); j++) {
            matrix.set_value(i, j, expected[i][j]);
        }
    }

    for (int i = 0; i < expected.size(); i++) {
        for (int j = 0; j < expected[i].size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, Addition_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
    };

    Matrix matrix1(initial);
    Matrix matrix2(initial);
    auto result = matrix1 + matrix2;

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial[i].size(); j++) {
            EXPECT_EQ(result.get_value(i, j), 2);
        }
    }
}

TEST(MatrixImplementation, Addition_Random) {
    std::vector<std::vector<int>> initial1 = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };
    std::vector<std::vector<int>> initial2 = {
        { 6, 3, 7 },
        { 8, 6, 6 },
        { 3, 3, 5 },
    };
    std::vector<std::vector<int>> expected = {
        { 6,  3,  15 },
        { 14, 13, 14 },
        { 7,  4,  11 },
    };

    Matrix matrix1(initial1);
    Matrix matrix2(initial2);
    auto result = matrix1 + matrix2;

    for (int i = 0; i < initial1.size(); i++) {
        for (int j = 0; j < initial1[i].size(); j++) {
            EXPECT_EQ(result.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, Multiplication_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
    };

    Matrix matrix1(initial);
    Matrix matrix2(initial);
    auto result = matrix1 * matrix2;

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial[i].size(); j++) {
            EXPECT_EQ(result.get_value(i, j), 3);
        }
    }
}

TEST(MatrixImplementation, Multiplication_Random) {
    std::vector<std::vector<int>> initial1 = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };
    std::vector<std::vector<int>> initial2 = {
        { 6, 3, 7 },
        { 8, 6, 6 },
        { 3, 3, 5 },
    };
    std::vector<std::vector<int>> expected = {
        { 24,  24, 40  },
        { 116, 84, 124 },
        { 50,  36, 64  },
    };

    Matrix matrix1(initial1);
    Matrix matrix2(initial2);
    auto result = matrix1 * matrix2;

    for (int i = 0; i < initial1.size(); i++) {
        for (int j = 0; j < initial1[i].size(); j++) {
            EXPECT_EQ(result.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, DiagonalSumMajor) {
    std::vector<std::vector<int>> initial = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };

    Matrix matrix(initial);
    EXPECT_EQ(matrix.sum_diagonal_major(), 13);
}

TEST(MatrixImplementation, DiagonalSumMinor) {
    std::vector<std::vector<int>> initial = {
        { 0, 0, 8 },
        { 6, 7, 8 },
        { 4, 1, 6 },
    };

    Matrix matrix(initial);
    EXPECT_EQ(matrix.sum_diagonal_minor(), 19);
}

TEST(MatrixImplementation, SwapRows_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 1, 1 },
        { 2, 2, 2 },
        { 3, 3, 3 },
    };

    std::vector<std::vector<int>> expected = {
        { 2, 2, 2 },
        { 1, 1, 1 },
        { 3, 3, 3 },
    };

    Matrix matrix(initial);
    matrix.swap_rows(0, 1);

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial[i].size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, SwapRows_Random) {
    std::vector<std::vector<int>> initial = {
        { 3, 1, 4, 1 },
        { 5, 9, 2, 6 },
        { 5, 3, 5, 8 },
        { 9, 7, 9, 3 }
    };
    std::vector<std::vector<int>> expected = {
        { 5, 3, 5, 8 },
        { 5, 9, 2, 6 },
        { 3, 1, 4, 1 },
        { 9, 7, 9, 3 }
    };

    Matrix matrix(initial);
    matrix.swap_rows(0, 2);

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial[i].size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, SwapCols_Basic) {
    std::vector<std::vector<int>> initial = {
        { 1, 2, 3 },
        { 1, 2, 3 },
        { 1, 2, 3 },
    };

    std::vector<std::vector<int>> expected = {
        { 3, 2, 1 },
        { 3, 2, 1 },
        { 3, 2, 1 },
    };

    Matrix matrix(initial);
    matrix.swap_cols(0, 2);

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial[i].size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, SwapCols_Random) {
    std::vector<std::vector<int>> initial = {
        { 3, 1, 4, 1 },
        { 5, 9, 2, 6 },
        { 5, 3, 5, 8 },
        { 9, 7, 9, 3 }
    };

    std::vector<std::vector<int>> expected = {
        { 1, 1, 4, 3 },
        { 6, 9, 2, 5 },
        { 8, 3, 5, 5 },
        { 3, 7, 9, 9 }
    };

    Matrix matrix(initial);
    matrix.swap_cols(0, 3);

    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial[i].size(); j++) {
            EXPECT_EQ(matrix.get_value(i, j), expected[i][j]);
        }
    }
}

TEST(MatrixImplementation, OutOfBoundsThrowsException) {
    Matrix matrix({
        { 25, 35, 45 },
        { 15, 45, 45 },
        { 80, 80, 80 },
    });

    EXPECT_THROW(matrix.get_value(4, 4), std::out_of_range);
}

TEST(MatrixImplementation, SetValue_OutOfBoundsThrowsException) {
    std::vector<std::vector<int>> initial = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
    };
    Matrix matrix(initial);
    EXPECT_THROW(matrix.set_value(3, 0, 100), std::out_of_range);
    EXPECT_THROW(matrix.set_value(0, 3, 100), std::out_of_range);
}

TEST(MatrixImplementation, SwapRows_OutOfBoundsThrowsException) {
    std::vector<std::vector<int>> initial = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
    };
    Matrix matrix(initial);
    EXPECT_THROW(matrix.swap_rows(0, 3), std::out_of_range);
}

TEST(MatrixImplementation, SwapCols_OutOfBoundsThrowsException) {
    std::vector<std::vector<int>> initial = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
    };
    Matrix matrix(initial);
    EXPECT_THROW(matrix.swap_cols(1, 3), std::out_of_range);
}

TEST(MatrixImplementation, Multiplication_Identity) {
    std::vector<std::vector<int>> identity = {
        { 1, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 1 },
    };
    std::vector<std::vector<int>> matrixData = {
        { 5, 7, 9 },
        { 2, 3, 4 },
        { 6, 8, 1 },
    };
    Matrix id(identity);
    Matrix m(matrixData);
    Matrix product = id * m;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(product.get_value(i, j), matrixData[i][j]);
        }
    }
}

TEST(MatrixImplementation, Addition_ExceptionDifferentDimensions) {
    std::vector<std::vector<int>> matrix1 = {
        { 1, 2 },
        { 3, 4 },
    };
    std::vector<std::vector<int>> matrix2 = {
        { 5, 6, 7 },
        { 8, 9, 10 },
        { 11, 12, 13 },
    };
    EXPECT_THROW(Matrix(matrix1) + Matrix(matrix2), std::invalid_argument);
}
