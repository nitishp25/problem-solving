#include <iostream>

using namespace std;

class stack {
    public:
    int top;
    int arr[10];

    stack() {
        top = -1;
    }

    void push(int val) {
        if(top == 9) {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top] = val;
    }

    void pop() {
        if(top == -1) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<"Popped: "<<arr[top--]<<endl;
    }

    void peek() {
        if(top == -1) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<"Top = "<<arr[top]<<endl;
    }

    void print() {
        if(top == -1) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        int i = top;
        cout<<"Stack is: "<<endl;
        while(i >= 0)
            cout<<arr[i--]<<endl;
    }
};

int main() {

    stack s;

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