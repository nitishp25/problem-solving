#include <bits/stdc++.h>

using namespace std;

int solve(int sr, int sc, int er, int ec, vector<vector<int> > &dp) {

    if(sr == er && sc == ec) {
        dp[er][ec] = 1;
        return dp[er][ec];
    }

    if(dp[sr][sc] != 0)
        return dp[sr][sc];
    
    int count = 0;
    for(int i = 1; (i + sc) <= ec; i++) {
        count += solve(sr, sc+i, er, ec, dp);
    }
    for(int i = 1; (i + sr) <= er; i++) {
        count += solve(sr+i, sc, er, ec, dp);
    }
    for(int i = 1; ((i + sc) <= ec) && ((i + sr) <= er); i++) {
        count += solve(sr+i, sc+i, er, ec, dp);
    }
    dp[sr][sc] = count;
    return dp[sr][sc];

}

int main() {

    vector<vector<int> > dp;
    vector<int> dp1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            dp1.push_back(0);
        }
        dp.push_back(dp1);
    }
    cout<<solve(0, 0, 2, 2, dp)<<endl;

    return 0;
}