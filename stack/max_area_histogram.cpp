#include <iostream>
#include <stack>

using namespace std;

int solve(int hist[], int n) {

    stack<int> s;
    int i = 0, top, area, max_area = 0;
    while(i < n) {

        if(s.empty() || hist[i] >= hist[s.top()])
            s.push(i++);
        else {
            top = s.top();
            s.pop();
            area = hist[top] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(area, max_area);
        }
    }
    while(!s.empty()) {
        top = s.top();
        s.pop();
        area = hist[top] * (s.empty() ? i : i - s.top() - 1);
        max_area = max(area, max_area);
    }
    return max_area;
}

int main() {

    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = 7;
    cout<<solve(hist, n)<<endl;

    return 0;
}