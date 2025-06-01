// Link matrix_utils.cpp: g++ .\8zero_matrix.cpp .\matrix_utils.cpp

#include <iostream>
#include <cassert>
#include "matrix_utils.h"
#include <vector>
#include <set>

void zeroMatrix(std::vector<std::vector<int>>& matrix) {
    int m = static_cast<int>(matrix.size());
    int n = static_cast<int>(matrix[0].size());
    std::set<int> rows;
    std::set<int> columns;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                rows.insert(i);
                columns.insert(j);
            }
        }
    }

    for (int i : rows)
    {
        zeroRow(matrix, i);
    }
    for (int j : columns) {
        zeroColumn(matrix, j);
    }
    
    return;
}

int main () {
    std::vector<std::vector<int>> matrix = {
        {1, 0, 1},
        {1, 1, 1},
        {1, 1, 1},
        {0, 1, 1}
    };
    std::vector<std::vector<int>> matrixResult = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 0}
    };
    zeroMatrix(matrix);
    assert(matrix == matrixResult);
    std::cout << "All tests were passed." << std::endl;
    return 0;
}