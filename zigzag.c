#include <stdio.h>

#define ROWS 5
#define COLS 4

void zigzag(int matrix[ROWS][COLS]){
    
    /*concept: */
    /*even diagonals are printed in a bottom-up direction*/
    /*odd diagonals are printed in a top-down direction*/

    
    int diagonal = 0;
    int max_diagonal = ROWS + COLS - 2;

    for (diagonal = 0; diagonal <= max_diagonal; diagonal++) {
        if (diagonal % 2) {
            // Odd-numbered diagonal
            int row = (diagonal < COLS) ? 0 : diagonal - COLS + 1;
            int col = (diagonal < COLS) ? diagonal : COLS - 1;
            while (row < ROWS && col >= 0) {
                printf("%d ", matrix[row][col]);
                row++;
                col--;
            }
        } else {
            // Even-numbered diagonal
            int row = (diagonal < ROWS) ? diagonal : ROWS - 1;
            int col = (diagonal < ROWS) ? 0 : diagonal - ROWS + 1;
            while (row >= 0 && col < COLS) {
                printf("%d ", matrix[row][col]);
                row--;
                col++;
            }
        }
    }
    
}

int main() {
    /*test matrix*/
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
    };

    zigzag(matrix);

    return 0;
}
