#include <bits/stdc++.h>

using namespace std;

int solve(int mine[][4], int n, int m, int sr, int sc, vector<vector<int> > dp) {

    int ans = 0, g1, g2, g3;
    for(int j = m-1; j >= 0; j--) {

        for(int i = 0; i < n; i++) {

            g1 = 0;
            g2 = 0;
            g3 = 0;
            if(j == m-1)
                dp[i][j] = mine[i][j];
            if(j != m-1 && i != 0)
                g1 = mine[i][j] + dp[i-1][j+1];
            if(j != m-1)
                g2 = mine[i][j] + dp[i][j+1];
            if(j != m-1 && i != n-1)
                g2 = mine[i][j] + dp[i+1][j+1];
            if(j != m-1)
                dp[i][j] = max(g1, max(g2, g3));
        }
    }
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i][0]);

    return ans;
}

int main() {

    int n = 4, m = 4;
    vector<vector<int> > dp(n, vector<int>(m, 0));
    int mine[4][4] = {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};

    cout<<solve(mine, 4, 4, 0, 0, dp)<<endl;
    return 0;
}