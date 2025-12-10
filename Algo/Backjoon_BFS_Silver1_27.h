#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int t;
int c, m;
vector<pair<int, int>> v[100001];
bool visited[100001];

int BFS(int start) {
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    visited[start] = true;

    int maxi = 0;

    while (!q.empty()) {
        int curr = q.front().first;
        int cost = q.front().second;
        q.pop();

        maxi = max(maxi, cost);

        for (auto& nx : v[curr]) {
            int next = nx.first;
            int dist = nx.second;

            if (!visited[next]) {
                visited[next] = true;
                q.push({ next, cost + dist });
            }
        }
    }

    return maxi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {

        cin >> c >> m;

        for (int i = 1; i <= c; i++) {
            v[i].clear();
        }

        for (int i = 0; i < c - 1; i++) {
            int x, y, dist;
            cin >> x >> y >> dist;
            v[x].push_back({ y, dist });
        }

        memset(visited, false, sizeof(visited));
        int result = BFS(1);

        if (result >= m) cout << result << "\n";
        else cout << -1 << "\n";
    }
}