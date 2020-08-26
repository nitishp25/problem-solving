#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class node {

    public:
    int data, state;
    node *left, *right;

    node() {
        left = NULL;
        right = NULL;
    }

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    node(int val, int state) {
        data = val;
        this->state = state;
        left = NULL;
        right = NULL;
    }
};

class tree {

    public:
    node *root;

    tree() {
        root = NULL;
    }

    tree(node *root) {
        this->root = root;
    }
};

node* create(int arr[], int n, int idx) {

    if(idx == n)
        return NULL;

    node *root = new node(arr[idx]);

    root->left = create(arr, n, idx+1);
    root->right = create(arr, n, idx+1);

    return root;
}

node* create_2(int arr[], int n) {

    int idx = 0;
    stack<node*> s;
    node *root = new node(arr[idx], 0);
    s.push(root);

    while(!s.empty()) {

        node *top = s.top();

        if(top->state == 0) {
            if(idx + 1 == n) {
                top->left = NULL;
                top->state++;
            }
            else {
                top->left = new node(arr[idx+1], 0);
                top->state++;
                s.push(top->left);
                idx++;
            }
        }
        else if(top->state == 1) {
            if(idx + 1 == n) {
                top->right = NULL;
                top->state++;
            }
            else {
                top->right = new node(arr[idx+1], 0);
                top->state++;
                s.push(top->right);
                idx++;
            }
        }
        else {
            s.pop();
            idx--;
        }
    }
    return root;
}

int min_value(node *root) {

    if(root == NULL)
        return INT8_MAX;

    int min1 = min_value(root->left);
    int min2 = min_value(root->right);

    return min(min(min1, min2), root->data);
}

int max_value(node *root) {

    if(root == NULL)
        return INT8_MIN;

    int max1 = max_value(root->left);
    int max2 = max_value(root->right);

    return max(max(max1, max2), root->data);
}

int size(node *root) {

    if(root == NULL)
        return 0;

    return size(root->left) + size(root->right) + 1;
}

int height(node *root) {

    if(root == NULL)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

bool find(node *root, int val) {

    if(root == NULL)
        return false;

    return (root->data == val) || find(root->left, val) || find(root->right, val);

}

vector<int> root_to_node(node *root, int val) {

    if(root == NULL)
        return vector<int>();

    if(root->data == val) {
        vector<int> path;
        path.insert(path.begin(), val);
        return path;
    }

    vector<int> left = root_to_node(root->left, val);
    if(left.size() != 0) {
        left.insert(left.begin(), root->data);
        return left;
    }

    vector<int> right = root_to_node(root->right, val);
    if(right.size() != 0) {
        right.insert(left.begin(), root->data);
        return right;
    }

    return vector<int>();
}

int LCA(node* root, int a, int b) {

    vector<int> path1 = root_to_node(root, a);
    vector<int> path2 = root_to_node(root, b);

    if(path1.size() == 0 || path2.size() == 0)
        return -1;

    int ans;

    for(int i = 0; i < path1.size() && i < path2.size(); i++) {
        if(path1[i] == path2[i])
            ans = path1[i];
        else
            break;
    }
    return ans;
}

void k_down(node *root, int k) {

    if(root == NULL || k == 0) {
        if(k == 0 && root != NULL)
            cout<<root->data<<" ";
        return;
    }

    k_down(root->left, k-1);
    k_down(root->right, k-1);
}

void k_down_(node *root, node *prev, int k) {

    if(root == NULL || k == 0) {
        if(k == 0 && root != NULL)
            cout<<root->data<<" ";
        return;
    }

    if(root->left != prev)
        k_down(root->left, k-1);
    if(root->right != prev)
        k_down(root->right, k-1);
}

/*
void k_away(node *root, node *target, int k) {

    vector<int> path = root_to_node(root, target->data);


}
*/

void display(node* root) {

    if(root == NULL)
        return;

    cout<<(root->left == NULL ? -1 : root->left->data)<<" ";
    cout<<root->data<<" ";
    cout<<(root->right == NULL ? -1 : root->right->data)<<endl;
    display(root->left);
    display(root->right);
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    node *root = create_2(arr, 5);

    k_down(root, 3);

    return 0;
}