#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int m, vector<int> &dp) {

    if(n == m) {
        dp[m] = 2;
        return dp[m];
    }
    if(m < n) {
        dp[m] = 1;
        return dp[m];
    }
    if(dp[m] != 0)
        return dp[m];

    dp[m] = solve(n, m-1, dp) + solve(n, m-n, dp);
    return dp[m];
}

int main() {

    int n, m;
    n = 2;
    m = 4;
    vector<int> dp(m, 0);

    cout<<solve(n, m, dp)<<endl;

    return 0;
}