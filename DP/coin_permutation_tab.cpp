#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> coins, int sum, vector<int> dp, int index) {

    dp[0] = 1;

    for(int i = 1; i <= sum; i++) {
        for(int j = 0; j < coins.size(); j++) {
            if(i - coins[j] >= 0) {
                dp[i] += dp[i - coins[j]];
            }
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