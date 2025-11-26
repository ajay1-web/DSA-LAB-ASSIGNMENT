#include <iostream>
using namespace std;

// BST Node Structure
struct Node {
    int data;
    Node *left, *right, *parent;

    Node(int val) {
        data = val;
        left = right = parent = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data) {
        Node* leftChild = insert(root->left, key);
        root->left = leftChild;
        leftChild->parent = root;
    }
    else if (key > root->data) {
        Node* rightChild = insert(root->right, key);
        root->right = rightChild;
        rightChild->parent = root;
    }
    return root;
}

//  Recursive Search
Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

//  Non-Recursive Search
Node* searchIterative(Node* root, int key) {
    while (root != NULL && root->data != key) {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

//  Minimum Element
Node* minimum(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

//  Maximum Element
Node* maximum(Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

// In-order Successor
Node* inorderSuccessor(Node* node) {
    if (node->right != NULL)
        return minimum(node->right);

    Node* parent = node->parent;
    while (parent != NULL && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

//  In-order Predecessor
Node* inorderPredecessor(Node* node) {
    if (node->left != NULL)
        return maximum(node->left);

    Node* parent = node->parent;
    while (parent != NULL && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

// Inorder traversal (for display)
void inorderDisplay(Node* root) {
    if (root == NULL) return;
    inorderDisplay(root->left);
    cout << root->data << " ";
    inorderDisplay(root->right);
}

int main() {
    Node* root = NULL;

    // Creating BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "BST Inorder Traversal: ";
    inorderDisplay(root);

    int key = 40;

    // Search Recursive
    cout << "\n\nSearching (Recursive) for " << key << ": ";
    Node* res1 = searchRecursive(root, key);
    cout << (res1 ? "Found" : "Not Found");

    // Search Non-Recursive
    cout << "\nSearching (Non-Recursive) for " << key << ": ";
    Node* res2 = searchIterative(root, key);
    cout << (res2 ? "Found" : "Not Found");

    // Minimum & Maximum
    cout << "\nMinimum Element: " << minimum(root)->data;
    cout << "\nMaximum Element: " << maximum(root)->data;

    // Successor & Predecessor
    Node* node = searchRecursive(root, key);

    Node* succ = inorderSuccessor(node);
    Node* pred = inorderPredecessor(node);

    cout << "\nInorder Successor of " << key << ": ";
    cout << (succ ? to_string(succ->data) : "None");

    cout << "\nInorder Predecessor of " << key << ": ";
    cout << (pred ? to_string(pred->data) : "None");

    return 0;
}
