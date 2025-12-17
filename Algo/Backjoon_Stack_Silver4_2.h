#pragma once
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    while (true) {
        string s;
        getline(cin, s);

        if (s == ".") break;

        stack<char> st;
        bool ok = true;

        for (char c : s) {
            if (c == '(' || c == '[') {
                st.push(c);
            }
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    ok = false;
                    break;
                }
                st.pop();
            }
            else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }

        if (ok && st.empty()) cout << "yes\n";
        else cout << "no\n";
    }
}