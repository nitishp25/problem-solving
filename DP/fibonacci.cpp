#include <bits/stdc++.h>

using namespace std;

int solve(int n) {

    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i < n+1; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];

}

int main() {

    int n;
    cin>>n;

    cout<<solve(n)<<endl;

    return 0;
}