#include <stdio.h>

int grid[9][9];
int count = 0;

int isValid(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) return 0;
    }

    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) return 0;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num)
                return 0;
        }
    }

    return 1;
}

void solve() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {

            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {
                        grid[row][col] = num;
                        solve();
                        grid[row][col] = 0; 
                    }
                }
                return; 
            }
        }
    }
    count++;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    solve();

    printf("%d\n", count);
    return 0;
}