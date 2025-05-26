#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int arr[101][101];
vector<int> trinity; // ���� ������ 3���� ����
bool visited[101][101];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// ������ ���� �� ���� ����
bool isValidNumber(int num) {
    return trinity[0] == num || trinity[1] == num || trinity[2] == num;
}

// ���� Ȯ��
bool inRange(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

// BFS�� ù �࿡�� ������ ����� ���� ���� ���� Ȯ��
bool canEscapeFrom(int startY) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;

    q.push(make_pair(0, startY));
    visited[0][startY] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1) return true;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (inRange(nx, ny) && !visited[nx][ny] && isValidNumber(arr[nx][ny])) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return false;
}

int main() {
    cin >> m >> n; // �� m, �� n

    for (int i = 0; i < n; i++) {     // ��
        for (int j = 0; j < m; j++) { // ��
            cin >> arr[i][j];
        }
    }

    // 0~9 �� �ߺ� ��� 3�� for������ ��� ���� Ȯ��
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                trinity.clear();
                trinity.push_back(a);
                trinity.push_back(b);
                trinity.push_back(c);
                for (int col = 0; col < m; col++) {
                    if (isValidNumber(arr[0][col]) && canEscapeFrom(col)) {
                        cout << a << " " << b << " " << c << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    // �Ұ����� ���
    cout << "-1 -1 -1\n";
    return 0;
}
