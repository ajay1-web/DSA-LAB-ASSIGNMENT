#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int n = 0;

void createArray() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement() {
    int pos, val;
    cout << "Enter position (0 to " << n-1 << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;

    if (pos < 0 || pos > n || n == MAX) {
        cout << "Invalid position or array is full.\n";
        return;
    }
    for (int i = n-1; i >= pos; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos] = val;
    n++;
}

void deleteElement() {
    int pos;
    cout << "Enter position to delete (0 to " << n - 1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linearSearch() {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i << endl;
            return;
        }
    }
    cout << "Element not found.\n";
}

int main() {
    int choice;

    
        do{cout << "\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Linear Search\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }}
        while (choice!=6);
        
        
    

    return 0;
}
