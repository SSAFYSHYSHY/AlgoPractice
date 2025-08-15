#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int n, m, b;
vector<pair<int, int>> v[50001];
long long dist1[50001];

void Dijk_from_1() {
    for (int i = 1; i <= n; i++) dist1[i] = LLONG_MAX;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({ 0, 1 });
    dist1[1] = 0;

    while (!pq.empty()) {
        int ccost = pq.top().first;
        int cx = pq.top().second;
        pq.pop();
        if (ccost > dist1[cx]) continue;

        for (auto& [nx, ncost] : v[cx]) {
            if (dist1[nx] > ccost + ncost) {
                dist1[nx] = ccost + ncost;
                pq.push({ dist1[nx], nx });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> b;
    for (int i = 0; i < m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        v[x].push_back({ y, cost });
        v[y].push_back({ x, cost });
    }

    Dijk_from_1();

    while (b--) {
        int s, e;
        cin >> s >> e;

        cout << dist1[s] + dist1[e] << "\n";
    }
}
