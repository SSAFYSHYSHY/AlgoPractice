#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int n, m;
int sx, sy;

char arr[301][301];
bool visited[301][301];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

struct Node {
    int x, y, cnt;
};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

// BFS: (x, y)에서 시작하여 tar 문자가 있는 가장 가까운 칸까지 거리 반환
pair<int, pair<int, int>> BFS(int x, int y, char tar) {
    memset(visited, false, sizeof(visited));
    queue<Node> q;
    q.push({ x, y, 0 });
    visited[x][y] = true;
    int ax, ay;
    int mini = INT_MAX;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int cx = cur.x, cy = cur.y, ccnt = cur.cnt;

        if (arr[cx][cy] == tar) {

            if (mini > ccnt) {
                mini = ccnt;
                ax = cx;
                ay = cy;
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny, ccnt + 1 });
        }
    }

    return { mini, {ax,ay} };
}

void Input() {
    cin >> n >> m;
    cin >> sx >> sy;
    sx--; sy--; // 0-index 변환

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j];
        }
    }
}

int main() {
    Input();

    string s;
    cin >> s;

    int ans = 0;
    int cx = sx, cy = sy;

    for (int i = 0; i < s.length(); i++) {
        auto res = BFS(cx, cy, s[i]);
        int dist = res.first;
        cx = res.second.first;
        cy = res.second.second;
        ans += dist;
    }

    cout << ans;
}
