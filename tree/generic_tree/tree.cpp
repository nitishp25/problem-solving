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

node* create_tree(vector<int> arr, int idx) {

    node* root = new node(arr[idx]);
    int i = idx+1;
    while(i < arr.size()) {
        root->children.push_back(create_tree(arr, idx+1));
        i++;
    }
    return root;
}

int max_value(node *root) {
    int _max = root->data;
    for(node* child : root->children)
        _max = max(_max, max_value(child));
    return _max;
}

int min_value(node *root) {
    int _min = root->data;
    for(node* child : root->children)
        _min = min(_min, min_value(child));
    return _min;
}

int size(node* root) {
    int s = 0;
    for(node* child : root->children)
        s += size(child);
    return s+1;
}

int height(node* root) {
    int h = 0;
    for(node* child : root->children)
        h = max(h, height(child));
    return h+1;
}

bool search(node* root, int val) {
    bool f = false;
    if(root->data == val)
        return true;
    for(node* child : root->children)
        f = f || search(child, val);
    return f;
}

vector<node*> root_to_node(node* root, int val) {
    if(root == NULL)
        return vector<node*>();
    if(root->data == val) {
        vector<node*> path;
        path.insert(path.begin(), root);
        return path;
    }
    for(node* child : root->children) {
        vector<node*> path = root_to_node(child, val);
        if(path.size() > 0) {
            path.insert(path.begin(), root);
            return path;
        }
    }
    return vector<node*>();
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
    node* root = create_tree(arr, 0);
    cout<<min_value(root)<<"\n";
    cout<<max_value(root)<<"\n";
    cout<<height(root)<<"\n";
    cout<<size(root)<<"\n";

    return 0;
}