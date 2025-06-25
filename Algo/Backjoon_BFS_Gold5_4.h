#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>
#include <cmath>

using namespace std;

const int MAX = 2001;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(const vector<pair<int, int>>& mall1, const vector<vector<bool>>& visited2) {
    vector<vector<int>> dist(MAX, vector<int>(MAX, -1));
    queue<pair<int, int>> q;

    for (auto& [x, y] : mall1) {
        dist[x][y] = 0;
        q.push({ x, y });
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (visited2[x][y]) {
            return dist[x][y];
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
    return INT_MAX;
}

int main() {
    while (true) {
        int p;
        cin >> p;
        if (p == 0) break;

        vector<pair<int, int>> mall1(p);
        for (int i = 0; i < p; ++i) {
            cin >> mall1[i].first >> mall1[i].second;
        }

        cin >> p;
        vector<pair<int, int>> mall2(p);
        for (int i = 0; i < p; ++i) {
            cin >> mall2[i].first >> mall2[i].second;
        }

        vector<vector<bool>> visited2(MAX, vector<bool>(MAX, false));
        for (auto& [x, y] : mall2) {
            visited2[x][y] = true;
        }

        int res = bfs(mall1, visited2);
        cout << res << endl;
    }

    return 0;
}
