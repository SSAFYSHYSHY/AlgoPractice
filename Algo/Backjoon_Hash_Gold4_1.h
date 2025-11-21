#pragma once
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, code;
    getline(cin, s);
    getline(cin, code);

    int arr[200] = { 0 };
    int result = 0;
    int size = s.length();

    // 각 문자에 대해 순서(index) 부여
    for (int i = 0; i < (int)s.length(); ++i) {
        int index = s[i] - '!';
        if (arr[index] == 0) arr[index] = i + 1;
    }

    // 해시 계산
    for (int i = 0; i < (int)code.length(); ++i) {
        int index = code[i] - '!';
        result *= size;
        result += arr[index];
        result %= 900528;
    }

    cout << result << "\n";

    return 0;
}