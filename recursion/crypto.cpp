#include <bits/stdc++.h>

using namespace std;

void solve(map<char, int> chars, vector<string> words, map<char, int>::iterator it) {

    for(int i = 0; i < 10; i++) {
        it->second = i;
        // TODO
    }

}

int main() {

    vector<string> words = {"send", "more", "money"};
    map<char, int> chars;
    map<char, int>::iterator it;
    for(int i = 0; i < words.size(); i++) {
        for(int j = 0; j < words[i].length(); j++) {
            chars[words[i][j]] = -1;
        }
    }
    it = chars.begin();
    solve(chars, words, it);

    return 0;
}