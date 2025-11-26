#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int minIndex = start;
        int maxIndex = start;

        // Find min and max in the unsorted part
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place minimum at the beginning
        swap(arr[start], arr[minIndex]);

        // If maximum was at 'start', it has moved to minIndex
        if (maxIndex == start)
            maxIndex = minIndex;

        // Place maximum at the end
        swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal Array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
