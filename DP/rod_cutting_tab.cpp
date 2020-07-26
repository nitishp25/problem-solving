#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int cost[]) {

    int max_cost, dp[n+1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        max_cost = 0;
        for(int j = 0; j < i; j++)
            max_cost = max(max_cost, cost[i-j-1] + dp[j]);
        dp[i] = max_cost;
    }
    return dp[n];
}

int main() {

    int n;
    n = 8;
    int cost[] = {3, 5, 8, 9, 10, 17, 17, 20};

    cout<<solve(n, cost)<<endl;

    return 0;
}