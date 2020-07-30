#include <iostream>
#include <vector>

using namespace std;

int solve(string a, string b, vector<vector<int> > dp) {
    int _max = 0;
    for(int i = a.length() - 1; i >= 0; i--) {
        for(int j = b.length() - 1; j >= 0; j--) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i+1][j+1] + 1;
                _max = max(_max, dp[i][j]);
            }
        }
    }
    return _max;
}

int main() {

    string a = "ABHRDEG", b = "FEWDEGAB";
    vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));
    cout<<solve(a, b, dp)<<endl;

    return 0;
}