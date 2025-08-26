#pragma once
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define INF 987654321
#define F first
#define S second

using namespace std;

int R, C, N;
int dx[11];
int dy[11];
int map[1001][1001];
int check[1001][1001];
int ans = INF;
queue<pair<pair<int, int>, int>> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().F.F;
        int y = q.front().F.S;
        int cnt = q.front().S;
        q.pop();
        if (x == R) ans = min(ans, cnt);
        for (int i = 0; i < N; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= R && yy >= 1 && yy <= C) {
                if (check[xx][yy] == 1) continue;
                if (map[xx][yy] == 1) {
                    check[xx][yy] = 1;
                    q.push({ {xx, yy}, cnt + 1 });
                }
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= C; i++) {
        if (map[1][i] == 1) {
            q.push({ {1, i}, 0 });
            check[1][i] = 1;
        }
    }
    bfs();
    if (ans == INF) cout << "-1";
    else cout << ans;
}

int main() {
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> map[i][j];
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> dx[i] >> dy[i];
    }
    solve();
    return 0;
}