#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX = INT_MAX;

int n, m, s, e;
vector<vector<pair<int, int>>> graph;

int Dijkstra(int n, vector<vector<pair<int, int>>>& v, int s, int e) {
    vector<int> dist(n + 1, MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int cost = top.first;
        int now = top.second;

        if (dist[now] < cost) continue;

        for (int i = 0; i < v[now].size(); ++i) {
            int next = v[now][i].first;
            int weight = v[now][i].second;
            int nextCost = dist[now] + weight;

            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push(make_pair(nextCost, next));
            }
        }
    }

    return dist[e];
}

void Input() {
    cin >> n >> m >> s >> e;
    graph.assign(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
}

int main() {
    Input();
    int ans = Dijkstra(n, graph, s, e);
    cout << ans << endl;
    return 0;
}
