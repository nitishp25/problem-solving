#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> values, vector<int> wts, int cap, vector<vector<int> > &dp, int idx, int value) {

    if(idx == values.size()) {
        dp[idx][cap] = value;
        return value;
    }

    if(dp[idx][cap] != 0)
        return dp[idx][cap];

    int v1 = 0, v2 = 0;
    if(wts[idx] <= cap)
        v1 = solve(values, wts, cap - wts[idx], dp, idx+1, value + values[idx]);
    v2 = solve(values, wts, cap, dp, idx+1, value);
    dp[idx][cap] = max(v1, v2);

    return dp[idx][cap];
}

int main() {

    vector<int> values{60, 100, 120};
    vector<int> wts{10, 20, 30};
    int cap = 50;
    vector<vector<int> > dp(4, vector<int>(cap+1, 0));

    cout<<solve(values, wts, cap, dp, 0, 0)<<endl;

    return 0;
}