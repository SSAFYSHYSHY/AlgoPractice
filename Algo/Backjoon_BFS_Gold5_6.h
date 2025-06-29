#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
char arr[101][101];
bool visited[101][101][2]; // [행][열][슈퍼이동 사용 여부]
pair<pair<int, int>, bool> parent[101][101][2]; // 이전 위치, 슈퍼 사용 여부

// 일반 나이트 이동
int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };

// 슈퍼 나이트 이동
int sdx[] = { -3,-1,1,3,3,1,-1,-3 };
int sdy[] = { 1,3,3,1,-1,-3,-3,-1 };

struct Node {
    int x, y;
    int dist;
    bool usedSuper;
};

pair<int, int> start, dest;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS() {
    queue<Node> q;
    visited[start.first][start.second][0] = true;
    q.push(Node{ start.first, start.second, 0, false });

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int dist = cur.dist;
        bool used = cur.usedSuper;

        if (x == dest.first && y == dest.second) {
            // 도착 지점에 도달했으면 경로 추적
            vector<pair<int, int> > path;
            int cx = x;
            int cy = y;
            bool cf = used;

            while (!(cx == start.first && cy == start.second)) {
                path.push_back(make_pair(cx + 1, cy + 1));
                pair<pair<int, int>, bool> prev = parent[cx][cy][cf];
                cx = prev.first.first;
                cy = prev.first.second;
                cf = prev.second;
            }

            path.push_back(make_pair(start.first + 1, start.second + 1));
            reverse(path.begin(), path.end());

            // 출력
            cout << (int)path.size() - 1 << "\n";
            for (int i = 0; i < (int)path.size(); i++) {
                cout << path[i].first << " " << path[i].second << "\n";
            }

            return;
        }

        // 일반 나이트 이동
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny][used] && arr[nx][ny] != '#') {
                visited[nx][ny][used] = true;
                parent[nx][ny][used] = make_pair(make_pair(x, y), used);
                q.push(Node{ nx, ny, dist + 1, used });
            }
        }

        // 슈퍼 이동 (한 번만 가능)
        if (!used) {
            for (int i = 0; i < 8; i++) {
                int nx = x + sdx[i];
                int ny = y + sdy[i];

                if (InRange(nx, ny) && !visited[nx][ny][1] && arr[nx][ny] != '#') {
                    visited[nx][ny][1] = true;
                    parent[nx][ny][1] = make_pair(make_pair(x, y), used);
                    q.push(Node{ nx, ny, dist + 1, true });
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j];
            if (arr[i][j] == '@') {
                start = make_pair(i, j);
            }
            else if (arr[i][j] == '*') {
                dest = make_pair(i, j);
            }
        }
    }

    BFS();

    return 0;
}
