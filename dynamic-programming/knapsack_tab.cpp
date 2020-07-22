#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> values, vector<int> wts, int cap) {

    vector<vector<int> > dp(4, vector<int>(cap+1, 0));

    for(int i = 0; i < values.size(); i++) {
        for(int j = 0; j <= cap; j++) {
            if(i == 0 && wts[i] <= j) {
                dp[i][j] = values[i];
                continue;
            }
            if(wts[i] <= j && i != 0)
                dp[i][j] = max(values[i] + dp[i-1][j - wts[i]], dp[i-1][j]);
            else if(i != 0)
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[values.size() - 1][cap];
}

int main() {

    vector<int> values{60, 100, 120};
    vector<int> wts{10, 20, 30};
    int cap = 50;

    cout<<solve(values, wts, cap)<<endl;

    return 0;
}