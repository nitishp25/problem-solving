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

node* add(node *root, int val) {

    if(root == NULL) {
        node* new_node = new node(val);
        return new_node;
    }
    if(val > root->data)
        root->right = add(root->right, val);
    else
        root->left = add(root->left, val);
    return root;
}

node* remove_node(node* root, int val) {

    if(root == NULL)
        return NULL;
    if(root->data == val) {
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;
        root->data = find_min(root->right)->data;
        root->right = remove_node(root->right, root->data);
    }
    else if(val > root->data)
        root->right = remove_node(root->right, val);
    else
        root->left = remove_node(root->left, val);
    return root;
}

int ceil(node *root, int val) {

    if(root == NULL)
        return -1;
    if(root->data == val)
        return root->data;
    if(root->data < val) {
        return ceil(root->right, val);
    }
    int c = ceil(root->left, val);
    if(c < val)
        c = root->data;
    return c;
}

int floor(node *root, int val) {

    if(root == NULL)
        return -1;
    if(root->data == val)
        return root->data;
    if(root->data > val) {
        return floor(root->left, val);
    }
    int f = floor(root->right, val);
    if(f > val)
        f = root->data;
    return f;
}

bool isBST(node *root, int min_, int max_) {

    if(root == NULL)
        return true;
    if(root->data <= min_ || root->data >= max_)
        return false;
    return isBST(root->left, min_, root->data) && isBST(root->right, root->data, max_);
}

node* LCA(node* root, int root1, int root2) {
    if(root == NULL)
        return NULL;

    if(root->data > root1 && root->data > root2)
        return LCA(root->left, root1, root2);
    if(root->data < root1 && root->data < root2)
        return LCA(root->right, root1, root2);
    return root;
}

node* head = NULL;
node* tail = NULL;

void flatten(node* root) {

    if(root == NULL)
        return;
    flatten(root->left);
    if(head == NULL) {
        head = root;
        tail = root;
        root->left = NULL;
    }
    else {
        tail->right = root;
        root->left = NULL;
        tail = root;
    }
    flatten(root->right);
}

node* flatten_2(node* root) {

    if(root == NULL)
        return NULL;
    node *left = flatten_2(root->left);
    node* curr = left;
    if(curr != NULL) {
        while(curr->right != NULL) {
            curr = curr->right;
        }
        curr->right = root;
        root->left = NULL;
        root->right = flatten_2(root->right);
        return left;
    }
    else {
        root->right = flatten_2(root->right);
        return root;
    }
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
    node* new_node = flatten_2(root);
    display(new_node);
    return 0;
}