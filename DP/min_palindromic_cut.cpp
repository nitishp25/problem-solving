#include <bits/stdc++.h>

using namespace std;

bool isPalin(string s) {

    for(int i = 0, j = s.length() - 1; i < s.length(), j >= 0; i++, j--) {
        if(s[i] != s[j])
            return false;
    }
    return true;
}

int solve(string s, int i, int j, vector<vector<int> > &dp) {

    if(isPalin(s))
        return 0;
    if(dp[i][j] != 0)
        return dp[i][j];
    int ans = INT16_MAX;
    for(int k = i; k < j; k++) {
        ans = min(ans, 1 + solve(s.substr(i, k-i+1), i, k, dp) + solve(s.substr(k), k, j, dp));
    }
    dp[i][j] = ans;
    return ans;
}

int main() {

    string s = "ababbbabbababa";
    vector<vector<int> > dp(s.length(), vector<int>(s.length(), 0));
    cout<<solve(s, 0, s.length() - 1, dp)<<endl;

    return 0;
}