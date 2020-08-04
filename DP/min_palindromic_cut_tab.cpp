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

int solve(string s, vector<vector<int> > &palin) {

    vector<vector<int> > dp(s.length(), vector<int>(s.length(), 0));
    int ans;

    for(int gap = 1; gap < s.length(); gap++) {
        for(int si = 0, ei = gap; ei < s.length(); si++, ei++) {
            if(palin[si][ei] == 1) {
                dp[si][ei] = 0;
                continue;
            }
            ans = INT16_MAX;
            for(int k = si; k < ei; k++) {
                ans = min(ans, 1 + dp[si][k] + dp[k+1][ei]);
            }
            dp[si][ei] = ans;
        }
    }
    return dp[0][s.length() - 1];
}

int main() {

    string s = "ababbbabbababa";
    vector<vector<int> > palin(s.length(), vector<int>(s.length(), 0));
    isPalin(s, palin);
    cout<<solve(s, palin)<<endl;

    return 0;
}