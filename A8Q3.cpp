#include <iostream>
using namespace std;

// BST Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// INSERT (No duplicates allowed)
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        cout << "Duplicate value not allowed: " << key << endl;

    return root;
}

// Find minimum value node (used in delete)
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// DELETE a node
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// MAXIMUM DEPTH (Height)
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// MINIMUM DEPTH
int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->left == NULL)
        return 1 + minDepth(root->right);

    if (root->right == NULL)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Inorder Traversal (to display BST)
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // Insert Elements
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "BST Inorder Traversal: ";
    inorder(root);

    // Delete element
    cout << "\n\nDeleting 20...\n";
    root = deleteNode(root, 20);

    cout << "BST after deletion: ";
    inorder(root);

    // Max & Min Depth
    cout << "\n\nMaximum Depth of BST: " << maxDepth(root);
    cout << "\nMinimum Depth of BST: " << minDepth(root);

    return 0;
}
