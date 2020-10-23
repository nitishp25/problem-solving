#include <iostream>

using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;
    int height;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int get_height(node* n) {
    if(n == NULL)
        return 0;
    return n->height;
}

int get_balance(node* n) {
    if(n == NULL)
        return 0;
    return get_height(n->left) - get_height(n->right);
}

node* rightRotate(node* root) {
    node* left = root->left;
    node* child = left->right;
    left->right = root;
    root->left = child;

    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    left->height = max(get_height(left->left), get_height(left->right)) + 1;
    return left;
}

node* leftRotate(node* root) {
    node* right = root->right;
    node* child = right->left;
    right->left = root;
    root->right = child;

    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    right->height = max(get_height(right->left), get_height(right->right)) + 1;
    return right;    
}

node* insert(node* root, int key) {
    if(root == NULL) {
        node* new_node = new node(key);
        return new_node;
    }
    if(root->data < key)
        root->right = insert(root->right, key);
    else
        root->left = insert(root->left, key);
    
    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    int balance = get_balance(root);

    if(balance > 1 && key < root->left->data)
        return rightRotate(root);
    if(balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && key > root->right->data)
        return leftRotate(root);
    if(balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

node* max_value(node* root) {
    if(root == NULL)
        return NULL;
    if(root->right == NULL)
        return root;
    return max_value(root->right);
}

node* remove(node* root, int key) {
    if(root == NULL)
        return NULL;
    if(key < root->data)
        root->left = remove(root->left, key);
    else if(key > root->data)
        root->right = remove(root->right, key);
    else {
        if(root->left == NULL && root->right == NULL)
            return NULL;
        else if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;
        else {
            int _max = max_value(root->left)->data;
            root->data = _max;
            root->left = remove(root->left, _max);
            return root;
        }
    }

    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    int balance = get_balance(root);

    if(balance > 1 && get_balance(root->left) >= 0)
        return rightRotate(root);
    if(balance > 1 && get_balance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && get_balance(root->right) <= 0)
        return leftRotate(root);
    if(balance < -1 && get_balance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void display(node* root) {
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}

int main() {

    node* root = NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    display(root);
    cout<<"\n";

    root = remove(root, 10);

    display(root);
    cout<<"\n";

    return 0;
}