#include <iostream>
#include "matrix_utils.h"

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row)
            std::cout << val << " ";
        std::cout << '\n';
    }
}

void zeroRow(std::vector<std::vector<int>>& matrix, int i) {
    for (int j = 0; j < matrix[0].size(); j++) {
        matrix[i][j] = 0;
    }
}

void zeroColumn(std::vector<std::vector<int>>& matrix, int j) {
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i][j] = 0;
    }
}