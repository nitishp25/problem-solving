#include <bits/stdc++.h>

using namespace std;

void solve(int arr[], int index, int sum1, int sum2, vector<int> a, vector<int> b) {

    if(index == 3) {
        if(sum1 == sum2) {
            for(int i = 0; i < a.size(); i++)
                cout<<a[i]<<" ";
            cout<<endl;
            for(int i = 0; i < b.size(); i++)
                cout<<b[i]<<" ";
            cout<<endl;
        }
        return;
    }

    a.push_back(arr[index]);
    solve(arr, index+1, sum1+arr[index], sum2, a, b);
    a.pop_back();
    b.push_back(arr[index]);
    solve(arr, index+1, sum1, sum2+arr[index], a, b);

}

int main() {

    int arr[] = {10, 20, 30};
    vector<int> a, b;
    solve(arr, 0, 0, 0, a, b);

    return 0;
}