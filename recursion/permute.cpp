#include <bits/stdc++.h>

using namespace std;

void solve(string str, int index, set<int> s) {

    if(index == str.length()) {
        cout<<str<<endl;
        return;
    }

    s.clear();

    for(int i = index; i < str.length(); i++) {
        if(s.find(str[i]) == s.end()) {
            s.insert(str[i]);
            swap(str[index], str[i]);
            solve(str, index+1, s);
            swap(str[index], str[i]);
        }
    }
    return;
}

int main() {

    string str = "ACBC";
    set<int> s;

    solve(str, 0, s);

    return 0;
}