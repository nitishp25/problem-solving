#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> arr, vector<int> dp) {
    int ans = 1;

    for(int i = arr.size() - 1; i >= 0; i--) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] < arr[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {

    vector<int> arr{100, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> dp(arr.size(), 1);
    cout<<solve(arr, dp)<<endl;

    return 0;
}