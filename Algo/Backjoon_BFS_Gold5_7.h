#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, maxi = 0;
int arr[102][102];
bool visited[102][102];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Input() {
    maxi = 0;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            arr[i][j] = 0;
            visited[i][j] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            maxi = max(arr[i][j], maxi);
        }
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x <= n + 1 && 0 <= y && y <= m + 1;
}

// 바다 채우기 BFS (높이 h 이하만 바다로 확장)
void BFS(int x, int y, int h) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (arr[nx][ny] > h) continue; // 땅은 바다로 확장 불가

            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
}

// 섬 BFS (높이 h 이상인 땅만 탐색)
void BFS2(int x, int y, int h) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
}

bool Calc(int h) {
    memset(visited, false, sizeof(visited));

    // 바다 채우기 (경계에서만 시작)
    for (int i = 0; i <= n + 1; i++) {
        if (!visited[i][0] && arr[i][0] <= h) BFS(i, 0, h);
        if (!visited[i][m + 1] && arr[i][m + 1] <= h) BFS(i, m + 1, h);
    }
    for (int j = 0; j <= m + 1; j++) {
        if (!visited[0][j] && arr[0][j] <= h) BFS(0, j, h);
        if (!visited[n + 1][j] && arr[n + 1][j] <= h) BFS(n + 1, j, h);
    }

    // 섬 개수 세기
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && arr[i][j] > h) {
                BFS2(i, j, h);
                cnt++;
            }
        }
    }

    return cnt >= 2; // 섬이 둘 이상으로 갈라졌는지 판정
}

int main() {
    int cnt = 1;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        Input();

        int ans = 0;
        for (int h = 1; h <= maxi; h++) {
            if (Calc(h)) {
                ans = h;
                break;
            }
        }

        if (ans > 0) {
            cout << "Case " << cnt << ": Island splits when ocean rises " << ans << " feet.\n";
        }
        else {
            cout << "Case " << cnt << ": Island never splits.\n";
        }
        cnt++;
    }
}
