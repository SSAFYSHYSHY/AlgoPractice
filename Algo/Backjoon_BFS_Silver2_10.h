#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    if (!(cin >> R >> C)) return 0;

    vector<vector<int>> a(R, vector<int>(C));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> a[i][j];

    vector<vector<char>> vis(R, vector<char>(C, 0));
    int islands = 0;

    // 8방향(상, 하, 좌, 우, 대각선 4개)
    int dx[8] = { -1,-1,-1,0,0,1,1,1 };
    int dy[8] = { -1,0,1,-1,1,-1,0,1 };

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            // 고도 > 0 이고 아직 방문하지 않았다면 새로운 섬 발견
            if (a[i][j] > 0 && !vis[i][j]) {
                ++islands;
                queue<pair<int, int>> q;
                q.push({ i,j });
                vis[i][j] = 1;

                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (int d = 0; d < 8; ++d) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                            if (!vis[nx][ny] && a[nx][ny] > 0) {
                                vis[nx][ny] = 1;
                                q.push({ nx, ny });
                            }
                        }
                    }
                }
            }
        }
    }

    cout << islands << '\n';
    return 0;
}