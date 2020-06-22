#include <bits/stdc++.h>

using namespace std;

int decrypt(map<char, int> chars, vector<string> words) {

    vector<int> ans;
    ans.clear();
    cout<<"Decrypt"<<endl;

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

int solve(map<char, int> chars, vector<string> words, map<char, int>::iterator it, vector<bool> &istaken) {

    if(it == chars.end()) {
        if(decrypt(chars, words))
            return 1;
        return 0;
    }
    cout<<"Solving"<<endl;

    for(int i = 0; i < 10; i++) {
        if(!istaken[i]) {
            it->second = i;
            istaken[i] = 1;
            if(solve(chars, words, ++it, istaken))
                return 1;
            --it;
            istaken[i] = 0;
        }
    }
    return 0;
}

int main() {

    vector<string> words;
    vector<bool> istaken;
    words.push_back("send");
    words.push_back("more");
    words.push_back("money");
    set<char> s;
    map<char, int> chars;
    map<char, int>::iterator it;
    for(int i = 0; i < 10; i++)
        istaken.push_back(0);
    cout<<"Entering elements"<<endl;
    for(int i = 0; i != words.size(); i++) {
        for(int j = 0; j != words[i].length(); j++) {
            if(s.find(words[i][j]) == s.end()) {
                s.insert(words[i][j]);
                chars.insert({words[i][j], -1});
            }
        }
    }
    cout<<"Elements entered"<<endl;
    it = chars.begin();
    cout<<chars.size()<<endl;
    solve(chars, words, it, istaken);

    return 0;
}