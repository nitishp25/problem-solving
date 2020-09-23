#include <iostream>

using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

        node() {
            left = NULL;
            right = NULL;
        }

        node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

node* create(int arr[], int si, int ei) {

    if(si > ei)
        return NULL;

    int mid = (si+ei)/2;
    node* root = new node(arr[mid]);
    root->left = create(arr, si, mid-1);
    root->right = create(arr, mid+1, ei);
    return root;
}

node* find_max(node* root) {

    if(root == NULL)
        return NULL;
    if(root->right == NULL)
        return root;
    return find_max(root->right);
}

node* find_min(node* root) {

    if(root == NULL)
        return NULL;
    if(root->left == NULL)
        return root;
    return find_min(root->left);
}

node* search(node* root, int val) {

    if(root == NULL)
        return NULL;
    if(root->data == val)
        return root;   
    if(root->data < val)
        return search(root->right, val);
    else
        return search(root->left, val);
}

void display(node* root) {

    if(root == NULL)
        return;
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    node* root = create(arr, 0, 6);
    cout<<find_max(root)->data<<endl;
    cout<<find_min(root)->data<<endl;
    cout<<search(root, 3)->data<<endl;
    // cout<<search(root, 9)->data<<endl;
    return 0;
}