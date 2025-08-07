#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <climits>

using namespace std;

const int GRID_SIZE = 8;
const int INF = INT_MAX;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(const vector<string>& grid) {
    vector<vector<int>> dist(GRID_SIZE, vector<int>(GRID_SIZE, INF));
    deque<pair<int, int>> dq;

    int sx, sy, ex, ey;

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }

    dist[sx][sy] = 0;
    dq.push_front({ sx, sy });

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= GRID_SIZE || ny >= GRID_SIZE) continue;

            int cost = (grid[nx][ny] == 'M') ? 1 : 0;
            if (dist[nx][ny] > dist[x][y] + cost) {
                dist[nx][ny] = dist[x][y] + cost;
                if (cost == 0) {
                    dq.push_front({ nx, ny });
                }
                else {
                    dq.push_back({ nx, ny });
                }
            }
        }
    }

    return dist[ex][ey];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<string>> inputs;
    vector<string> currentGrid;
    string line;

    while (getline(cin, line)) {
        if (line == "-") {
            if (!currentGrid.empty()) {
                inputs.push_back(currentGrid);
                currentGrid.clear();
            }
        }
        else {
            currentGrid.push_back(line);
        }
    }

    if (!currentGrid.empty()) {
        inputs.push_back(currentGrid);
    }

    for (const auto& grid : inputs) {
        int result = bfs(grid);
        cout << result << "\n";
    }

    return 0;
}
