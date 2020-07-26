#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int m, vector<int> &dp) {

    for(int i = 0; i <= m; i++) {
        if(i < n)
            dp[i] = 1;
        else
            dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[m];
}

int main() {

    int n, m;
    n = 2;
    m = 4;
    vector<int> dp(m+1, 0);

    cout<<solve(n, m, dp)<<endl;

    return 0;
}