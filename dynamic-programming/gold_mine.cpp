#include <bits/stdc++.h>

using namespace std;

int solve(int mine[][4], int n, int m, int sr, int sc, vector<vector<int> > &dp) {

    int g1 = -1, g2 = -1, g3 = -1;

    if(dp[sr][sc] != 0)
        return dp[sr][sc];

    if(sc == m-1) {
        for(int i = 0; i < n; i++)
            dp[i][sc] = mine[i][sc];
        return dp[sr][sc];
    }

    if(sr != 0 && sc != m-1)
        g1 = mine[sr][sc] + solve(mine, n, m, sr-1, sc+1, dp); 
    if(sc != m-1)
        g2 = mine[sr][sc] + solve(mine, n, m, sr, sc+1, dp);
    if(sr != n-1 && sc != m-1)
        g3 = mine[sr][sc] + solve(mine, n, m, sr+1, sc+1, dp);;

    dp[sr][sc] = max(g1, max(g2, g3));

    return dp[sr][sc];

}
 
int main() {

    int n, m, ans;
    ans = -1;
    n = 4;
    m = 4;
    vector<vector<int> > dp(n, vector<int>(m, 0));

    int mine[4][4] = {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};

    for(int i = 0; i < n; i++)
        ans = max(ans, solve(mine, 4, 4, i, 0, dp));
    cout<<ans<<endl;

    return 0;
}