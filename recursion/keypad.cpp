#include <bits/stdc++.h>

using namespace std;

void solve(int num, string str[], string output) {

    if(num == 0) {
        cout<<output<<endl;
        return;
    }

    int n = num%10;
    string s = str[n];

    for(int i = 0; i < s.length(); i++) {
        solve(num/10, str, s[i] + output);
    }
    return;
}

int main() {

    string str[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";

    int num = 234;

    solve(num, str, output);

    return 0;
}