#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAXT = 3600;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;
    while (TC--) {
        int n, tar;
        cin >> n >> tar;
        vector<int> dx(n);
        for (int i = 0; i < n; ++i) cin >> dx[i];

        vector<int> dist(MAXT + 1, INF);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int b : dx) {
                int next = cur + b;
                if (next < 0) next = 0;
                if (next > MAXT) next = MAXT;
                if (dist[next] == INF) {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }

        if (dist[tar] != INF) {
            cout << dist[tar] << " " << 0 << "\n";
        }
        else {
            int i;
            for (i = tar; i <= MAXT; ++i) {
                if (dist[i] != INF) break;
            }
            cout << dist[i] << " " << (i - tar) << "\n";
        }
    }
    return 0;
}