#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &dp) {

    if(n == 0) {
        dp[0] = 1;
        return dp[0];
    }
    if(dp[n] != 0)
        return dp[n];

    dp[n] += solve(n-1, dp);
    if(n >= 2)
        dp[n] += (n-1)*solve(n-2, dp);

    return dp[n];
}

int main() {

    int n;
    n = 2;
    vector<int> dp;
    for(int i = 0; i <= n; i++)
        dp.push_back(0);
    cout<<solve(n, dp)<<endl;

    return 0;
}