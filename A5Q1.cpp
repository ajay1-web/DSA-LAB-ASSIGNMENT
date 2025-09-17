#include <iostream>
using namespace std;

// The basic building block of the list
struct Element {
    int value;
    Element* link;
    Element(int v): value(v), link(nullptr) {}
};

// The class managing the linked list operations
class MyList {
    Element* start;
public:
    MyList() { start = nullptr; }

    // Inserts an item at the head of the list
    void prepend(int item) {
        Element* newElement = new Element(item);
        newElement->link = start;
        start = newElement;
    }

    // Inserts an item at the tail of the list
    void append(int item) {
        Element* newElement = new Element(item);
        if (!start) {
            start = newElement;
            return;
        }
        Element* traverser = start;
        while (traverser->link) traverser = traverser->link;
        traverser->link = newElement;
    }

    // Inserts a new item before an existing item
    void addBefore(int newItem, int existingItem) {
        if (!start) return;
        if (start->value == existingItem) {
            prepend(newItem);
            return;
        }
        Element* previous = nullptr;
        Element* current = start;
        while (current && current->value != existingItem) {
            previous = current;
            current = current->link;
        }
        if (current) {
            Element* newElement = new Element(newItem);
            previous->link = newElement;
            newElement->link = current;
        } else {
            cout << "Item " << existingItem << " not found\n";
        }
    }

    // Inserts a new item after an existing item
    void addAfter(int newItem, int existingItem) {
        Element* current = start;
        while (current && current->value != existingItem)
            current = current->link;
        if (current) {
            Element* newElement = new Element(newItem);
            newElement->link = current->link;
            current->link = newElement;
        } else {
            cout << "Item " << existingItem << " not found\n";
        }
    }

    // Deletes the first item in the list
    void removeFirst() {
        if (!start) {
            cout << "List is empty\n";
            return;
        }
        Element* temp = start;
        start = start->link;
        delete temp;
    }

    // Deletes the last item in the list
    void removeLast() {
        if (!start) {
            cout << "List is empty\n";
            return;
        }
        if (!start->link) {
            delete start;
            start = nullptr;
            return;
        }
        Element* current = start;
        Element* previous = nullptr;
        while (current->link) {
            previous = current;
            current = current->link;
        }
        previous->link = nullptr;
        delete current;
    }

    // Deletes a specific item from the list
    void removeItem(int item) {
        if (!start) {
            cout << "List is empty\n";
            return;
        }
        if (start->value == item) {
            removeFirst();
            return;
        }
        Element* current = start;
        Element* previous = nullptr;
        while (current && current->value != item) {
            previous = current;
            current = current->link;
        }
        if (!current) {
            cout << "Item " << item << " not found\n";
            return;
        }
        previous->link = current->link;
        delete current;
    }

    // Searches for an item and returns its position
    int find(int item) {
        Element* current = start;
        int position = 1;
        while (current) {
            if (current->value == item) return position;
            current = current->link;
            position++;
        }
        return -1; // Not found
    }

    // Displays all items in the list
    void printList() {
        if (!start) {
            cout << "List is empty\n";
            return;
        }
        Element* current = start;
        while (current) {
            cout << current->value << " -> ";
            current = current->link;
        }
        cout << "NULL\n";
    }
};

int main() {
    MyList linkedList;
    int option, num1, num2;
    while (true) {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Prepend (Insert at beginning)\n";
        cout << "2. Append (Insert at end)\n";
        cout << "3. Add before an item\n";
        cout << "4. Add after an item\n";
        cout << "5. Remove from beginning\n";
        cout << "6. Remove from end\n";
        cout << "7. Remove specific item\n";
        cout << "8. Find an item\n";
        cout << "9. Print list\n";
        cout << "10. Exit\n";
        cout << "Enter your option: ";
        cin >> option;
        cout << "------------------------\n";

        switch (option) {
            case 1:
                cout << "Enter item to prepend: "; cin >> num1;
                linkedList.prepend(num1);
                break;
            case 2:
                cout << "Enter item to append: "; cin >> num1;
                linkedList.append(num1);
                break;
            case 3:
                cout << "Enter new item: "; cin >> num1;
                cout << "Enter item to insert before: "; cin >> num2;
                linkedList.addBefore(num1, num2);
                break;
            case 4:
                cout << "Enter new item: "; cin >> num1;
                cout << "Enter item to insert after: "; cin >> num2;
                linkedList.addAfter(num1, num2);
                break;
            case 5:
                linkedList.removeFirst();
                cout << "Removed first item.\n";
                break;
            case 6:
                linkedList.removeLast();
                cout << "Removed last item.\n";
                break;
            case 7:
                cout << "Enter item to remove: "; cin >> num1;
                linkedList.removeItem(num1);
                break;
            case 8:
                cout << "Enter item to find: "; cin >> num1;
                num2 = linkedList.find(num1);
                if (num2 == -1)
                    cout << "Item not found in the list.\n";
                else
                    cout << "Item found at position " << num2 << ".\n";
                break;
            case 9:
                linkedList.printList();
                break;
            case 10:
                cout << "Exiting. Good work today from Patiala!\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
}