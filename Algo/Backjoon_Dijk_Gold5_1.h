#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
int sx, sy, ex, ey;
long long arr[501][501];
long long dist[501][501];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Dijkstra() {
    dist[sx][sy] = arr[sx][sy];
    priority_queue<pair<long long, pair<int, int>>> pq;
    pq.push(make_pair(-arr[sx][sy], make_pair(sx, sy)));

    while (!pq.empty()) {
        long long cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (cost > dist[x][y]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!InRange(nx, ny)) continue;
            if (arr[nx][ny] < 0) continue;

            long long next_cost = cost + arr[nx][ny];

            if (dist[nx][ny] == 0 || next_cost < dist[nx][ny]) {
                dist[nx][ny] = next_cost;
                pq.push(make_pair(-next_cost, make_pair(nx, ny)));
            }
        }
    }
}

int main() {
    cin >> n >> sy >> sx >> ey >> ex;
    sx--; sy--; ex--; ey--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    if (arr[sx][sy] < 0 || arr[ex][ey] < 0) {
        cout << -1 << "\n";
        return 0;
    }

    Dijkstra();

    if (dist[ex][ey] == 0) {
        cout << -1 << "\n";
    }
    else {
        cout << dist[ex][ey] << "\n";
    }

    return 0;
}
