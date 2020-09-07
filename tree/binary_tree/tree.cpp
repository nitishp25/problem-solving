#include <bits/stdc++.h>

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

vector<node*> root_to_node(node *root, int val) {

    if(root == NULL)
        return vector<node*>();

    if(root->data == val) {
        vector<node*> path;
        path.insert(path.begin(), root);
        return path;
    }

    vector<node*> left = root_to_node(root->left, val);
    if(left.size() != 0) {
        left.insert(left.begin(), root);
        return left;
    }

    vector<node*> right = root_to_node(root->right, val);
    if(right.size() != 0) {
        right.insert(right.begin(), root);
        return right;
    }

    return vector<node*>();
}

int LCA(node* root, int a, int b) {

    vector<node*> path1 = root_to_node(root, a);
    vector<node*> path2 = root_to_node(root, b);

    if(path1.size() == 0 || path2.size() == 0)
        return -1;

    int ans;

    for(int i = 0; i < path1.size() && i < path2.size(); i++) {
        if(path1[i] == path2[i])
            ans = path1[i]->data;
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

    if(root == NULL || k <= 0) {
        if(k == 0 && root != NULL)
            cout<<root->data<<" ";
        return;
    }

    if(root->left != prev)
        k_down(root->left, k-1);
    if(root->right != prev)
        k_down(root->right, k-1);
}

void k_away(node *root, node *target, int k) {

    vector<node*> path = root_to_node(root, target->data);
    reverse(path.begin(), path.end());
    node *prev = NULL;

    for(int i = 0; i <= k; i++) {
        k_down_(path[i], prev, k - i);
        prev = path[i];
    }
}

int diameter(node *root) {

    if(root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(max(ld, rd), lh + rh + 1);
}

int diameter2(node *root, int &dia) {

    if(root == NULL)
        return 0;

    int lh = diameter2(root->left, dia);
    int rh = diameter2(root->right, dia);

    dia = max(dia, lh + rh + 1);

    return max(lh, rh) + 1;
}

int leaftoleaf(node *root, int &max_sum) {

    if(root == NULL)
        return 0;

    int ls = leaftoleaf(root->left, max_sum);
    int rs = leaftoleaf(root->right, max_sum);

    max_sum = max(max_sum, ls + rs + root->data);

    return max(ls, rs) + root->data;
}

bool isPathSum(node *root, int sum) {

    if(root == NULL)
        return false;

    if(root->left == NULL && root->right == NULL) {
        if(sum - root->data == 0)
            return true;
        return false;
    }

    bool l = isPathSum(root->left, sum - root->data);
    bool r = isPathSum(root->right, sum - root->data);

    return false || l || r; 
}

vector<float> LevelAvg(node *root) {

    queue<node*> q;
    vector<float> ans;
    q.push(root);

    while(!q.empty()) {
        int s = q.size();
        int size = s;
        int sum = 0;
        while(size-- > 0) {
            node* top = q.front();
            q.pop();
            sum += top->data;
            if(top->left != NULL)
                q.push(top->left);
            if(top->right != NULL)
                q.push(top->right);
        }
        ans.push_back(sum/s);
    }
    return ans;
}

bool isCousin(node *root, int a, int b) {

    queue<node*> q;
    q.push(root);
    int l1 = 0, l2 = 0;
    int level = 1;

    while(!q.empty()) {
        int size = q.size();
        while(size-- > 0) {
            node* front = q.front();
            q.pop();

            if(front->data == a)
                l1 = level;
            if(front->data == b)
                l2 = level;
            if(front->left != NULL && front->right != NULL && ((front->left->data == a && front->right->data == b) || (front->left->data == b && front->right->data == a)))
                return false;
            if(front->left != NULL)
                q.push(front->left);
            if(front->right != NULL)
                q.push(front->right);
        }
        level++;
        if(l1 != 0 || l2 != 0)
            return l1 == l2;
    }
    return true;
}

void inorder(node *root) {

    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node *root) {

    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) {

    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void levelorder(node *root) {

    queue<node*> q;
    q.push(root);

    while(!q.empty()) {

        int s = q.size();
        while(s--) {

            node *front = q.front();
            q.pop();
            cout<<front->data<<" ";
            if(front->left != NULL)
                q.push(front->left);
            if(front->right != NULL)
                q.push(front->right);  
        }
        cout<<endl;
    }
}

void levelorderzigzag(node *root) {

    stack<node*> curr, next;
    int lefttoright = 1;
    curr.push(root);

    while(!curr.empty()) {

        node *top = curr.top();
        curr.pop();
        cout<<top->data<<" ";

        if(lefttoright == 1) {
            if(top->left != NULL)
                next.push(top->left);
            if(top->right != NULL)
                next.push(top->right);
        }
        else {
            if(top->right != NULL)
                next.push(top->right);
            if(top->left != NULL)
                next.push(top->left);
        }
        if(curr.empty()) {
            cout<<endl;
            stack<node*> temp = curr;
            curr = next;
            next = temp;
            lefttoright = lefttoright == 1 ? 0 : 1;
        }
    }
}

void Floor(node *root, int n, int &floor) {

    if(root == NULL)
        return;

    if(root->data < n)
        floor = max(floor, root->data);

    Floor(root->left, n, floor);
    Floor(root->right, n, floor);
}

void Ciel(node *root, int n, int &ciel) {

    if(root == NULL)
        return;

    if(root->data > n)
        ciel = min(ciel, root->data);

    Ciel(root->left, n, ciel);
    Ciel(root->right, n, ciel);
}

int kth_largest(node *root, int k) {

    int n = INT8_MAX, floor;

    for(int i = 0; i < k; i++) {
        floor = INT8_MIN;
        Floor(root, n, floor);
        n = floor;
    }
    return n;
}

void leaves(node *root, vector<int> &leaves_) {

    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
        leaves_.push_back(root->data);

    leaves(root->left, leaves_);
    leaves(root->right, leaves_);
}

bool leaf_similar(node *root1, node *root2) {

    vector<int> leaf1, leaf2;
    leaves(root1, leaf1);
    leaves(root2, leaf2);

    return leaf1 == leaf2;
}

bool isSameShape(node *root1, node *root2) {

    if(root1 == NULL && root2 == NULL)
        return true;
    if((root1 == NULL && root2 != NULL) || root1 != NULL && root2 == NULL)
        return false;

    return isSameShape(root1->left, root2->left) && isSameShape(root1->right, root2->right);
}

bool isMirrorShape(node *root1, node *root2) {

    if(root1 == NULL && root2 == NULL)
        return true;
    if((root1 == NULL && root2 != NULL) || root1 != NULL && root2 == NULL)
        return false;

    return isMirrorShape(root1->left, root2->right) && isMirrorShape(root1->right, root2->left);  

}

bool isSymmetric(node *root) {

    return isMirrorShape(root, root);

}

node* mirrorTree(node *root) {

    if(root == NULL)
        return NULL;

    node *left = mirrorTree(root->left);
    node *right = mirrorTree(root->right);

    root->left = right;
    root->right = left;
    return root;
}

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
    int arr2[] = {7, 8, 9};
    node *root = create_2(arr, 5);
    // node *root2 = create_2(arr2, 3);

    node *root2 = mirrorTree(root);
    display(root2);

    return 0;
}