#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string findSmallestMultiple(int n) {
    vector<bool> visited(n, false); // 나머지 방문 여부
    queue<pair<int, string>> q;
    q.push({ 1 % n, "1" });
    visited[1 % n] = true;

    while (!q.empty()) {
        auto [rem, num] = q.front();
        q.pop();

        if (rem == 0) return num; // 나누어떨어짐 → 정답

        // 0을 붙인 경우
        int next0 = (rem * 10) % n;
        if (!visited[next0]) {
            visited[next0] = true;
            q.push({ next0, num + "0" });
        }

        // 1을 붙인 경우
        int next1 = (rem * 10 + 1) % n;
        if (!visited[next1]) {
            visited[next1] = true;
            q.push({ next1, num + "1" });
        }
    }
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << findSmallestMultiple(n) << "\n";
    }
}
