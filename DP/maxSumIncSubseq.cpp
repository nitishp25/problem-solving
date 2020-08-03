#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> arr) {

    vector<int> dp(arr.size(), 0);
    int ans = 0;
    for(int i = arr.size() - 1; i >= 0; i--) {
        if(i == arr.size() - 1) {
            dp[i] = arr[i];
            continue;
        }
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[i] < arr[j]) {
                dp[i] = max(dp[i], arr[i] + dp[j]);
            }
        }
        if(dp[i] == 0)
            dp[i] = arr[i];
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {

    vector<int> arr{10, 5, 4, 3};
    cout<<solve(arr)<<endl;

    return 0;
}