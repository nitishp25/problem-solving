#include <iostream>
#include <vector>

using namespace std;

int solve(string a, string b, vector<vector<int> > &dp) {

    if(a.length() == 0 || b.length() == 0)
        return 0;

    if(dp[dp.size() - a.length()][dp[0].size() - b.length()] != 0)
        return dp[dp.size() - a.length()][dp[0].size() - b.length()];

    if(a[0] == b[0])
        dp[dp.size() - a.length()][dp[0].size() - b.length()] = solve(a.substr(1), b.substr(1), dp) + 1;
    else
        dp[dp.size() - a.length()][dp[0].size() - b.length()] = max(solve(a.substr(1), b, dp), solve(a, b.substr(1), dp));

    return dp[dp.size() - a.length()][dp[0].size() - b.length()];
}

int main() {

    string a = "AGGTAB", b = "GXTXAYB";
    vector<vector<int> > dp(a.length(), vector<int>(b.length(), 0));
    cout<<solve(a, b, dp)<<endl;

    return 0;
}