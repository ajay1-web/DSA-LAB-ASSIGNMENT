#include <iostream>
using namespace std;

int main() {
    char c = 'A';
    if (c >= 'A' && c <= 'Z') {
        c = c + 32;
    }
    cout << c;
}
