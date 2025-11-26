#include <iostream>
#include <climits>
using namespace std;

// Structure of Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to check BST using range method
bool isBSTUtil(Node* root, int min, int max) {
    if (root == NULL)
        return true;

    if (root->data <= min || root->data >= max)
        return false;

    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

// Wrapper function
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
  
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(8);

    if (isBST(root))
        cout << "The given Binary Tree is a BST.";
    else
        cout << "The given Binary Tree is NOT a BST.";

    return 0;
}
