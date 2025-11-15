#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int K, N, M;
vector<int> adj[1001];
bool reachable[1001][101];
int cow[101];

void bfs(int cow_idx) {
    int start = cow[cow_idx];
    queue<int> q;
    q.push(start);
    reachable[start][cow_idx] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int next : adj[cur]) {
            if (!reachable[next][cow_idx]) {
                reachable[next][cow_idx] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> K >> N >> M;

    for (int i = 0; i < K; i++) {
        cin >> cow[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 0; i < K; i++) {
        bfs(i);
    }

    int ans = 0;
    for (int pasture = 1; pasture <= N; pasture++) {
        bool ok = true;
        for (int i = 0; i < K; i++) {
            if (!reachable[pasture][i]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }

    cout << ans << "\n";

    return 0;
}