#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> coins, int sum, vector<int> &dp, int index) {

    if(sum == 0) {
        dp[0] = 1;
        return 1;
    }
    if(dp[sum] != 0)
        return dp[sum];

    for(int i = index; i < coins.size(); i++) {
        if(sum - coins[i] >= 0) {
            dp[sum] += solve(coins, sum-coins[i], dp, index);
        }
    }    
    return dp[sum];
}

int main() {

    vector<int> coins{1, 2, 3};
    int sum = 4;
    vector<int> dp(sum+1, 0);

    cout<<solve(coins, sum, dp, 0)<<endl;

    return 0;
}