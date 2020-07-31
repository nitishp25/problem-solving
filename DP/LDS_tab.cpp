#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> arr) {

    int ans = 1;
    vector<int> dp(arr.size(), 1);
    for(int i = arr.size() - 1; i >= 0; i--) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {

    vector<int> arr{1, 4, 2, 43, 21, 5, 3};
    cout<<solve(arr)<<endl;

    return 0;
}