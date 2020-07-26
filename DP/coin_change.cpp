#include <bits/stdc++.h>

using namespace std;

int solve(int sum, vector<int> coins, vector<vector<int> > &dp, int index, vector<int> ans) {

    if(sum == 0) {
        dp[0][index] = 1;
        for(int i = 0; i < ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        return 1;
    }

    if(dp[sum][index] != 0)
        return dp[sum][index];

    for(int i = index; i < coins.size(); i++) {
        if(coins[i] <= sum) {
            ans.push_back(coins[i]);
            dp[sum][index] += solve(sum-coins[i], coins, dp, i, ans);
            ans.pop_back();
        }
    }
    return dp[sum][index];
}

int main() {

    int sum = 4;
    vector<int> ans;
    vector<int> coins{ 1, 2, 3 };
    vector<vector<int> > dp(sum+1, vector<int>(4, 0));

    cout<<solve(sum, coins, dp, 0, ans)<<endl;

    return 0;
}