#include <iostream>
#include <vector>

using namespace std;

long int solve(vector<int> arr, int i, int j, vector<vector<long int> > &dp) {

    if(j == i+1)
        return 0;
    if(dp[i][j] != INT16_MAX)
        return dp[i][j];

    for(int k = i+1; k < j; k++) {
        dp[i][j] = min(dp[i][j], solve(arr, i, k, dp) + solve(arr, k, j, dp) + (arr[i] * arr[k] * arr[j]));
    }
    return dp[i][j];
}

int main() {

    vector<int> arr{10, 20, 30, 40, 30};
    vector<vector<long int> > dp(arr.size(), vector<long int>(arr.size(), INT16_MAX));
    cout<<solve(arr, 0, 4, dp)<<endl;

    return 0;
}