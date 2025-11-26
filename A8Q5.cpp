#include <iostream>
using namespace std;

// Function to heapify for Max Heap (for Increasing Order)
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Heap Sort for Increasing Order
void heapSortAscending(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// Function to heapify for Min Heap (for Decreasing Order)
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Heap Sort for Decreasing Order
void heapSortDescending(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

// Display array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {40, 10, 30, 50, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    display(arr, n);

    heapSortAscending(arr, n);
    cout << "Sorted in Increasing Order: ";
    display(arr, n);

    int arr2[] = {40, 10, 30, 50, 20};

    heapSortDescending(arr2, n);
    cout << "Sorted in Decreasing Order: ";
    display(arr2, n);

    return 0;
}
