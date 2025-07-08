#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1501;
int n, m;
char arr[MAX][MAX];
bool visited[MAX][MAX];
bool melt_visited[MAX][MAX];
queue<pair<int, int>> swan_q, swan_nq;
queue<pair<int, int>> water_q, water_nq;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
pair<int, int> swan1, swan2;

bool inRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool move_swan() {
    while (!swan_q.empty()) {
        auto [x, y] = swan_q.front(); swan_q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];

            if (!inRange(nx, ny) || visited[nx][ny]) continue;
            visited[nx][ny] = true;

            if (arr[nx][ny] == '.') {
                swan_q.push({ nx, ny });
            }
            else if (arr[nx][ny] == 'X') {
                swan_nq.push({ nx, ny });
            }
            else if (make_pair(nx, ny) == swan2) {
                return true;
            }
        }
    }
    return false;
}

void melt() {
    while (!water_q.empty()) {
        auto [x, y] = water_q.front(); water_q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];

            if (!inRange(nx, ny) || melt_visited[nx][ny]) continue;
            if (arr[nx][ny] == 'X') {
                melt_visited[nx][ny] = true;
                arr[nx][ny] = '.';
                water_nq.push({ nx, ny });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;

    bool found = false;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            arr[i][j] = s[j];
            if (arr[i][j] != 'X') {
                water_q.push({ i, j });
                melt_visited[i][j] = true;
            }
            if (arr[i][j] == 'L') {
                if (!found) {
                    swan1 = { i, j };
                    found = true;
                }
                else {
                    swan2 = { i, j };
                }
            }
        }
    }

    swan_q.push(swan1);
    visited[swan1.first][swan1.second] = true;

    int day = 0;
    while (true) {
        if (move_swan()) {
            cout << day << '\n';
            break;
        }
        melt();
        swan_q = swan_nq;
        water_q = water_nq;
        while (!swan_nq.empty()) swan_nq.pop();
        while (!water_nq.empty()) water_nq.pop();
        day++;
    }
}
