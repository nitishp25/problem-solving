#include <iostream>
#include <unordered_map>

using namespace std;

class node {
public:
    unordered_map<char, node*> children;
    bool eow;
    
    node() {
        children = unordered_map<char, node*>();
        eow = false;
    }
};

class Trie {
public:
    node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* curr = root;
        for(int i = 0; i < word.length(); i++) {
            if(curr->children.find(word[i]) == curr->children.end())
                curr->children[word[i]] = new node();
            curr = curr->children[word[i]];
        }
        curr->eow = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* curr = root;
        for(int i = 0; i < word.length(); i++) {
            if(curr->children.find(word[i]) == curr->children.end())
                return false;
            curr = curr->children[word[i]];
        }
        return curr->eow;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* curr = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(curr->children.find(prefix[i]) == curr->children.end())
                return false;
            curr = curr->children[prefix[i]];
        }
        return true;
    }
};