#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int cost[], vector<int> &dp) {

    int curr_cost, max_cost = 0;
    if(n == 0)
        return 0;
    
    if(dp[n] != 0)
        return dp[n];

    for(int i = 0; i < n; i++) {
        curr_cost = cost[n-i-1] + solve(i, cost, dp);
        if(curr_cost > max_cost)
            max_cost = curr_cost;
    }
    dp[n] = max_cost;
    return max_cost;
}

int main() {

    int n;
    n = 8;
    int cost[] = {3, 5, 8, 9, 10, 17, 17, 20};
    vector<int> dp(n, 0);

    cout<<solve(n, cost, dp)<<endl;

    return 0;
}