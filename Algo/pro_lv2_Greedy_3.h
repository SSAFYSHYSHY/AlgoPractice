#pragma once
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack <char> st;

    for (int i = 0; i < number.length(); i++) {
        while (!st.empty() && k > 0 && st.top() < number[i]) {
            st.pop();
            k--;
        }
        st.push(number[i]);
    }

    while (k--) {
        st.pop();
    }

    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }

    reverse(answer.begin(), answer.end());

    return answer;
}