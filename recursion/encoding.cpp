#include <bits/stdc++.h>

using namespace std;

void encode(string num, char l[], string ans) {

    if(num.length() == 0) {
        cout<<ans<<endl;
        return;
    }

    int ch = stoi(num.substr(0, 1));
    if(ch == 0)
        encode(num.substr(1), l, ans);
    else
        encode(num.substr(1), l, ans + l[((int)ch) - 1]);

    if(num.length() > 1) {
        int s;
        if(num[0] == '0')
            return;
        else
            s = stoi(num.substr(0, 2));
        if(s > 27) {
            return;
        }
        else
            encode(num.substr(2), l, ans + l[s - 1]);
    }

}

int main() {

    string num = "10234";
    char l[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                'u', 'v', 'w', 'x', 'y', 'z'};

    encode(num, l, "");

    return 0;
}