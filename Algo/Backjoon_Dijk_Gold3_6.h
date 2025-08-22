#pragma once
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int r, c;
double v;

int arr[101][101];
double dist[101][101];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Input() {
    cin >> v >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            dist[i][j] = INT_MAX;
        }
    }
}

struct Node {
    int x, y;
    double v, t;  // 현재 속도, 현재까지 걸린 시간
    bool operator>(const Node& other) const {
        return t > other.t;
    }
};

bool InRange(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

void Dijk() {
    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.push({ 0, 0, v, 0 });
    dist[0][0] = 0;

    while (!pq.empty()) {
        int cx = pq.top().x;
        int cy = pq.top().y;
        double cv = pq.top().v;
        double ct = pq.top().t;
        pq.pop();

        if (ct > dist[cx][cy]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (!InRange(nx, ny)) continue;

            double nt = ct + (1.0 / cv);  // 현재 속도로 한 칸 이동
            double nv = cv * (pow(2, arr[cx][cy] - arr[nx][ny])); // 이동 후 속도

            if (nt < dist[nx][ny]) {
                dist[nx][ny] = nt;
                pq.push({ nx, ny, nv, nt });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed;
    cout.precision(2);

    Input();

    Dijk();

    cout << dist[r - 1][c - 1];
}