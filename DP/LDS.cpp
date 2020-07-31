#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> arr, int idx, vector<int> &dp, int *ans) {
    if(idx == arr.size() - 1)
        return 1;
    if(dp[idx] != 1)
        return dp[idx];
    int res;
    for(int i = idx + 1; i < arr.size(); i++) {
        res = solve(arr, i, dp, ans);
        if(arr[idx] > arr[i] && res + 1 > dp[idx])
            dp[idx] = res + 1;
    }
    if(dp[idx] > *ans)
        *ans = dp[idx];
    return dp[idx];
}

int main() {

    vector<int> arr{1, 4, 2, 43, 21, 5, 3};
    vector<int> dp(arr.size(), 1);
    int ans = 0;
    solve(arr, 0, dp, &ans);
    cout<<ans<<endl;

    return 0;
}