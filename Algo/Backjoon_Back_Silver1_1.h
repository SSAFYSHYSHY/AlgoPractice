#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int back[11], arr[11][11];
int visited[11];
bool found = false;

bool Calc() {
    for (int i = 0; i < n; i++) {
        arr[0][i] = back[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j + 1];
        }
    }

    return arr[n - 1][0] == m;
}

void Back(int now) {
    if (found) return; // 이미 찾았으면 더 이상 진행 X

    if (now == n) {
        if (Calc()) {
            for (int i = 0; i < n; i++) {
                cout << back[i] << " ";
            }
            cout << '\n';
            found = true;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            back[now] = i + 1;
            Back(now + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    Back(0);
}
