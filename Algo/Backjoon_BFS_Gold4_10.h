#pragma once


#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int n;
map<pair<int, int>, set<pair<int, int>>> adj;
map<pair<int, int>, bool> visited;

bool BFS(pair<int, int> start) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> comp;
    visited[start] = true;
    q.push(start);

    bool valid = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        comp.push_back(cur);

        for (auto nxt : adj[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }

    for (auto& node : comp) {
        if (adj[node].size() != 2) {
            valid = false;
            break;
        }
    }

    return valid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    map<pair<int, int>, map<pair<int, int>, int>> edgeCount;

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pair<int, int> u = { a,b }, v = { c,d };

        if (u == v) continue;

        edgeCount[u][v]++;
        edgeCount[v][u]++;

        adj[u].insert(v);
        adj[v].insert(u);
    }

    int ans = 0;
    for (auto& it : adj) {
        if (!visited[it.first]) {
            if (BFS(it.first)) ans++;
        }
    }

    cout << ans << "\n";
}
