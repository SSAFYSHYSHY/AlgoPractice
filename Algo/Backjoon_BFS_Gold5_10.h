#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int n;
int arr[101][101][101];      // [Ãþ][x][y]
bool visited[101][101][101]; // [x][y][Ãþ]

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int dh[] = { -1, 1 };

int sx, sy, sh;
int ex, ey, eh;

struct Node {
    int x, y, h, cnt;
};

void Input() {
    memset(visited, 0, sizeof(visited));

    cin >> n;


    cin >> sx >> sy >> sh;
    cin >> ex >> ey >> eh;

    // 0-indexed·Î º¯È¯
    sx--; sy--; sh--;
    ex--; ey--; eh--;

    // arr[k][i][j] => k: Ãþ, i: x, j: y
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                arr[k][i][j] = s[j] - '0';
            }
        }
    }
}

bool InRangeXY(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool InRangeH(int h) {
    return 0 <= h && h < n;
}

void BFS() {
    queue<Node> q;
    visited[sx][sy][sh] = true;
    q.push({ sx, sy, sh, 0 });

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        int cx = cur.x, cy = cur.y, ch = cur.h, ccnt = cur.cnt;

        if (cx == ex && cy == ey && ch == eh) {
            cout << ccnt;
            return;
        }

        // »óÇÏÁÂ¿ì ÀÌµ¿
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!InRangeXY(nx, ny)) continue;
            if (arr[ch][nx][ny] == 1) continue;
            if (visited[nx][ny][ch]) continue;

            visited[nx][ny][ch] = true;
            q.push({ nx, ny, ch, ccnt + 1 });
        }

        // Ãþ ÀÌµ¿
        for (int i = 0; i < 2; i++) {
            int nh = ch + dh[i];

            if (!InRangeH(nh)) continue;
            if (arr[nh][cx][cy] == 1) continue;
            if (visited[cx][cy][nh]) continue;

            visited[cx][cy][nh] = true;
            q.push({ cx, cy, nh, ccnt + 1 });
        }
    }

    // µµ´Þ ºÒ°¡
    cout << -1;
}

int main() {
    Input();
    BFS();
}
