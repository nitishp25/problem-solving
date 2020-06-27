#include <bits/stdc++.h>

using namespace std;

long long solve(long long n, long long *dp) {

    if(n == 1 || n == 0) {
        dp[n] = n;
        return dp[n];
    }
    if(dp[n] != -1)
        return dp[n];

    dp[n] = max(n, solve(n/2, dp) + solve(n/3, dp) + solve(n/4, dp));

    return dp[n];
}

int main() {

    long long n;
    while(cin>>n) {
        // cin>>n;
        long long dp[n+1];
        for(long long i = 0; i < n+1; i++) {
            dp[i] = -1;
        }
        cout<<solve(n, dp)<<endl;
    }

    return 0;
}