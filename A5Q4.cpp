#include <iostream>
using namespace std;

// Represents a single link in the sequence
struct ChainLink {
    int payload;
    ChainLink* successor;
    ChainLink(int p): payload(p), successor(nullptr) {}
};

// Manages the sequence of linked elements
class Sequence {
    ChainLink* anchor;
public:
    Sequence() { anchor = nullptr; }

    // Adds a new item to the end of the sequence
    void push_back(int item) {
        ChainLink* newLink = new ChainLink(item);
        if (!anchor) {
            anchor = newLink;
            return;
        }
        ChainLink* iterator = anchor;
        while (iterator->successor) {
            iterator = iterator->successor;
        }
        iterator->successor = newLink;
    }

    // Inverts the order of the entire sequence
    void invert() {
        ChainLink* previousNode = nullptr;
        ChainLink* currentNode = anchor;
        ChainLink* nextNode = nullptr;

        while (currentNode) {
            // Store the next link before overwriting the pointer
            nextNode = currentNode->successor;
            // Reverse the pointer of the current link
            currentNode->successor = previousNode;
            // Move the pointers one position ahead
            previousNode = currentNode;
            currentNode = nextNode;
        }
        // The last 'previousNode' is the new start of the sequence
        anchor = previousNode;
    }

    // Displays the sequence
    void show() {
        ChainLink* iterator = anchor;
        while (iterator) {
            cout << iterator->payload;
            if (iterator->successor) {
                cout << " -> ";
            }
            iterator = iterator->successor;
        }
        cout << "\n";
    }
};

int main() {
    Sequence mySequence;
    int elements[] = {1, 2, 3, 4};
    for (int e : elements) {
        mySequence.push_back(e);
    }

    cout << "Original sequence: ";
    mySequence.show();

    cout << "Inverting the sequence...\n";
    mySequence.invert();

    cout << "Reversed sequence: ";
    mySequence.show();
    
    // A little something extra for the end of the day in Patiala!
    Sequence anotherSeq;
    anotherSeq.push_back(10);
    anotherSeq.push_back(20);
    anotherSeq.invert();
    cout << "Another reversed sequence: ";
    anotherSeq.show();

    return 0;
}