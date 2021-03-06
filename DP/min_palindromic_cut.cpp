#include <bits/stdc++.h>

using namespace std;

void isPalin(string s, vector<vector<int> > &dp) {

    for(int i = 0; i < s.length(); i++) {
        for(int si = 0, ei = i; ei < s.length(); si++, ei++) {
            if(i == 0) {
                dp[si][ei] = 1;
                continue;
            }
            if(i == 1 && s[si] == s[ei]) {
                dp[si][ei] = 1;
                continue;
            }
            if(s[si] == s[ei] && dp[si+1][ei-1] == 1)
                dp[si][ei] = 1;
        }
    }

}

int solve(string s, int i, int j, vector<vector<int> > &dp, vector<vector<int> > &palin) {

    if(palin[i][j])
        return 0;
    if(dp[i][j] != 0)
        return dp[i][j];
    int ans = INT16_MAX;
    for(int k = i; k < j; k++)
        ans = min(ans, 1 + solve(s, i, k, dp, palin) + solve(s, k+1, j, dp, palin));
    dp[i][j] = ans;
    return ans;
}

int main() {

    string s = "ababbbabbababa";
    vector<vector<int> > palin(s.length(), vector<int>(s.length(), 0));
    vector<vector<int> > dp(s.length(), vector<int>(s.length(), 0));
    isPalin(s, palin);
    cout<<solve(s, 0, s.length() - 1, dp, palin)<<endl;

    return 0;
}