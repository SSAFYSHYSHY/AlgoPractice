#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

struct Edge {
    int to;
    double cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(2);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<tuple<int, int, int>> stones; // a, b, h
        map<int, int> nodeMap; // 길이 -> 노드 번호
        int nodeCnt = 0;

        for (int i = 0; i < n; i++) {
            int a, b, h;
            cin >> a >> b >> h;
            stones.push_back({ a,b,h });
            if (!nodeMap.count(a)) nodeMap[a] = nodeCnt++;
            if (!nodeMap.count(b)) nodeMap[b] = nodeCnt++;
        }

        int sLength, eLength;
        cin >> sLength >> eLength;
        if (!nodeMap.count(sLength)) nodeMap[sLength] = nodeCnt++;
        if (!nodeMap.count(eLength)) nodeMap[eLength] = nodeCnt++;

        int N = nodeCnt; // 실제 노드 개수
        vector<vector<Edge>> graph(N);

        for (auto [a, b, h] : stones) {
            int u = nodeMap[a];
            int v = nodeMap[b];
            double cost = ((double)a + (double)b) / 2.0 * h * 0.02;
            graph[u].push_back({ v, cost });
            graph[v].push_back({ u, cost }); // 양방향
        }

        int s = nodeMap[sLength];
        int e = nodeMap[eLength];

        // 다익스트라
        vector<double> dist(N, 1e18);
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
        dist[s] = 0;
        pq.push({ 0.0, s });

        while (!pq.empty()) {
            auto [curCost, u] = pq.top(); pq.pop();
            if (curCost > dist[u]) continue;

            for (auto& edge : graph[u]) {
                int v = edge.to;
                double ncost = edge.cost;
                if (dist[v] > dist[u] + ncost) {
                    dist[v] = dist[u] + ncost;
                    pq.push({ dist[v], v });
                }
            }
        }

        cout << dist[e] << "\n";
    }
}
