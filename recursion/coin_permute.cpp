#include <bits/stdc++.h>

using namespace std;

void solve(int coins[], int sum, vector<int> ans, int added[]) {

    if(sum == 0) {
        for(int i = 0; i < ans.size(); i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    for(int i = 0; i < 4; i++) {
        if(coins[i] <= sum && !added[i]) {
            ans.push_back(coins[i]);
            added[i] = 1;
            solve(coins, sum - coins[i], ans, added);
            ans.pop_back();
            added[i] = 0;
        }
    }

}

int main() {

    int coins[] = {2, 3, 5, 7};
    int added[] = {0, 0, 0, 0};
    vector<int> ans;
    solve(coins, 10, ans, added);

    return 0;
}