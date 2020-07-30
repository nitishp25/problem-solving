#include <iostream>
#include <vector>

using namespace std;

int _max = -1;

int solve(string a, string b, vector<vector<int> > &dp, int i, int j) {

    if(i == a.length() || j == b.length())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(a[i] == b[j]) {
        dp[i][j] = solve(a, b, dp, i+1, j+1) + 1;
        _max = max(_max, dp[i][j]);
        return dp[i][j];
    }
    solve(a, b, dp, i+1, j);
    solve(a, b, dp, i, j+1);    

    dp[i][j] = 0;
    return dp[i][j];
}

int main() {

    string a = "ABHRDEGD", b = "FEWDEGAB";
    vector<vector<int> > dp(a.length(), vector<int>(b.length(), -1));
    solve(a, b, dp, 0, 0);
    cout<<_max<<endl;

    return 0;
}