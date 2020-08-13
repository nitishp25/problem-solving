#include <iostream>
#include <stack>

using namespace std;

class node {
    public:
        int val;
        node *next = NULL;

        node() {
            this->val = 0;
            this->next = NULL;
        }

        node(int val, node* next) {
            this->val = val;
            this->next = next;
        }
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

    bool isPalindrome() {
        node *curr = head;
        if(head == NULL)
            return true;
        stack<int> s;
        while(curr != NULL) {
            s.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr != NULL) {
            if(s.top() == curr->val) {
                s.pop();
                curr = curr->next;
            }
            else
                return false;
        }
        return true;
    }

    node* find_middle(node* head) {
        node* slow = head;
        node* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL && fast->next == NULL)
            slow = slow->next;
        return slow;
    }

    node* reverse(node* head) {
        node *prev = NULL;
        node *curr = head;
        node *next = curr->next;
        while(curr != NULL) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next != NULL)
                next = next->next;
        }
        return prev;
    }

    bool isPalindrome_2() {
        if(head == NULL || head->next == NULL)
            return true;
        node *curr = head;
        node *middle = find_middle(head);
        middle = reverse(middle);
        while(middle != NULL) {
            if(curr->val != middle->val)
                return false;
            curr = curr->next;
            middle = middle->next;
        }
        return true;
    }

    node* oddEvenList() {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        node *odd = head;
        node *start = head->next;
        node *eve = head->next;
        while(eve != NULL && eve->next != NULL) {
            odd->next = odd->next->next;
            eve->next = eve->next->next;
            odd = odd->next;
            eve = eve->next;
        }
        odd->next = start;
        return head;
    }

    node* removeElements(int val) {
        node *curr = head;
        node *prev = new node(-1, head);
        while(curr != NULL) {
            if(curr->val == val) {
                if(curr == head)
                    head = head->next;
                node *temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            }
            else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }

    node* removeNthFromEnd(int n) {
        node *curr = head;
        int len = 0;
        while(curr != NULL) {
            len++;
            curr = curr->next;
        }
        len -= n;
        node *prev = new node(-1, head);
        curr = head;
        while(curr != NULL) {
            if(len == 0) {
                if(curr == head)
                    head = head->next;
                prev->next = curr->next;
                delete curr;
                break;
            }
            prev = prev->next;
            curr = curr->next;
            len--;
        }
        return head;
    }

    node *getIntersectionNode(node *headA, node *headB) {
        node *tempA = headA;
        node *tempB = headB;
        int sizeA = 0, sizeB = 0, diff;
        while(tempA != NULL) {
            sizeA += 1;
            tempA = tempA->next;
        }
        while(tempB != NULL) {
            sizeB += 1;
            tempB = tempB->next;
        }
        diff = abs(sizeA - sizeB);
        tempA = headA;
        tempB = headB;
        if(sizeA > sizeB) {
            while(tempA != NULL && diff > 0) {
                tempA = tempA->next;
                diff--;
            }
        }
        else {
            while(tempB != NULL && diff > 0) {
                tempB = tempB->next;
                diff--;
            }
        }
        while(tempA != NULL && tempB != NULL) {
            if(tempA == tempB) {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }

    node *detectCycle_2() {
        node *slow = head;
        node *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    bool hasCycle() {
        
        node *slow = head;
        node *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
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