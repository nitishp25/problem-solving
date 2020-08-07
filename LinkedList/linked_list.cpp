#include <iostream>

using namespace std;

class node {
    public:
        int val;
        node *next = NULL;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    node *head;
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        node *curr = head;
        while(curr != NULL) {
            if(index == 0) {
                return curr->val;
            }
            index--;
            curr = curr->next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node *new_node = new node();
        new_node->val = val;
        new_node->next = head;
        head = new_node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *new_node = new node();
        new_node->val = val;
        if(head == NULL) {
            head = new_node;
            return;
        }
        if(head->next == NULL) {
            head->next = new_node;
        }
        else {
            node *curr = head;
            while(curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new_node;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        node *new_node = new node();
        new_node->val = val;
        node *prev = head;
        if(index == 0) {
            if(head == NULL) {
                head = new_node;
            }
            else {
                new_node->next = head;
                head = new_node;
            }
        }
        else {
            while(prev != NULL) {
                if(index == 1) {
                    new_node->next = prev->next;
                    prev->next = new_node;
                    return;
                }
                prev = prev->next;
                index--;
            }
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        node *prev = head;
        node *curr = head->next;
        if(index == 0) {
            head = head->next;
            delete prev;
        }
        else {
            while(curr != NULL) {
                if(index == 1) {
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
                prev = prev->next;
                curr = curr->next;
                index--;
            }
        }
    }
};

int main() {

    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    cout<<obj->get(0)<<endl;
    cout<<obj->get(1)<<endl;
    obj->deleteAtIndex(0);
    cout<<obj->get(0)<<endl;

    return 0;
}