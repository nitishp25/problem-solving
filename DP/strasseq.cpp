#include <iostream>
#include <vector>

using namespace std;

bool solve(string a, string b) {
    if(a.length() == 0)
        return true;
    if(b.length() == 0)
        return false;
    if(a[0] == b[0])
        return solve(a.substr(1), b.substr(1));
    else
        return solve(a, b.substr(1));
}

bool solve1(string a, string b) {

    int j = 0;
    for(int i = 0; i < b.length(), j < a.length(); i++) {
        if(a[j] = b[i])
            j++;
    }
    if(j == a.length())
        return true;
    else
        return false;
}

int main() {

    string a = "AXY", b = "ADXCPY";
    cout<<solve(a, b)<<endl;
    cout<<solve1(a, b)<<endl;

    return 0;
}