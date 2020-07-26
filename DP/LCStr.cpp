#include <iostream>
#include <vector>

using namespace std;

int solve(string a, string b, vector<vector<int> > dp) {

    int ans = 0;
    for(int i = 0; i < a.length(); i++) {
        for(int j = 0; j < b.length(); j++) {
            if(a[i] == b[j])
        }
    }

}

int main() {

    string a = "ABHRDEG", b = "FEWDEGAB";
    vector<vector<int> > dp(a.length(), vector<int>(b.length(), 0));

    return 0;
}