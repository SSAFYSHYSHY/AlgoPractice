#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, k;
bool visited[251] = { false };
vector<int> arr[251];

void Input() {
    cin >> n >> k;

    // �湮 �迭 �ʱ�ȭ
    memset(visited, false, sizeof(visited));

    // �׷��� �ʱ�ȭ
    for (int i = 1; i <= n; i++) {
        arr[i].clear();
    }

    // ���� ���� �Է�
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
}

void BFS() {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cx = q.front();
        q.pop();

        for (int i = 0; i < arr[cx].size(); i++) {
            int nx = arr[cx][i];
            if (!visited[nx]) {
                visited[nx] = true;
                q.push(nx);
            }
        }
    }
}

int main() {
    Input();
    BFS();

    bool printed = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << i << "\n";
            printed = true;
        }
    }

    if (!printed) {
        cout << 0 << "\n";
    }

    return 0;
}
