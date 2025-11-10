#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            st.push(c - '0');
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
            else if (c == '^') st.push(pow(a, b));
        }
    }
    cout << st.top();
    return 0;
}
