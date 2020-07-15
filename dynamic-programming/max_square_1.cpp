#include <bits/stdc++.h>

using namespace std;

int ans = 0;

int solve(int matrix[][5], int sr, int sc, vector<vector<int> > &dp) {

    int s1, s2, s3;

    if(sr == 0 || sc == 0) {
        dp[sr][sc] = matrix[sr][sc];
        return dp[sr][sc];
    }
    if(dp[sr][sc] != -1)
        return dp[sr][sc];

    s1 = solve(matrix, sr-1, sc, dp);
    s2 = solve(matrix, sr-1, sc-1, dp);
    s3 = solve(matrix, sr, sc-1, dp);
    if(matrix[sr][sc] == 0)
        dp[sr][sc] = 0;
    else
        dp[sr][sc] = min(s1, min(s2, s3)) + 1;

    ans = max(ans, dp[sr][sc]);

    return dp[sr][sc];
}

int main() {

    int n, m;
    n = 6;
    m = 5;
    vector<vector<int> > dp(n, vector<int>(m, -1));
    int matrix[][5] = {{0, 1, 1, 0, 1},  
                    {1, 1, 0, 1, 0},  
                    {0, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 1},  
                    {0, 0, 0, 0, 0}};

    solve(matrix, 5, 4, dp);
    cout<<ans<<endl;
    return 0;
}