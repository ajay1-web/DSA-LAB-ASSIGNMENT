#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;
    int start = 0, end = n - 1, mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            cout << mid;
            return 0;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << -1;
    return 0;
}
