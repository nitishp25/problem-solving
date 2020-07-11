#include <bits/stdc++.h>

using namespace std;

int solve(int sr, int sc, int er, int ec, vector<vector<int> > &dp) {

    for(int i = er; i >= sr; i--) {
        for(int j = ec; j >= sc; j--) {
            if(i == er && j == ec) {
                dp[i][j] = 1;
                continue;
            }
            for(int jump = 1; jump+j <= ec; jump++)
                dp[i][j] += dp[i][j+jump];
            for(int jump = 1; jump+i <= er; jump++)
                dp[i][j] += dp[i+jump][j];
            for(int jump = 1; jump+j <= ec && jump+i <= er; jump++)
                dp[i][j] += dp[i+jump][j+jump];
        }
    }

    return dp[0][0];
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