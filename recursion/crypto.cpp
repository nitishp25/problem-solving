#include <bits/stdc++.h>

using namespace std;

int decrypt(map<char, int> chars, vector<string> words) {

    vector<int> ans;
    ans.clear();

    for(int i = 0; i != words.size(); i++) {
        for(int j = 0; j != words[i].length(); j++) {
            words[i][j] = chars[words[i][j]];
        }
        ans.push_back(stoi(words[i]));
    }
    if(ans[0] + ans[1] == ans[2]) {
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
        return 1;
    }
    return 0;

}

int solve(map<char, int> chars, vector<string> words, map<char, int>::iterator it) {

    if(it == chars.end()) {
        if(decrypt(chars, words))
            return 1;
        return 0;
    }

    for(int i = 0; i < 10; i++) {
        it->second = i;
        if(solve(chars, words, ++it))
            return 1;
        --it;
    }
    return 0;
}

int main() {

    vector<string> words;
    words.push_back("send");
    words.push_back("more");
    words.push_back("money");
    map<char, int> chars;
    map<char, int>::iterator it;
    for(int i = 0; i != words.size(); i++) {
        for(int j = 0; j != words[i].length(); j++) {
            // chars[words[i][j]] = -1;
        }
    }
    it = chars.begin();
    solve(chars, words, it);

    return 0;
}