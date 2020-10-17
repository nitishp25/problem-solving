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

node* LCA(node* root, int n1, int n2) {
    vector<node*> path1 = root_to_node(root, n1);
    vector<node*> path2 = root_to_node(root, n2);
    if(path1.size() == 0 || path2.size() == 0)
        return NULL;
    int i = 0, j = 0;
    while(i < path1.size() && j < path2.size()) {
        if(path1[i]->data != path2[j]->data)
            return path1[i-1];
        i++;
        j++;
    }
    return path1[i-1];
}

void k_down(node* root, int k) {
    if(k == 0) {
        cout<<root->data<<"\n";
        return;
    }
    for(node* child : root->children)
        k_down(child, k-1);
}

void k_down_(node* root, node* prev, int k) {
    if(k == 0) {
        cout<<root->data<<"\n";
        return;
    }
    for(node* child : root->children) {
        if(child != prev)
            k_down_(child, prev, k-1);
    }
}

void k_away(node* root, node* target, int k) {
    vector<node*> path = root_to_node(root, target->data);
    reverse(path.begin(), path.end());
    node* prev = NULL;
    for(int i = 0; i < path.size(); i++) {
        if(k-i >= 0) {
            k_down_(path[i], prev, k-i);
            prev = path[i];
        }
    }
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
    cout<<search(root, 4)<<"\n";
    cout<<search(root, 6)<<"\n";
    vector<node*> path = root_to_node(root, 5);
    for(node* n : path)
        cout<<n->data<<" ";

    return 0;
}