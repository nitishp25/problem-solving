#include <bits/stdc++.h>

using namespace std;

int solve(int n, int *dp) {

    if(n == 0 || n == 1) {
        dp[n] = n;
        return dp[n];
    }

    if(dp[n] != -1)
        return dp[n];

    dp[n] = solve(n-1, dp) + solve(n-2, dp);
    return dp[n];

}

int main() {

    int dp[1000];
    for(int i = 0; i < 1000; i++)
        dp[i] = -1;

    cout<<solve(6, dp)<<endl;
    for(int i = 0; i < 7; i++)
        cout<<dp[i]<<" "<<endl;
}