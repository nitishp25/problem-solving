#include <bits/stdc++.h>

using namespace std;

int solve(int start, int end, vector<int> &dp) {

    if(start == end) {
        dp[start] = 1;
        return dp[start];
    }

    if(dp[start] != 0)
        return dp[start];

    for(int i = 1; i < 7; i++) {
        if(start+i <= end) {
            dp[start] += solve(start+i, end, dp);
        }
    }
    return dp[start];
}

int main() {

    vector<int> dp;
    int n;
    n = 4;
    for(int i = 0; i <= n; i++) {
        dp.push_back(0);
    }
    cout<<solve(0, n, dp)<<endl;

    return 0;
}