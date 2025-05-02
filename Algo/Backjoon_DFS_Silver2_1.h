#pragma once
#include <iostream>
#include <string>

using namespace std;

int n, ans = 0;
string digits[] = { "0", "1", "2" };

void backtrack(int depth, string temp) {
    if (depth == n) {
        if (temp[0] == '0') return; // 0으로 시작하면 안 됨

        int sum = 0;
        for (char c : temp) sum += c - '0';

        if (sum % 3 == 0) ans++; // 3의 배수
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