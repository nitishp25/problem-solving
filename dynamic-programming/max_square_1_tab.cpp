#include <bits/stdc++.h>

using namespace std;

int solve(int matrix[][5], int n, int m, vector<vector<int> > &dp) {

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = matrix[i][j];
                continue;
            }
            if(matrix[i][j] == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
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

    cout<<solve(matrix, n, m, dp)<<endl;

    return 0;
}