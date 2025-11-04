#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 1e9;
int n, m, s;
vector<int> graph[100001];
bool mushroom[100001];
int dist[100001];

int BFS() {
    queue<int> q;
    q.push(1);
    dist[1] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (!mushroom[next]) continue;
            if (dist[next] != INF) continue;

            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
    return dist[n];
}

int main() {
    cin >> n >> m >> s;

    memset(mushroom, false, sizeof(mushroom));
    mushroom[1] = mushroom[n] = true;

    for (int i = 0; i < s - 2; i++) {
        int x;
        cin >> x;
        mushroom[x] = true;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    fill(dist, dist + n + 1, INF);

    int ans = BFS();
    cout << (ans == INF ? -1 : ans) << "\n";
}