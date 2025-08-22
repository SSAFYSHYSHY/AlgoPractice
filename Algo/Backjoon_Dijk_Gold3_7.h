#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int INF = 1000000000;
int n, m;

// �׷��� ���� ����Ʈ (���� ���, ���)
vector<pair<int, int>> adj[201];

// ��� ������ ���̺�
int nextHop[201][201];

void dijkstra(int start) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        int cost = top.first;
        int cur = top.second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (size_t i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur][i].first;
            int w = adj[cur][i].second;
            int newCost = cost + w;

            if (newCost < dist[nxt]) {
                dist[nxt] = newCost;
                pq.push(make_pair(newCost, nxt));

                // ������ ���
                if (cur == start) nextHop[start][nxt] = nxt;
                else nextHop[start][nxt] = nextHop[start][cur];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c)); // �����
    }

    // ��� ��忡�� ���ͽ�Ʈ�� ����
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }

    // ��� ���
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "- ";
            else cout << nextHop[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
