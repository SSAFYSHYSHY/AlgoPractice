#pragma once
#include <iostream>
#include <vector>
using namespace std;

int parent[3001];
int degreeCnt[3001];
int V, E;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
        degreeCnt[i] = 0;
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
        degreeCnt[a]++;
        degreeCnt[b]++;
        edges.push_back({ a,b });
    }

    int root = Find(edges[0].first);
    bool connected = true;
    for (auto& e : edges) {
        if (Find(e.first) != root || Find(e.second) != root) {
            connected = false;
            break;
        }
    }

    int oddCount = 0;
    for (int i = 1; i <= V; i++) {
        if (degreeCnt[i] % 2 == 1) oddCount++;
    }

    if (connected && (oddCount == 0 || oddCount == 2))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}