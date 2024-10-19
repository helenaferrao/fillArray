#include "Std2DArrays.h"
#include <iostream>

void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    int startValue = 1;

    // Fill starting from the first column in each row, bottom to top
    for (int startRow = rows - 1; startRow >= 0; --startRow) {
        int r = startRow, c = 0;
        while (r < rows && c < columns) {
            arr[r][c] = startValue++;
            ++r;
            ++c;
        }
    }

    // Then, fill starting from the second column in the top row, left to right
    for (int startCol = 1; startCol < columns; ++startCol) {
        int r = 0, c = startCol;
        while (r < rows && c < columns) {
            arr[r][c] = startValue++;
            ++r;
            ++c;
        }
    }
}

void printArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
