#include <iostream>

using namespace std;

class Queue {
    public:
    int arr[10], size, front, rear;
    Queue() {
        size = 0;
        front = 0;
        rear = -1;
    }

    void push(int val) {
        if(size == 10) {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        rear = (rear+1)%10;
        arr[rear] = val;
        size++;
    }

    void pop() {
        if(size == 0) {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        cout<<"Popped: "<<arr[front]<<endl;
        front = (front+1)%10;
        size--;
    }

    void print() {
        for(int i = 0; i < size; i++)
            cout<<arr[(front+i)%10]<<" ";
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
    q.push(11);
    q.push(12);
    q.print();
    q.push(13);

    return 0;
}