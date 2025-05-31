#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, q;
vector<pair<int, int>> v[10001];
bool visited[10001];

int BFS(int start, int endi) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    visited[start] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (cx == endi) return dist;

        for (auto next : v[cx]) {
            int nx = next.first;
            int ndist = next.second;

            if (!visited[nx]) {
                visited[nx] = true;
                q.push({ nx, dist + ndist });
            }
        }
    }

    return -1; // 이론상 도달 불가 없음 (문제 조건 상 트리이므로)
}

int main() {
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        v[x].push_back({ y, l });
        v[y].push_back({ x, l });
    }

    for (int i = 0; i < q; i++) {
        int start, endi;
        cin >> start >> endi;
        cout << BFS(start, endi) << '\n';
    }

    return 0;
}
