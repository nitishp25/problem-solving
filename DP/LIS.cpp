#include <iostream>
#include <vector>

using namespace std;

int solve(int arr[], int idx, vector<int> &dp) {
    int _max = 0;
    if(idx == 8)
        return 1;
    if(dp[idx] != 0)
        return dp[idx];
    for(int i = idx+1; i < 9; i++) {
        if(arr[idx] < arr[i]) {
            _max = max(_max, solve(arr, i, dp) + 1);
        }
    }
    dp[idx] = _max;
    return _max;
}

int main() {

    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> dp(9, 0);
    cout<<solve(arr, 0, dp)<<endl;

    return 0;
}