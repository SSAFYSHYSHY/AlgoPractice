#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int n, m;
char arr[21][21];
bool visited[21][21][21][21]; // 두 동전 좌표 방문 체크

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

struct Node {
    int ax, ay;
    int bx, by;
    int cnt;
};

int sx, sy, sx2, sy2;

void Input() {
    cin >> n >> m;
    bool first = false;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j];
            if (arr[i][j] == 'o') {
                if (!first) {
                    sx = i; sy = j;
                    first = true;
                }
                else {
                    sx2 = i; sy2 = j;
                }
            }
        }
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS() {
    memset(visited, false, sizeof(visited));
    queue<Node> q;
    q.push({ sx, sy, sx2, sy2, 0 });
    visited[sx][sy][sx2][sy2] = true;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        //if (cur.cnt >= 10) continue; // 10번 넘으면 더 못감

        for (int i = 0; i < 4; i++) {
            int nax = cur.ax + dx[i];
            int nay = cur.ay + dy[i];
            int nbx = cur.bx + dx[i];
            int nby = cur.by + dy[i];

            bool outA = !InRange(nax, nay);
            bool outB = !InRange(nbx, nby);

            // 벽이면 제자리
            if (!outA && arr[nax][nay] == '#') { nax = cur.ax; nay = cur.ay; outA = false; }
            if (!outB && arr[nbx][nby] == '#') { nbx = cur.bx; nby = cur.by; outB = false; }

            // 두 동전이 동시에 떨어지면 무효
            if (outA && outB) continue;

            // 하나만 떨어졌으면 정답
            if (outA ^ outB) {
                cout << cur.cnt + 1 << "\n";
                return;
            }

            // 방문 체크
            if (!visited[nax][nay][nbx][nby]) {
                visited[nax][nay][nbx][nby] = true;
                q.push({ nax, nay, nbx, nby, cur.cnt + 1 });
            }
        }
    }

    cout << -1 << "\n"; // 불가능
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    BFS();
}
