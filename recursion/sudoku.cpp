#include <bits/stdc++.h>

using namespace std;

int isSafe(int sudoku[9][9], int i, int j, int k) {

    for(int c = 0; c < 9; c++) {
        if(sudoku[i][c] == k) {
            return 0;
        }
    }
    for(int r = 0; r < 9; r++) {
        if(sudoku[r][j] == k) {
            return 0;
        }
    }
    int row = (i/3)*3;
    int col = (j/3)*3;
    for(int r = row; r < row+3; r++) {
        for(int c = col; c < col+3; c++) {
            if(sudoku[r][c] == k) {
                return 0;
            }
        }
    }
    return 1;

}

int solve(int sudoku[9][9], int i, int j) {

    if(i == 9 && j == 0) {
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                cout<<sudoku[r][c]<<" ";
            }
            cout<<endl;
        }
        return 1;
    }

    if(sudoku[i][j] == 0) {
        for(int k = 1; k < 10; k++) {
            if(isSafe(sudoku, i, j, k)) {
                sudoku[i][j] = k;
                if(j == 8) {
                    if(solve(sudoku, i+1, 0))
                        return 1;
                }
                else {
                    if(solve(sudoku, i, j+1))
                        return 1;
                }
                sudoku[i][j] = 0;
            }
        }
        return 0;
    }
    else {
        if(j == 8) {
            return solve(sudoku, i+1, 0);
        }
        else {
            return solve(sudoku, i, j+1);
        }
    }
}

int main() {

    int sudoku[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    solve(sudoku, 0, 0);

    return 0;
}