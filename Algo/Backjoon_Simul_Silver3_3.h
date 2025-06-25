#pragma once
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s1, s2;
stack<int> v;

int main() {
    cin >> s1 >> s2;

    // 항상 s1이 더 길도록 swap
    if (s1.length() < s2.length())
        swap(s1, s2);

    int carry = 0;
    int idx1 = s1.length() - 1;
    int idx2 = s2.length() - 1;

    // 뒤에서부터 한 자리씩 더하기
    while (idx2 >= 0) {
        int sum = (s1[idx1] - '0') + (s2[idx2] - '0') + carry;
        carry = sum / 10;
        v.push(sum % 10);
        idx1--;
        idx2--;
    }

    // s1 나머지 처리
    while (idx1 >= 0) {
        int sum = (s1[idx1] - '0') + carry;
        carry = sum / 10;
        v.push(sum % 10);
        idx1--;
    }

    // 마지막 캐리 처리
    if (carry > 0)
        v.push(carry);

    // 결과 출력
    while (!v.empty()) {
        cout << v.top();
        v.pop();
    }

    cout << '\n';
}
