#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int h, m, n;
int sx, sy, sh, ex, ey, eh;
char arr[51][51][51];
bool visited[51][51][51];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct Node {
    int x, y, z, t;
};

bool InRange(int x, int y) {
    return 0 <= x && x < m && 0 <= y && y < n;  // m=세로, n=가로
}
bool InRangeH(int z) {
    return 0 <= z && z < h;
}

void Input() {
    cin >> h >> m >> n;
    for (int z = 0; z < h; z++) {
        for (int x = 0; x < m; x++) {
            string s; cin >> s;
            for (int y = 0; y < n; y++) {
                arr[z][x][y] = s[y];
                if (s[y] == '1') { sx = x; sy = y; sh = z; }
                if (s[y] == '2') { ex = x; ey = y; eh = z; }
            }
        }
    }
}

void BFS() {
    memset(visited, false, sizeof(visited));
    queue<Node> q;
    q.push({ sx,sy,sh,0 });
    visited[sh][sx][sy] = true;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        int t = q.front().t;
        q.pop();

        if (x == ex && y == ey && z == eh) {
            cout << t * 5 << "\n";
            return;
        }

        // 수평 4방향
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!InRange(nx, ny)) continue;
            if (visited[z][nx][ny]) continue;
            if (arr[z][nx][ny] == 'o') continue;
            visited[z][nx][ny] = true;
            q.push({ nx,ny,z,t + 1 });
        }

        // 수직 아래로
        int nz = z + 1;
        if (InRangeH(nz) && !visited[nz][x][y] && arr[nz][x][y] != 'o') {
            visited[nz][x][y] = true;
            q.push({ x,y,nz,t + 1 });
        }
    }
}

int main() {
    Input();
    BFS();
}
