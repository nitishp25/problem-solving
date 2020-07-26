#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> arr, int sum, vector<vector<int> > dp) {

    dp[0][0] = 1;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j <= sum; j++) {
            if(j == arr[i] && i == 0) {
                dp[i][j] = 1;
            }
            else {
                if(j - arr[i] >= 0 && i >= 1)
                    dp[i][j] += dp[i-1][j - arr[i]];
                if(i >= 1)
                    dp[i][j] += dp[i-1][j];
            }
        }
    }
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j <= sum; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[arr.size() - 1][sum];
}

int main() {

    vector<int> arr{2, 3, 5, 6, 8, 10};
    int sum = 10;
    vector<vector<int> > dp(6, vector<int>(11, 0));
    cout<<solve(arr, sum, dp)<<endl;

    return 0;
}