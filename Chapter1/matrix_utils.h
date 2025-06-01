#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include <vector>

void printMatrix(const std::vector<std::vector<int>>& matrix);
void zeroRow(std::vector<std::vector<int>>& matrix, int i);
void zeroColumn(std::vector<std::vector<int>>& matrix, int j);

#endif
