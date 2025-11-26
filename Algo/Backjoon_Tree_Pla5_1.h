#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 40001;
const int LOG = 16; // 2^15 = 32768, 2^16 = 65536

vector<pair<int, int>> adj[MAX];
int parent[MAX][LOG];
int depth[MAX];
int distSum[MAX];
int n, m;

void dfs(int cur, int par, int d, int dist) {
    parent[cur][0] = par;
    depth[cur] = d;
    distSum[cur] = dist;

    for (auto& nx : adj[cur]) {
        int next = nx.first;
        int cost = nx.second;
        if (next == par) continue;
        dfs(next, cur, d + 1, dist + cost);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    // 1) 깊이를 맞춘다
    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++)
        if (diff & (1 << i))
            a = parent[a][i];

    if (a == b) return a;

    // 2) 같이 위로 올린다
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({ y,w });
        adj[y].push_back({ x,w });
    }

    // 트리 루트는 1로 잡음
    dfs(1, 0, 0, 0);

    // LCA parent DP
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
        }
    }

    cin >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        int c = lca(a, b);
        int ans = distSum[a] + distSum[b] - 2 * distSum[c];

        cout << ans << "\n";
    }
}