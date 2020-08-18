#include <iostream>
#include <queue>

using namespace std;

class Stack {
    public:
    queue<int> q1, q2;
    int top, size;

    Stack() {
        top = -1;
        size = 0;
    }

    void push(int val) {
        q2.push(val);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        top = q2.front();
        size++;
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop() {
        if(q1.empty())
            return;
        q1.pop();
        top = q1.front();
        size--;
    }

    void peek() {
        if(q1.empty())
            cout<<"-1"<<endl;
        else
            cout<<q1.front()<<endl;;
    }

    void print() {
        int i = size;
        while(i != 0) {
            cout<<q1.front()<<" ";
            q2.push(q1.front());
            q1.pop();
            i--;
        }
        cout<<endl;
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
};

class Stack_2 {
    public:
    queue<int> q1, q2;
    int top, size;

    Stack_2() {
        top = -1;
        size = 0;
    }

    void push(int val) {
        q1.push(val);
        top = q1.back();
        size++;
    }

    void pop() {
        if(q1.empty())
            cout<<"-1"<<endl;
        else {
            while(q1.size() != 1) {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            queue<int> q = q1;
            q1 = q2;
            q2 = q;
            size--;
        }
        top = q1.back();
    }

    void peek() {
        if(q1.empty())
            cout<<"-1"<<endl;
        else
            cout<<q1.back()<<endl;;
    }

};

int main() {

    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    s.pop();
    s.pop();
    s.print();
    s.peek();

    return 0;
}