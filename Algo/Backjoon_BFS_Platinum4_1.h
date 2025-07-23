#pragma once
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int n, m, k;
char arr[1001][1001];
int dist[1001][1001];  // 이동 횟수 기록
int s_x, s_y, e_x, e_y;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS() {
    queue<pair<int, int>> q;
    q.push({ s_x, s_y });
    dist[s_x][s_y] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == e_x && y == e_y) {
            cout << dist[x][y] << "\n";
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            for (int step = 1; step <= k; step++) {
                int nx = x + dx[dir] * step;
                int ny = y + dy[dir] * step;

                if (!InRange(nx, ny) || arr[nx][ny] == '#') break;

                if (dist[nx][ny] != -1) {
                    // 이미 방문했는데 지금 이동 횟수가 더 많으면 중단
                    if (dist[nx][ny] < dist[x][y] + 1) break;
                    else continue;
                }

                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    // 도달 못함
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j];
        }
    }

    cin >> s_x >> s_y >> e_x >> e_y;
    s_x--; s_y--; e_x--; e_y--;

    memset(dist, -1, sizeof(dist));
    BFS();
}
