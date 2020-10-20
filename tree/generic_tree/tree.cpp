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

int diameter(node* root) {
    int h1 = 0, h2 = 0;
    for(node* child : root->children) {
        int h = height(child);
        if(h > h1) {
            h2 = h1;
            h1 = h;
        }
        else if(h > h2)
            h2 = h;
    }
    int d = 0;
    for(node* child : root->children)
        d = max(d, diameter(child));
    d = max(d, h1 + h2 + 1);
}

int dia = 0;

int _diameter(node* root) {
    int h1 = 0, h2 = 0;
    for(node* child : root->children) {
        int h = _diameter(child);
        if(h > h1) {
            h2 = h1;
            h1 = h;
        }
        else if(h > h2)
            h2 = h;
    }
    dia = max(dia, h1 + h2 + 1);
    return max(h1, h2) + 1;
}

int leaves(node* root) {
    int l = 0;
    /* for(node* child : root->children) {
        if(child->children.size() == 0)
            l++;
    } */
    if(root->children.size() == 0)
        return 1;
    for(node* child : root->children) {
        l += leaves(child);
    }
    return l;
}

int f = INT_MIN;

void floor(node* root, int val) {
    if(root->data < val && root->data > f)
        f = root->data;
    for(node* child : root->children)
        floor(child, val);
}

int kth_largest(node* root, int k) {
    int ans = INT_MAX;
    for(int i = 0; i < k; i++) {
        floor(root, ans);
        ans = f;
        f = INT_MIN;
    }
    return ans;
}

void levelorder(node* root) {
    queue<node*> que;
    que.push(root);
    while(que.size() != 0) {
        node* n = que.front();
        que.pop();
        cout<<n->data<<" ";
        for(node* child : n->children)
            que.push(child);
    }
}

void levelorder_newline(node* root) {
    queue<node*> que;
    que.push(root);
    int size;
    while(que.size() != 0) {
        size = que.size();
        while(size--) {
            node* n = que.front();
            que.pop();
            cout<<n->data<<" ";
            for(node* child : n->children)
                que.push(child);
        }
        cout<<"\n";
    }
}

void levelorder_zigzag(node* root) {
    stack<node*> s1;
    stack<node*> s2;
    bool l = true;
    s1.push(root);
    while(!s1.empty()) {
        node* n = s1.top();
        s1.pop();
        cout<<n->data<<" ";
        if(l) 
            for(node* child:n->children)
                s2.push(child);
        else
            for(int i = n->children.size()-1; i>=0; i--)
                s2.push(n->children[i]);
        if(s1.empty()) {
            cout<<"\n";
            l = !l;
            stack<node*> t = s1;
            s1 = s2;
            s2 = t;
        }
    }
}

bool isSameShape(node* root1, node* root2) {
    if(root1->children.size() != root2->children.size())
        return false;
    bool ans = true;
    for(int i = 0; i < root1->children.size(); i++)
        ans = ans && isSameShape(root1->children[i], root2->children[i]);
    return ans;
}

bool isMirrorShape(node* root1, node* root2) {
    if(root1->children.size() != root2->children.size())
        return false;
    bool ans = true;
    int i = 0, j = root1->children.size() - 1;
    while(i < root1->children.size() - 1 && j >= 0) {
        ans = ans && isMirrorShape(root1->children[i], root2->children[j]);
        i++;
        j--;
    }
    return ans;
}

bool isSymmetric(node* root1, node* root2) {
    return isMirrorShape(root1, root2);
}

bool isSymmetricWithValue(node* root1, node* root2) {
    if(root1->children.size() != root2->children.size() || root1->data != root2->data)
        return false;
    bool ans = true;
    int i = 0, j = root1->children.size() - 1;
    while(i < root1->children.size() - 1 && j >= 0) {
        ans = ans && isSymmetricWithValue(root1->children[i], root2->children[j]);
        i++;
        j--;
    }
    return ans;
}

void mirrorTree(node* root) {
    for(node* child : root->children)
        mirrorTree(child);
    reverse(root->children.begin(), root->children.end());
}

void remove_leaves(node* root) {
    for(int i = root->children.size() - 1; i >= 0; i--) {
        if(root->children[i]->children.size() == 0)
            root->children.resize(root->children.size() - 1);
    }
    for(node* child : root->children)
        remove_leaves(child);
}

void flatten(node* root) {
    for(node* child : root->children)
        flatten(child);
    int i = root->children.size() - 1;
    while(i > 0) {
        node* curr = root->children[i];
        node* tail = root->children[i-1];
        root->children.pop_back();
        while(tail->children.size() == 0) {
            tail = tail->children[0];
        }
        tail->children.push_back(curr);
        i--;
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
    flatten(root);
    display(root);

    return 0;
}