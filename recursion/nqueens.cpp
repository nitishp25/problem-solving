#include <bits/stdc++.h>

using namespace std;

int isSafe(int board[4][4], int i, int j) {
    for(int k = 0; k < j; k++) {
        if(board[i][k])
            return 0;
    }
    int row = i, col = j;
    while(i > 0 && j > 0) {
        if(board[i-1][j-1])
            return 0;
        i--;
        j--;
    }
    while(row < 3 && col > 0) {
        if(board[row+1][col-1])
            return 0;
        row++;
        col--;
    }
    return 1;
}

int solve(int board[4][4], int queens, int index) {

    if(queens == 0) {
        return 1;
    }
    int count = 0;

    for(int i = 0; i < 4; i++) {
        if(isSafe(board, i, index)) {
            board[i][index] = 1;
            count += solve(board, queens-1, index+1);
            board[i][index] = 0;
        }
    }

    return count;
}

int main() {

    int board[4][4] = {{0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}};
    cout<<solve(board, 4, 0)<<endl;

    return 0;
}