#include <bits/stdc++.h>

using namespace std;

int solve(string s, vector<long long> &dp) {

    if(s.length() == 0) {
        dp[0] = 1;
        return dp[0];
    }
    if(dp[s.length()] != 0)
        return dp[s.length()];

    int ch = stoi(s.substr(0, 1));
    if(ch == 0) {
        dp[s.length()] = 0;
        return dp[s.length()];
    }
    else
        dp[s.length()] += solve(s.substr(1), dp);
           

    if(s.length() > 1) {
        if(s[0] == '0') {
            dp[s.length()] = 0;
            return dp[s.length()];
        }
        int ch = stoi(s.substr(0, 2));
        if(ch < 27) {
            dp[s.length()] += solve(s.substr(2), dp);
        }
    }

    return dp[s.length()];
}

int main() {

    string s;
    int n;
    while(cin>>s) {
        if(s == "0")
            break;
        n = s.length();
        vector<long long> dp(n+1);
        for(int i = 0; i < n+1; i++)
            dp[i] = 0;
        cout<<solve(s, dp)<<endl;
    }

    return 0;
}