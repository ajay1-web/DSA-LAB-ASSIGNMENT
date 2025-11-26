#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool checkDuplicates(Node* root, unordered_set<int>& s) {
    if(root == NULL)
        return false;

    // If value already exists, duplicate found
    if(s.find(root->data) != s.end())
        return true;

    s.insert(root->data);

    return checkDuplicates(root->left, s) || checkDuplicates(root->right, s);
}

bool hasDuplicate(Node* root) {
    unordered_set<int> s;
    return checkDuplicates(root, s);
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(2); // Duplicate

    if (hasDuplicate(root))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
