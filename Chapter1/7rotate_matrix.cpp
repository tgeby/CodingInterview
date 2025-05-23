#include <iostream>
#include <vector>
#include <cassert>
#include <string>

bool is_square(std::vector<std::vector<int>>& matrix) {
    size_t n = matrix.size();
    for (const auto& row: matrix) {
        if (row.size() != n) return false;
    }
    return true;
}

void print_matrix(std::vector<std::vector<int>> matrix) {
    for (const auto& row : matrix) {
        for (int i : row) {
          std::cout << std::to_string(i) << ", ";  
        }
        std::cout << std::endl;
    }
    std::cout << "Result Matrix complete." << std::endl;
}

std::vector<std::vector<int>> rotate_matrix(std::vector<std::vector<int>>& matrix) {
    assert(is_square(matrix) == true);
    size_t n = matrix.size(); 
    std::vector<std::vector<int>> result(n, std::vector<int>(n));
    for (size_t column=0; column<n; column++) {
        for (int row = static_cast<int>(n)-1; row >= 0; row--) {
            result[column][n-1-row] = matrix[row][column];
        }
    }
    return result;
} 

int main() {
        // Test case 1: 2x2 identity matrix
    std::vector<std::vector<int>> matrix_1 = {
        {1, 0},
        {0, 1}
    };
    std::vector<std::vector<int>> matrix_1_result = {
        {0, 1},
        {1, 0}
    };
    assert(rotate_matrix(matrix_1) == matrix_1_result);

    // Test case 2: 2x2 full matrix
    std::vector<std::vector<int>> matrix_2 = {
        {1, 2},
        {3, 4}
    };
    std::vector<std::vector<int>> matrix_2_result = {
        {3, 1},
        {4, 2}
    };
    assert(rotate_matrix(matrix_2) == matrix_2_result);

    // Test case 3: 3x3 matrix
    std::vector<std::vector<int>> matrix_3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> matrix_3_result = {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}
    };
    assert(rotate_matrix(matrix_3) == matrix_3_result);

    // Test case 4: 1x1 matrix
    std::vector<std::vector<int>> matrix_4 = {
        {1}
    };
    std::vector<std::vector<int>> matrix_4_result = {
        {1}
    };
    assert(rotate_matrix(matrix_4) == matrix_4_result);

    // Test case 5: 4x4 matrix
    std::vector<std::vector<int>> matrix_5 = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15,16}
    };
    std::vector<std::vector<int>> matrix_5_result = {
        {13, 9, 5, 1},
        {14,10, 6, 2},
        {15,11, 7, 3},
        {16,12, 8, 4}
    };
    assert(rotate_matrix(matrix_5) == matrix_5_result);
    std::cout << "All tests were passed." << std::endl;
    return 0;
}