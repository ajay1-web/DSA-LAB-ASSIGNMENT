#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};

    unordered_set<int> setA;
    unordered_set<int> common;

    // Insert elements of array A into set
    for (int num : A)
        setA.insert(num);

    // Check elements of B
    for (int num : B) {
        if (setA.find(num) != setA.end())
            common.insert(num);
    }

    cout << "Common Elements: ";
    for (int num : common)
        cout << num << " ";

    return 0;
}
