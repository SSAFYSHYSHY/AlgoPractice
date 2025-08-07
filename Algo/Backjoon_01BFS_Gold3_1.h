#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

int n, sx, sy, mx = 0, my = 0;
int dist[1002][1002];
int arr[1002][1002];

void Input() {
    cin >> n >> sx >> sy;

    mx = max(sx, mx);
    my = max(sy, my);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;

        mx = max(x, mx);
        my = max(y, my);
    }

    for (int i = 1; i <= mx; i++) {
        for (int j = 1; j <= my; j++) {
            dist[i][j] = INT_MAX;

            if (arr[i][j] != 1) {
                arr[i][j] = 0;
            }
        }
    }
}

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool InRange(int x, int y) {
    return 1 <= x && x <= mx && 1 <= y && y <= my;
}

struct Node {
    int x, y;

};

void BFS() {
    deque<Node> dq;
    dist[sx][sy] = 0;
    dq.push_front({ sx, sy });

    while (!dq.empty()) {
        int cx = dq.front().x;
        int cy = dq.front().y;
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!InRange(nx, ny)) continue;

            int cost = (arr[nx][ny] == 1 ? 1 : 0);
            int new_cost = dist[cx][cy] + cost;

            if (dist[nx][ny] > new_cost) {
                dist[nx][ny] = new_cost;

                if (cost == 0) {
                    dq.push_front({ nx,ny });
                }
                else {
                    dq.push_back({ nx,ny });
                }

            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Input();
    BFS();

    cout << dist[1][1];

    return 0;
}
