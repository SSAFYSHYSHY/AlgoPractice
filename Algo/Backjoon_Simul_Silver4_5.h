#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
int jungle[41][41];
bool visited[41][41] = { false, };

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> jungle[i][j];
        }
    }

    int x = 0, y = 0;
    int total = jungle[0][0];
    visited[0][0] = true;

    while (!(x == R - 1 && y == C - 1)) {
        int maxFruit = -1;
        int nextX = -1, nextY = -1;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (visited[nx][ny]) continue;

            if (jungle[nx][ny] > maxFruit) {
                maxFruit = jungle[nx][ny];
                nextX = nx;
                nextY = ny;
            }
        }

        x = nextX;
        y = nextY;
        visited[x][y] = true;
        total += jungle[x][y];
    }

    cout << total << "\n";
    return 0;
}