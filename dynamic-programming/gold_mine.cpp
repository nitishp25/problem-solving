#include <bits/stdc++.h>

using namespace std;

int solve(int mine[][4], int n, int m, int sr, int sc, vector<vector<int> > &dp) {

    for(int i = 0; i < n; i++) {

        if(i != 0) {
        //    dp[i][sc] += 
        }

    }

}
 
int main() {

    vector<vector<int> > dp;
    vector<int> dp1;
    int n, m;
    n = 4;
    m = 4;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            dp1.push_back(-1);
        }
        dp.push_back(dp1);
    }
    int mine[4][4] = { {1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};
    cout<<solve(mine, n, m, 0, 0, dp)<<endl;

    return 0;
}