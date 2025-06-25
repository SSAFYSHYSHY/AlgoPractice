#pragma once
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s1, s2;
stack<int> v;

int main() {
    cin >> s1 >> s2;

    // �׻� s1�� �� �浵�� swap
    if (s1.length() < s2.length())
        swap(s1, s2);

    int carry = 0;
    int idx1 = s1.length() - 1;
    int idx2 = s2.length() - 1;

    // �ڿ������� �� �ڸ��� ���ϱ�
    while (idx2 >= 0) {
        int sum = (s1[idx1] - '0') + (s2[idx2] - '0') + carry;
        carry = sum / 10;
        v.push(sum % 10);
        idx1--;
        idx2--;
    }

    // s1 ������ ó��
    while (idx1 >= 0) {
        int sum = (s1[idx1] - '0') + carry;
        carry = sum / 10;
        v.push(sum % 10);
        idx1--;
    }

    // ������ ĳ�� ó��
    if (carry > 0)
        v.push(carry);

    // ��� ���
    while (!v.empty()) {
        cout << v.top();
        v.pop();
    }

    cout << '\n';
}
