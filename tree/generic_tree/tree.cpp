#include <bits/stdc++.h>

using namespace std;

class node {
    public:
    int data;
    vector<node*> children;

    node(int val) {
        data = val;
    }
};

int idx = 0;

node* create_tree(vector<int> arr) {

    if(idx >= arr.size()) {
        return NULL;
    }
    node* root = new node(arr[idx]);
    idx++;
    while(idx < arr.size()) {
        root->children.push_back(create_tree(arr));
    }
    idx++;
    return root;
}

void display(node* root) {
    if(root == NULL)
        return;
    cout<<root->data;
    cout<<"->";
    for(node* child : root->children) {
        if(child != NULL)
            cout<<child->data<<" ";
    }
    cout<<"\n";
    for(node* child : root->children) {
        if(child != NULL)
            display(child);
    }
}

int main() {

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    node* root = create_tree(arr);
    display(root);

    return 0;
}