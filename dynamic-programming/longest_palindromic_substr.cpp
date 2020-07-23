#include <iostream>
#include <vector>

using namespace std;

int solve(string s, vector<vector<int> > dp) {
    int si, max_len = 0;
    string ans;
    for(int i = 0; i < s.length(); i++) {
        si = 0;
        for(int j = i; j < s.length(); j++) {
            if(i == 0)
                dp[si][j] = 1;
            else if(i == 1 && s[si] == s[j])
                dp[si][j] = 1;
            else if(s[si] == s[j] && dp[si+1][j-1] == 1)
                dp[si][j] = 1;
            if(dp[si][j] == 1) {
                if(j - si + 1 > max_len) {
                    max_len = j - si + 1;
                    ans = s.substr(si, max_len);
                }
            }
            si++;
        }
    }
    cout<<ans<<endl;
    return max_len;
}

int main() {

    string s = "abaab";
    vector<vector<int> > dp(s.length(), vector<int>(s.length(), 0));
    cout<<solve(s, dp)<<endl;

    return 0;
}