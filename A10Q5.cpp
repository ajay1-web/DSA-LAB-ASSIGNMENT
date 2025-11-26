#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool detectLoop(Node* head) {
    unordered_set<Node*> visited;

    while(head != NULL) {
        // If node already exists in set, loop detected
        if(visited.find(head) != visited.end())
            return true;

        visited.insert(head);
        head = head->next;
    }
    return false;
}

int main() {
    // Creating nodes
    Node* head = new Node{1, nullptr};
    Node* second = new Node{2, nullptr};
    Node* third = new Node{3, nullptr};
    Node* fourth = new Node{4, nullptr};

    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating loop: 4 -> 2
    fourth->next = second;

    if(detectLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
