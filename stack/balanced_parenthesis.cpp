#include <iostream>
#include <stack>

using namespace std;

bool solve(string str) {
    stack<char> s;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(')
            s.push(str[i]);
        else {
            if(!s.empty() && s.top() == '(')
                s.pop();
            else
                return false;
        }
    }
    if(s.empty())
        return true;
    return false;
}

int main() {

    string s1 = "(((())))", s2 = "())", s3 = "()()";

    cout<<solve(s1)<<endl;
    cout<<solve(s2)<<endl;
    cout<<solve(s3)<<endl;

    return 0;
}