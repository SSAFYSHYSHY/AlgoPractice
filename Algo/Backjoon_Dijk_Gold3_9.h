#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <climits>
#include <queue>

using namespace std;

int N, M;
long long K;
vector<string> grid;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Node {
    int x, y;
    long long jump, cost;
    bool operator>(const Node& o) const {
        return cost > o.cost;
    }
};

bool inRange(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    grid.resize(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--; // 0-index

    // dist[x][y][j] : (x,y)에 메가점프 j번 사용 후 최소 비용
    // K 최대 1e6이라서 배열 불가능 → map/해시로 관리
    unordered_map<long long, int> dist;
    auto encode = [&](int x, int y, long long j) {
        return ((long long)x << 40) | ((long long)y << 20) | j;
        };

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[encode(sx, sy, 0)] = 0;
    pq.push({ sx,sy,0,0 });

    while (!pq.empty()) {
        auto [x, y, j, c] = pq.top(); pq.pop();
        long long key = encode(x, y, j);
        if (dist[key] < c) continue; // 이미 더 짧은 경로 있음
        if (x == ex && y == ey) {
            cout << "YES\n";
            return 0;
        }

        // 일반 이동
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (!inRange(nx, ny)) continue;
            if (grid[nx][ny] == '#') continue;
            long long nk = encode(nx, ny, j);
            if (!dist.count(nk) || dist[nk] > c + 1) {
                dist[nk] = c + 1;
                pq.push({ nx,ny,j,c + 1 });
            }
        }
        // 메가점프
        if (j < K) {
            for (int d = 0; d < 4; d++) {
                int nx = x + 2 * dx[d], ny = y + 2 * dy[d];
                if (!inRange(nx, ny)) continue;
                if (grid[nx][ny] == '#') continue;
                long long nk = encode(nx, ny, j + 1);
                if (!dist.count(nk) || dist[nk] > c + 1) {
                    dist[nk] = c + 1;
                    pq.push({ nx,ny,j + 1,c + 1 });
                }
            }
        }
    }
    cout << "NO\n";
}
