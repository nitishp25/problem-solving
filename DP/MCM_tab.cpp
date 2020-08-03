#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> arr) {

    vector<vector<long int> > dp(arr.size(), vector<long int>(arr.size(), INT16_MAX));

    for(int gap = 1; gap < arr.size(); gap++) {
        for(int i = 0, j = gap; i < arr.size(), j < arr.size(); i++, j++) {
            if(gap == 1) {
                dp[i][j] = 0;
                continue;
            }
            for(int k = i+1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
            }
        }
    }
    return dp[0][arr.size() - 1];
}

int main() {

    vector<int> arr{10, 20, 30, 40, 30};
    cout<<solve(arr)<<endl;

    return 0;
}