#pragma once
//https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/frog-journey/description
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>

using namespace std;

struct Node {
    int x, y, k, cost;
    bool operator<(const Node& o) const {
        return cost > o.cost;
    }
};

int n, q;
vector<string> arr;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dist[55][55][6]; // 점프력 1~5

bool Calc(int sx, int sy, int ex, int ey, int dir) {
    int dirx = dx[dir], diry = dy[dir];
    while (sx != ex || sy != ey) {
        sx += dirx;
        sy += diry;
        if (sx < 0 || sx >= n || sy < 0 || sy >= n) return false;
        if (arr[sx][sy] == '#') return false;
    }
    return true;
}

int dijkstra(int sx, int sy, int ex, int ey) {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 1; k <= 5; k++)
        dist[i][j][k] = 1e9;

    priority_queue<Node> pq;
    dist[sx][sy][1] = 0;
    pq.push({ sx,sy,1,0 });

    while (!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int k = pq.top().k;
        int c = pq.top().cost;
        pq.pop();

        if (c > dist[x][y][k]) continue;
        if (x == ex && y == ey) return c;

        // 1. 점프 (비용 +1)
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir] * k;
            int ny = y + dy[dir] * k;

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (!Calc(x, y, nx, ny, dir)) continue;
            if (arr[nx][ny] == '#' || arr[nx][ny] == 'S') continue;

            if (c + 1 < dist[nx][ny][k]) {
                dist[nx][ny][k] = c + 1;
                pq.push({ nx,ny,k,c + 1 });
            }
        }

        // 2. 점프력 증가 (비용 +(k+1)^2)
        if (k < 5) {
            int nk = k + 1;
            int nc = c + nk * nk;
            if (nc < dist[x][y][nk]) {
                dist[x][y][nk] = nc;
                pq.push({ x,y,nk,nc });
            }
        }

        // 3. 점프력 감소 (비용 +1)
        if (k > 1) {
            for (int nk = 1; nk < k; nk++) {
                int nc = c + 1;
                if (nc < dist[x][y][nk]) {
                    dist[x][y][nk] = nc;
                    pq.push({ x,y,nk,nc });
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> q;

    while (q--) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sx--; sy--; ex--; ey--;
        cout << dijkstra(sx, sy, ex, ey) << "\n";
    }
}