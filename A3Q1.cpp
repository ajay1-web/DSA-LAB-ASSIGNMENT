#include <iostream>
using namespace std;


class Stack {
    int arr[100];
    int top;
    int size;

public:
    Stack(int s) {
        top = -1;
        size = s;
    }

    void push(int n) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = n;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;
    Stack s1(size);

    int choice, value;
    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. IsEmpty\n6. IsFull\n7. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s1.push(value);
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                s1.peek();
                break;
            case 4:
                s1.display();
                break;
            case 5:
                cout << (s1.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case 6:
                cout << (s1.isFull() ? "Stack is full" : "Stack is not full") << endl;
                break;
            case 7:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 7);

    return 0;
}
