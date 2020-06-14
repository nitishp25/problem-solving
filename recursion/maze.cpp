#include <bits/stdc++.h>

using namespace std;

void solve(int maze[4][4], int i, int j, int sol[4][4], int visit[4][4]) {

    if(i==3 && j==3) {
        sol[i][j] = 1;
        for(int r=0; r<4; r++) {
            for(int c=0; c<4; c++) {
                cout<<sol[r][c]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    if(i>3 || j>3)
        return;

    if(visit[i][j] == 1)
        return;

    if(maze[i][j] == 1) {
        sol[i][j] = 1;
        visit[i][j] = 1;

        solve(maze, i, j+1, sol, visit);

        solve(maze, i+1, j, sol, visit);

        solve(maze, i, j-1, sol, visit);

        solve(maze, i-1, j, sol, visit);

        sol[i][j] = 0;

    }
    return;
}

int main() {

    int maze[4][4] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } };

    int sol[4][4] = { { 0, 0, 0, 0 }, 
                       { 0, 0, 0, 0 }, 
                       { 0, 0, 0, 0 }, 
                       { 0, 0, 0, 0 } };


    solve(maze, 0, 0, sol, sol);

    return 0;
}