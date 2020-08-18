#include <iostream>
#include <stack>

using namespace std;

class Queue {
    public:
    stack<int> s1, s2;
    int front, rear, size;

    void push(int val) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        rear = val;
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        front = s1.top();
    }

    void pop() {
        if(s1.empty())
            cout<<"-1"<<endl;
        else {
            cout<<"Popped: "<<s1.top()<<endl;
            s1.pop();
        }
        front = s1.top();
    }

    void print() {
        while(!s1.empty()) {
            cout<<s1.top()<<" ";
            s2.push(s1.top());
            s1.pop();
        }
        cout<<endl;
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void peek() {
        cout<<rear<<endl;
    }

};

int main() {

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.print();
    q.push(11);
    q.print();
    q.pop();
    q.pop();
    q.push(11);
    q.push(12);
    q.print();
    q.push(13);

    return 0;
}