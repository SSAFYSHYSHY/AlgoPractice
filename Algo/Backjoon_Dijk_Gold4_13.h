#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <climits>
#include <unordered_map>
#include <cstring>

using namespace std;

vector<pair<int, int>> graph[501]; // int 인덱스 사용
unordered_map<string, int> nameToIdx; // 마을 이름 → 번호
int p, n;
string startName, endName;
int nodeCount; // 마을 번호 개수 카운트

int getId(const string& name) {
    if (nameToIdx.count(name)) return nameToIdx[name];
    return nameToIdx[name] = ++nodeCount;
}

void Input() {
    cin >> n >> startName >> endName;
    nameToIdx.clear();
    nodeCount = 0;
    for (int i = 0; i <= 500; i++) graph[i].clear();

    for (int i = 0; i < n; i++) {
        string x, y;
        int d;
        cin >> x >> y >> d;
        int a = getId(x);
        int b = getId(y);
        graph[a].push_back({ b, d });
        graph[b].push_back({ a, d });
    }
}

int dijkstra(int s, int t) {
    vector<int> dist(nodeCount + 1, 1e9);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, s });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (cost > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > cost + w) {
                dist[v] = cost + w;
                pq.push({ dist[v], v });
            }
        }
    }
    return dist[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> p;
    while (p--) {
        Input();
        int s = getId(startName);
        int t = getId(endName);
        int ans = dijkstra(s, t);
        cout << startName << " " << endName << " " << ans << "\n";
    }
}
