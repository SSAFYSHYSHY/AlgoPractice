#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct Node {
    int x, y;
    int steps;   // 이동 횟수
    long long sum; // 모은 파워
};

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m;
int sx, sy, ex, ey;
long long arr[11][11];
int dist[11][11];
long long maxPower[11][11];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void Input() {
    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
}

void Solve(int tc) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            dist[i][j] = INT_MAX;
            maxPower[i][j] = 0;
        }

    queue<Node> q;
    q.push({ sx, sy, 0, arr[sx][sy] });
    dist[sx][sy] = 0;
    maxPower[sx][sy] = arr[sx][sy];

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (!InRange(nx, ny)) continue;
            if (arr[nx][ny] == -1) continue;

            int nSteps = cur.steps + 1;
            long long nSum = cur.sum + arr[nx][ny];

            if (nSteps < dist[nx][ny]) {
                dist[nx][ny] = nSteps;
                maxPower[nx][ny] = nSum;
                q.push({ nx, ny, nSteps, nSum });
            }
            else if (nSteps == dist[nx][ny] && nSum > maxPower[nx][ny]) {
                maxPower[nx][ny] = nSum;
                q.push({ nx, ny, nSteps, nSum });
            }
        }
    }

    if (dist[ex][ey] == INT_MAX) {
        cout << "Case #" << tc << ": Mission Impossible.\n";
    }
    else {
        cout << "Case #" << tc << ": " << maxPower[ex][ey] << "\n";
    }
}

int main() {
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        Input();
        Solve(tc);
    }
}
