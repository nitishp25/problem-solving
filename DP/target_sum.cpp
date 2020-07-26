#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> arr, int sum, int index, vector<vector<int> > &dp) {

    if(sum == 0 || index == arr.size())
        return sum == 0 ? 1 : 0;

    if(dp[index][sum] != 0)
        return dp[index][sum];

    if(sum - arr[index] >= 0)
        dp[index][sum] += solve(arr, sum-arr[index], index+1, dp);
    dp[index][sum] += solve(arr, sum, index+1, dp);

    return dp[index][sum];
}

int main() {

    vector<int> arr{2, 3, 5, 6, 8, 10};
    int sum = 10;
    vector<vector<int> > dp(6, vector<int>(11, 0));
    cout<<solve(arr, sum, 0, dp)<<endl;

    return 0;
}