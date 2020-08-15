#include <iostream>

using namespace std;

class node {
    public:
    int val;
    node* next;

    node() {
        next = NULL;
    }
    node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Stack {
    public:
    node* top;

    Stack() {
        top = NULL;
    }

    void push(int val) {
        node* new_node = new node(val);
        new_node->next = top;
        top = new_node;
    }

    void pop() {
        if(top == NULL) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        node* temp = top;
        cout<<"Popped: "<<top->val<<endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if(top == NULL) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<"Top = "<<top->val<<endl;
    }

    void print() {
        if(top == NULL) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<"Stack is:"<<endl;
        node* curr = top;
        while(curr != NULL) {
            cout<<curr->val<<endl;
            curr = curr->next;
        }
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