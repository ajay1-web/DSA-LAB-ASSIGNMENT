#include <iostream>
using namespace std;

// Represents a single item in the data chain
struct ListItem {
    int value;
    ListItem* link;
    ListItem(int v): value(v), link(nullptr) {}
};

// Manages the chain of list items
class DataChain {
    ListItem* start;
public:
    DataChain() { start = nullptr; }

    // Adds a new item to the end of the chain
    void append(int item) {
        ListItem* newItem = new ListItem(item);
        if (!start) {
            start = newItem;
            return;
        }
        ListItem* current = start;
        while (current->link) current = current->link;
        current->link = newItem;
    }

    // Counts how many times a target value appears
    int frequencyOf(int target) {
        int freq = 0;
        ListItem* current = start;
        while (current) {
            if (current->value == target)
                freq++;
            current = current->link;
        }
        return freq;
    }

    // Removes all items with the target value from the chain
    void purge(int target) {
        // First, handle any target values at the beginning of the chain
        while (start && start->value == target) {
            ListItem* nodeToRemove = start;
            start = start->link;
            delete nodeToRemove;
        }
        if (!start) return;

        // Next, handle target values in the rest of the chain
        ListItem* current = start;
        while (current->link) {
            if (current->link->value == target) {
                ListItem* nodeToRemove = current->link;
                current->link = current->link->link;
                delete nodeToRemove;
            } else {
                current = current->link;
            }
        }
    }

    // Prints the entire data chain to the console
    void printChain() {
        ListItem* current = start;
        while (current) {
            cout << current->value;
            if (current->link) cout << " -> ";
            current = current->link;
        }
        cout << "\n";
    }
};

int main() {
    DataChain chain;
    int initialData[] = {1, 2, 1, 2, 1, 3, 1};
    for (int item : initialData) {
        chain.append(item);
    }

    int targetValue = 1;
    cout << "Original chain: ";
    chain.printChain();

    int occurrenceCount = chain.frequencyOf(targetValue);
    cout << "Frequency of " << targetValue << ": " << occurrenceCount << "\n";

    cout << "Purging all instances of " << targetValue << "...\n";
    chain.purge(targetValue);
    
    cout << "Updated chain: ";
    chain.printChain();

    return 0;
}