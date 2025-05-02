#pragma once
#include <iostream>
#include <string>

using namespace std;

int n, ans = 0;
string digits[] = { "0", "1", "2" };

void backtrack(int depth, string temp) {
    if (depth == n) {
        if (temp[0] == '0') return; // 0���� �����ϸ� �� ��

        int sum = 0;
        for (char c : temp) sum += c - '0';

        if (sum % 3 == 0) ans++; // 3�� ���
        return;
    }

    for (int i = 0; i < 3; i++) {
        backtrack(depth + 1, temp + digits[i]);
    }
}

int main() {
    cin >> n;
    backtrack(0, "");
    cout << ans;
}