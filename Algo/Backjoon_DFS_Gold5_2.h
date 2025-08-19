#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int N, dy[2] = { 1, 0 }, dx[2] = { 0, 1 };
int minv = 1e9, maxv = -1e9;
char a[5][5];

void Calc(int y, int x, int val) {
    if (y == N - 1 && x == N - 1) {
        minv = min(minv, val);
        maxv = max(maxv, val);
        return;
    }

    for (int i = 0; i < 2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= N || nx >= N) continue;

        int nv = val;

        if (a[y][x] == '-')
            nv -= a[ny][nx] - '0';
        else if (a[y][x] == '+')
            nv += a[ny][nx] - '0';
        else if (a[y][x] == '*')
            nv *= a[ny][nx] - '0';

        Calc(ny, nx, nv);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    Calc(0, 0, a[0][0] - '0');

    cout << maxv << " " << minv;
}
