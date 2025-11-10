#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && c != '(' && c != ')') {
            result += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            int prec;
            if (c == '^') prec = 3;
            else if (c == '*' || c == '/') prec = 2;
            else prec = 1;

            while (!st.empty()) {
                char topOp = st.top();
                int topPrec;
                if (topOp == '^') topPrec = 3;
                else if (topOp == '*' || topOp == '/') topPrec = 2;
                else topPrec = 1;

                bool rightAssoc = (c == '^');
                if (topOp != '(' && (topPrec > prec || (topPrec == prec && !rightAssoc))) {
                    result += topOp;
                    st.pop();
                } else break;
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    cout << result;
    return 0;
}
