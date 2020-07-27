#include <iostream>
#include <vector>

using namespace std;

int solve(string a, string b, vector<vector<int> > dp) {

    for(int i = a.length() - 1; i >= 0; i--) {
        for(int j = b.length() - 1; j >= 0; j--) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i+1][j+1] + 1;
            }
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[0][0];
}

int main() {

    string a = "ABTHERC", b = "DSFRTHEBC";
    vector<vector<int> > dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    cout<<solve(a, b, dp)<<endl;

    return 0;
}