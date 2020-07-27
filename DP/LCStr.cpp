#include <iostream>
#include <vector>

using namespace std;

int solve(string a, string b, vector<vector<int> > &dp, int ans) {

    if(a.length() == 0 || b.length() == 0)
        return ans;

    if(dp[dp.size() - a.length()][dp[0].size() - b.length()] != 0)
        return dp[dp.size() - a.length()][dp[0].size() - b.length()];

    if(a[0] == b[0]) {
        ans = solve(a.substr(1), b.substr(1), dp, ans+1);
    }
    ans = max(max(solve(a.substr(1), b, dp, 0), solve(a, b.substr(1), dp, 0)), ans);

    dp[dp.size() - a.length()][dp[0].size() - b.length()] = ans;
    return ans;
}

int main() {

    string a = "ABHRDEG", b = "FEWDEGAB";
    vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));
    cout<<solve(a, b, dp, 0)<<endl;

    return 0;
}