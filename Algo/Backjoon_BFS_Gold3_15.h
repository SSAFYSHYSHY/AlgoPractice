#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, k;
int arr[1003][1003];       // �е� ����
bool visited[1003][1003];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// mid �������� K�� �̻� ä�� �������� Ȯ��
bool Calc(int mid) {
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({ 0,0 });   // (0,0)�� ���� (�ٱ� �е�)
    visited[0][0] = true;

    int cnt = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1) continue;
            if (visited[nx][ny]) continue;

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                // ���� ���� (���� ĭ)
                if (arr[nx][ny] <= mid) {
                    visited[nx][ny] = true;
                    cnt++;
                    q.push({ nx,ny });
                    if (cnt >= k) return true; // ���� ����
                }
                // arr[nx][ny] > mid �� �� -> skip
            }
            else {
                // �ٱ� ����
                visited[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
    }

    return cnt >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int l = 1, r = 1000000, ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (Calc(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans + 1 << "\n";
    return 0;
}
