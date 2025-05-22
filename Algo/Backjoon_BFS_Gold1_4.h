#pragma once
#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

int n, m;
char arr[51][51];
bool visited[51][51][5][2][2]; // [x][y][dir][c1][c2]

int dx[] = { -1, 1, 0, 0 }; // 상하좌우
int dy[] = { 0, 0, -1, 1 };

pair<int, int> start;
pair<int, int> c1, c2;

struct State {
    int x, y, dist;
    int prev_dir;
    int v1, v2;
};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void Input() {
    cin >> n >> m;
    int c_cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                start = make_pair(i, j);
                arr[i][j] = '.';
            }
            if (arr[i][j] == 'C') {
                if (c_cnt == 0) c1 = make_pair(i, j);
                else c2 = make_pair(i, j);
                c_cnt++;
            }
        }
    }
}

int BFS() {
    memset(visited, false, sizeof(visited));
    queue<State> q;

    q.push({ start.first, start.second, 0, 4, 0, 0 }); // 4는 초기값으로 이전 방향 없음
    visited[start.first][start.second][4][0][0] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.v1 && cur.v2) return cur.dist;

        for (int dir = 0; dir < 4; dir++) {
            if (dir == cur.prev_dir) continue;

            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (!InRange(nx, ny)) continue;
            if (arr[nx][ny] == '#') continue;

            int nv1 = cur.v1;
            int nv2 = cur.v2;

            if (nx == c1.first && ny == c1.second) nv1 = 1;
            if (nx == c2.first && ny == c2.second) nv2 = 1;

            if (!visited[nx][ny][dir][nv1][nv2]) {
                visited[nx][ny][dir][nv1][nv2] = true;
                q.push({ nx, ny, cur.dist + 1, dir, nv1, nv2 });
            }
        }
    }

    return -1;
}

int main() {
    Input();
    int result = BFS();
    cout << result;
    return 0;
}
