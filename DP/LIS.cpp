#include <iostream>
#include <vector>

using namespace std;

int solve(int arr[], int idx, vector<int> &dp, int* ans) {
    int res;
    if(idx == 8)
        return 1;
    if(dp[idx] != 0)
        return dp[idx];
    for(int i = idx+1; i < 9; i++) {
        res = solve(arr, i, dp, ans);
        if(arr[idx] < arr[i] && res+1 > dp[idx])
            dp[idx] = res + 1;
    }
    if(dp[idx] > *ans)
        *ans = dp[idx];
    return dp[idx];
}

int main() {

    int arr[] = {100, 22, 9, 33, 21, 50, 41, 60, 80}, ans = 0;
    vector<int> dp(9, 0);
    solve(arr, 0, dp, &ans);
    cout<<ans<<endl;

    return 0;
}