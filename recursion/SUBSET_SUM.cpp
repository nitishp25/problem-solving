#include <bits/stdc++.h>

using namespace std;

void subset(int arr[], int start, int size, int k, vector<int> out) {

    if(start == size && k > 0){
        return;
    }

    if(k == 0) {
        for(int i = 0; i < out.size(); i++)
            cout<<out[i]<<" ";
        cout<<endl;
        return;
    }

    subset(arr, start+1, size, k, out);
    if(arr[start] <= k) {
        out.push_back(arr[start]);
        subset(arr, start+1, size, k - arr[start], out);
    }
    return;
}

int main() {

    int arr[] = {3, 27, 10, 1, 12};
    vector<int> out;
    int k = 13;

    subset(arr, 0, 5, k, out);

    return 0;
}