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

class Queue {
    public:
    node *front, *rear;
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void push(int val) {
        node* new_node = new node(val);
        if(rear == NULL) {
            rear = new_node;
            front = new_node;
        }
        else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void pop() {
        if(front == NULL) {
            cout<<"Queue underflow"<<endl;
            return;
        }
        else {
            node *temp = front;
            cout<<"Popped: "<<temp->val<<endl;
            front = front->next;
            delete temp;
            if(front == NULL)
                rear = NULL;
        }
    }

    void print() {
        node *curr = front;
        while(curr != NULL) {
            cout<<curr->val<<" ";
            curr = curr->next;
        }
        cout<<endl;
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
    q.push(12);
    q.print();
    q.push(13);

    return 0;
}