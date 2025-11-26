#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};

    unordered_map<int, int> freq;

    // Count frequency
    for (int num : nums) {
        freq[num]++;
    }

    // Display result
    for (auto pair : freq) {
        cout << pair.first << " -> " << pair.second << " time";
        if (pair.second > 1) cout << "s";
        cout << endl;
    }

    return 0;
}
