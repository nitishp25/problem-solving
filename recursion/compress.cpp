#include <bits/stdc++.h>
#include <string>

using namespace std;

void solve(string str, string ans, int count) {

    if(str.length() == 1) {
        ans = ans + to_string(count) + str[0];
        cout<<ans<<endl;
        return;
    }

    char curr = str[0];
    char next = str.substr(1)[0];

    if(curr == next) {
        solve(str.substr(1), ans, count + 1);
    }
    else {
        solve(str.substr(1), ans + to_string(count) + curr, 1);
    }

}

int main() {

    string str = "aaaabbbcc";

    solve(str, "", 1);

    return 0;
}