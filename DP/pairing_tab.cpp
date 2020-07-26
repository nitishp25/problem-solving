#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> dp) {

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
    }

    return dp[n];
}

int main() {

    int n;
    n = 3;
    vector<int> dp;
    for(int i = 0; i <= n; i++)
        dp.push_back(0);
    cout<<solve(n, dp)<<endl;

    return 0;
}