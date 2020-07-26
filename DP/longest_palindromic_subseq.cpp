#include <iostream>
#include <vector>

using namespace std;

int solve(string s, vector<vector<int> > dp) {

    for(int i = 0; i < s.length(); i++) {
        for(int j = i, si = 0; j < s.length(); j++, si++) {
            if(i == 0)
                dp[si][j] = 1;
            else if(s[si] == s[j])
                dp[si][j] = dp[si+1][j-1] + 2;
            else
                dp[si][j] = max(dp[si+1][j], dp[si][j-1]);
        }
    }
    return dp[0][s.length() - 1];
}

int main() {

    string s = "abaab";
    vector<vector<int> > dp(s.length(), vector<int>(s.length(), 0));
    cout<<solve(s, dp)<<endl;

    return 0;
}