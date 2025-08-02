#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string>
#include <cstring>

using namespace std;

const int INF = 1e9;
int n, m;
char arr[51][51];
int dist[51][51][6];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

struct Node {
    int cost, x, y, k;
    bool operator>(const Node& o) const {
        return cost > o.cost;
    }
};

void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j];
        }
    }
    cin >> m;
}

int Dijkstra(int sx, int sy, int ex, int ey) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 1; k <= 5; k++)
                dist[i][j][k] = INF;

    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.push({ 0, sx, sy, 1 });
    dist[sx][sy][1] = 0;

    while (!pq.empty()) {
        int cost = pq.top().cost;
        int x = pq.top().x;
        int y = pq.top().y;
        int k = pq.top().k;
        pq.pop();

        if (dist[x][y][k] < cost) continue;
        if (x == ex && y == ey) return cost;

        // 1. 점프 이동
        for (int dir = 0; dir < 4; dir++) {
            for (int d = 1; d <= k; d++) {
                int nx = x + dx[dir] * d;
                int ny = y + dy[dir] * d;
                if (!InRange(nx, ny)) break;

                bool blocked = false;
                for (int s = 1; s <= d; s++) {
                    int tx = x + dx[dir] * s;
                    int ty = y + dy[dir] * s;
                    if (!InRange(tx, ty) || arr[tx][ty] == '#') {
                        blocked = true;
                        break;
                    }
                }

                if (blocked) break;
                if (arr[nx][ny] == '#' || arr[nx][ny] == 'S') continue;

                if (dist[nx][ny][k] > cost + 1) {
                    dist[nx][ny][k] = cost + 1;
                    pq.push({ cost + 1, nx, ny, k });
                }
            }
        }

        // 2. 점프력 증가
        if (k < 5) {
            int nk = k + 1;
            int ncost = cost + nk * nk;
            if (dist[x][y][nk] > ncost) {
                dist[x][y][nk] = ncost;
                pq.push({ ncost, x, y, nk });
            }
        }

        // 3. 점프력 감소
        if (k > 1) {
            int nk = k - 1;
            int ncost = cost + 1;
            if (dist[x][y][nk] > ncost) {
                dist[x][y][nk] = ncost;
                pq.push({ ncost, x, y, nk });
            }
        }
    }

    return -1; // 도달 불가
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    for (int i = 0; i < m; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sx--; sy--; ex--; ey--;

        if (sx == ex && sy == ey) {
            cout << "0\n";
            continue;
        }

        cout << Dijkstra(sx, sy, ex, ey) << "\n";
    }
}
