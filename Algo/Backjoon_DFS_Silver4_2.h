#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int target;
bool found;

void DFS(int idx, long long value, long long last, string expr) {
    if (found) return;

    if (idx == 4) {
        if (value == target) {
            cout << expr << " = " << target << "\n";
            found = true;
        }
        return;
    }

    if (idx == 0) {
        DFS(1, 4, 4, "4");
        return;
    }

    // +
    DFS(idx + 1, value + 4, 4, expr + " + 4");

    // -
    DFS(idx + 1, value - 4, -4, expr + " - 4");

    // *
    DFS(idx + 1,
        value - last + last * 4,
        last * 4,
        expr + " * 4");

    // /
    if (4 != 0) {
        DFS(idx + 1,
            value - last + last / 4,
            last / 4,
            expr + " / 4");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> target;
        found = false;

        DFS(0, 0, 0, "");

        if (!found) {
            cout << "no solution\n";
        }
    }
}