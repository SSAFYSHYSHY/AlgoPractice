#pragma once
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
vector<pair<int, int>> adj[MAX]; // (다음 노드, 간선 번호)
long long W[MAX];
long long sub[MAX]; // 서브트리 합
bool visited[MAX];
long long total;
int N;

struct Result {
    long long diff;
    int u, v;
};
Result answer = { LLONG_MAX, -1, -1 };

void dfs(int u, int parent) {
    sub[u] = W[u];
    visited[u] = true;

    for (auto [v, idx] : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        sub[u] += sub[v];

        // u-v 간선을 끊으면 v 쪽 서브트리 합이 sub[v]
        long long diff = llabs(total - 2 * sub[v]);
        if (diff < answer.diff) {
            answer = { diff, u, v };
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({ v, i });
        adj[v].push_back({ u, i });
    }

    total = 0;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
        total += W[i];
    }

    dfs(1, -1);

    cout << answer.diff << "\n";
    cout << answer.u << " " << answer.v << "\n";
}
