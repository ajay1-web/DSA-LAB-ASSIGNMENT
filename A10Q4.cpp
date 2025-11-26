#include <iostream>
#include <unordered_map>
using namespace std;

int firstNonRepeating(int arr[], int n) {
    unordered_map<int, int> freq;

    // Count frequency of each element
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Find first non-repeating element
    for(int i = 0; i < n; i++) {
        if(freq[arr[i]] == 1)
            return arr[i];
    }

    return -1; // if no non-repeating element exists
}

int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = firstNonRepeating(arr, n);

    if(result != -1)
        cout << "First non-repeating element: " << result;
    else
        cout << "No non-repeating element found";

    return 0;
}
