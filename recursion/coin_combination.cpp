#include <bits/stdc++.h>

using namespace std;

void solve(int coins[], int sum, vector<int> ans, int index) {

    if(sum == 0) {
        for(int i = 0; i < ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        return;
    }
    if(index == 4)
        return;

    solve(coins, sum, ans, index+1);
    if(coins[index] <= sum) {
        ans.push_back(coins[index]);
        solve(coins, sum - coins[index], ans, index+1);
    }
}

int main() {

    int coins[] = {2, 3, 5, 7};
    vector<int> ans;
    solve(coins, 10, ans, 0);

    return 0;
}