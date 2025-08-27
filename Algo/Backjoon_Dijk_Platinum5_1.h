#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e15;

struct Edge {
    int v, w;
};
int N, M;
vector<Edge> adj[1001];

struct Node {
    ll d;
    int v;
    bool operator>(const Node& o) const {
        return d > o.d;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({ b,w });
        adj[b].push_back({ a,w });
    }

    vector<ll> dist1(N + 1, INF), dist2(N + 1, INF);
    priority_queue<Node, vector<Node>, greater<>> pq;
    dist1[1] = 0;
    pq.push({ 0,1 });

    while (!pq.empty()) {
        auto [cd, u] = pq.top(); pq.pop();
        for (auto [v, w] : adj[u]) {
            ll nd = cd + w;
            if (nd < dist1[v]) {
                dist2[v] = dist1[v];
                dist1[v] = nd;
                pq.push({ nd,v });
            }
            else if (nd > dist1[v] && nd < dist2[v]) {
                dist2[v] = nd;
                pq.push({ nd,v });
            }
        }
    }

    cout << dist2[N] << "\n";
}
