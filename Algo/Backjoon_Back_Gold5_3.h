#pragma once
#include <iostream>
using namespace std;

int N, M, ans;
int board[26][26];
int dx[3] = { -1, 0, -1 };
int dy[3] = { 0, -1, -1 };

bool check(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (board[nx][ny]) cnt++;
        }
    }
    return cnt != 3;
}

void backtracking(int x, int y) {
    if (x == N - 1 && y == M) {
        ans++;
        return;
    }
    if (y == M) {
        y = 0;
        x++;
    }
    board[x][y] = 1;
    if (check(x, y)) backtracking(x, y + 1);
    board[x][y] = 0;
    backtracking(x, y + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    backtracking(0, 0);
    cout << ans;
}