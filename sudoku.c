#include <stdio.h>
#include <stdlib.h>
struct SudokuNode {
    int value;                 
    struct SudokuNode* right; 
    struct SudokuNode* down; 
};

struct SudokuNode* createSudokuNode(int value) {
    struct SudokuNode* node = (struct SudokuNode*)malloc(sizeof(struct SudokuNode));
    node->value = value;
    node->right = NULL;
    node->down = NULL;
    return node;
}

int main() {
    int sudokuGrid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    struct SudokuNode* grid[9][9];

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            grid[row][col] = createSudokuNode(sudokuGrid[row][col]);
        }
    }

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (col < 8) {
                grid[row][col]->right = grid[row][col + 1];
            }
            if (row < 8) {
                grid[row][col]->down = grid[row + 1][col];
            }
        }
    }
    return 0;
}
