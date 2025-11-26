#include <iostream>
using namespace std;

#define MAX 100

class PriorityQueue {
    int heap[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    // Insert element into Priority Queue
    void insert(int value) {
        if (size == MAX) {
            cout << "Priority Queue Overflow\n";
            return;
        }

        heap[size] = value;
        int i = size;
        size++;

        // Heapify Up
        while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Remove highest priority element
    void remove() {
        if (size <= 0) {
            cout << "Priority Queue Underflow\n";
            return;
        }

        cout << "Removed Element: " << heap[0] << endl;
        heap[0] = heap[size - 1];
        size--;

        heapify(0);
    }

    // Heapify Down
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    // Display Queue
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty\n";
            return;
        }
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    while (true) {
        cout << "\n--- Priority Queue Using Heap ---\n";
        cout << "1. Insert\n";
        cout << "2. Remove Highest Priority\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            pq.insert(value);
            break;
        case 2:
            pq.remove();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }
}
