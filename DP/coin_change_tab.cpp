#include <iostream>
#include <vector>

using namespace std;

int solve(int sum, vector<int> coins, vector<int> &dp) {

    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++) {
        for(int j = 1; j <= sum; j++) {
            if(j - coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    return dp[sum];
}

int main() {

    int sum = 4;
    vector<int> coins{1, 2, 3};
    vector<int> dp(sum+1, 0);
    cout<<solve(sum, coins, dp)<<endl;

    return 0;
}