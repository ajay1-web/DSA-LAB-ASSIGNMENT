#include <iostream>
using namespace std;

// Represents a single link in the list
struct LinkNode {
    int value;
    LinkNode* nextNode;
    LinkNode(int v): value(v), nextNode(nullptr) {}
};

// Manages the chain of linked nodes
class ChainList {
    LinkNode* first;
public:
    ChainList() { first = nullptr; }

    // Adds a new item to the end of the list
    void add(int item) {
        LinkNode* newLink = new LinkNode(item);
        if (!first) {
            first = newLink;
            return;
        }
        LinkNode* crawler = first;
        while (crawler->nextNode) {
            crawler = crawler->nextNode;
        }
        crawler->nextNode = newLink;
    }

    // Finds the value of the middle element using the fast/slow pointer method
    int getMidpointValue() {
        if (!first) {
            return -1; // Return -1 if the list is empty
        }

        LinkNode* p1 = first; // The "slow" pointer
        LinkNode* p2 = first; // The "fast" pointer

        while (p2 != nullptr && p2->nextNode != nullptr) {
            p1 = p1->nextNode;
            p2 = p2->nextNode->nextNode;
        }
        return p1->value;
    }
};

int main() {
    ChainList myChain;
    int sourceData[] = {1, 2, 3, 4, 5};
    for (int num : sourceData) {
        myChain.add(num);
    }

    cout << "The middle element is: " << myChain.getMidpointValue() << "\n";

    // Example with an even number of elements
    ChainList evenChain;
    int evenData[] = {10, 20, 30, 40, 50, 60};
    for (int num : evenData) {
        evenChain.add(num);
    }
    cout << "The middle element of the second list is: " << evenChain.getMidpointValue() << "\n";
    
    return 0;
}