#include <iostream>
#include <string>
#include <cassert>

using namespace std;

struct BST_Node {
    string key;
    // we'll ignore otherStuff
    string otherStuff;
    BST_Node* left;
    BST_Node* right;
};
typedef BST_Node* BST;

void BST_init (BST& root) {
    root = nullptr;
}

bool BST_isEmpty(const BST& root){
    return nullptr == root;
}

bool BST_has(const BST& root, string key) {
    if (BST_isEmpty (root)) { // nullptr == ROOT
        return false;
    } else if (key == root->key) {
        return true;
    } else if (key < root->key) {
        return BST_has (root->left, key);
    } else {
        return BST_has (root->right, key);
    }
}

string BST_lookup(const BST& root, string key) {
    if (BST_isEmpty(root)) { // nullptr == ROOT
        return "";
    } else if (key == root->key) {
        return root->otherStuff;
    } else if (key < root->key) {
        return BST_lookup(root->left, key);
    } else {
        return BST_lookup(root->right, key);
    }
}

void BST_insert (BST& root, string key) {
    if (BST_isEmpty(root)) {
        root = new BST_Node {};
        root->key = key;
        root->left = nullptr; // or BST_init(root->left)
        root->right = nullptr; // or BST_init(root->right)
    } else if (key < root->key) {
        BST_insert(root->left, key);
    } else {
        BST_insert(root->right, key);
    }
}

void BST_print (const BST& root) {
    if (!BST_isEmpty (root)) {
        BST_print (root->left);
        cout << root->key << endl;
        BST_print (root->right);
    }
}

