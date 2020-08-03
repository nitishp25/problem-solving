#include <iostream>
#include <vector>

using namespace std;

vector<int> LIS(vector<int> arr) {

    vector<int> dp(arr.size(), 1);
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return dp;
}

vector<int> LDS(vector<int> arr) {

    vector<int> dp(arr.size(), 1);
    for(int i = arr.size() - 1; i >= 0; i--) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return dp;
}

int LBS(vector<int> arr, vector<int> LIS, vector<int> LDS) {

    int ans = 1;
    for(int i = 0; i < arr.size(); i++)
        ans = max(ans, LIS[i] + LDS[i] - 1);
    return ans;
}

int main() {

    vector<int> arr{80, 60, 30, 40, 20, 10};
    vector<int> lis = LIS(arr);
    vector<int> lds = LDS(arr);
    cout<<LBS(arr, lis, lds)<<endl;

    return 0;
}