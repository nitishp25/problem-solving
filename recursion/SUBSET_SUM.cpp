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

    for(int i = start; i < size; i++) {
        if(arr[i] <= k) {
            out.push_back(arr[i]);
            subset(arr, start+1, size, k-arr[i], out);
            out.pop_back();
        }
        else
            subset(arr, start+1, size, k, out);
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