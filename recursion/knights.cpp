#include <bits/stdc++.h>

using namespace std;

int isSafe(int board[8][8], int x, int y) {

    return (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == -1); 
}

int solve(int boards[8][8], int move, int i, int j) {

    if(move == 64) {
        for(int r = 0; r < 8; r++) {
            for(int c = 0; c < 8; c++) {
                cout<<boards[r][c]<<" ";
            }
            cout<<endl;
        }
        return 1;
    }

    if(isSafe(boards, i, j)) {
        boards[i][j] = move;

        if(solve(boards, move+1, i+2, j+1) == 1)
            return 1;
        if(solve(boards, move+1, i+1, j+2) == 1)
            return 1;
        if(solve(boards, move+1, i-1, j+2) == 1)
            return 1;
        if(solve(boards, move+1, i-2, j+1) == 1)
            return 1;
        if(solve(boards, move+1, i-2, j-1) == 1)
            return 1;
        if(solve(boards, move+1, i-1, j-2) == 1)
            return 1;
        if(solve(boards, move+1, i+1, j-2) == 1)
            return 1;
        if(solve(boards, move+1, i+2, j-1) == 1)
            return 1;

        boards[i][j] = -1;
    }
    
    return 0;

}

int main() {

    int board[8][8] =   {{-1, -1, -1, -1, -1, -1, -1, -1},
                        {-1, -1, -1, -1, -1, -1, -1, -1},
                        {-1, -1, -1, -1, -1, -1, -1, -1},
                        {-1, -1, -1, -1, -1, -1, -1, -1},
                        {-1, -1, -1, -1, -1, -1, -1, -1},
                        {-1, -1, -1, -1, -1, -1, -1, -1},
                        {-1, -1, -1, -1, -1, -1, -1, -1},
                        {-1, -1, -1, -1, -1, -1, -1, -1}};

    //board[0][0] = 0;

    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            cout<<board[r][c]<<" ";
        }
        cout<<endl;
    }

    solve(board, 0, 0, 0);

    return 0;
}