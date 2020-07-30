#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> arr, vector<int> dp) {
    int _max;

    for(int i = arr.size() - 1; i >= 0; i--) {
        if(i == arr.size() - 1) {
            dp[i] = 1;
            continue;
        }
        _max = 0;
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] < arr[j]) {
                _max = max(_max, dp[j]+1);
            }
        }
        dp[i] = _max;
    }
    return dp[0];
}

int main() {

    vector<int> arr{10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> dp(arr.size(), 0);
    cout<<solve(arr, dp)<<endl;

    return 0;
}