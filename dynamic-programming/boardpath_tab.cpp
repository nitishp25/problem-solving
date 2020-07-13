#include <bits/stdc++.h>

using namespace std;

int solve(int start, int end, vector<int> dp) {

    dp[end] = 1;
    for(int i = end-1; i >= start; i--) {
        for(int j = 1; j < 7; j++) {
            if(j+i <= end)
                dp[i] += dp[j+i];
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