#pragma once
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);
    vector<int> dist(n + 1, -1); // �Ÿ� ���� (�湮 �� ������ -1)
    queue<int> q;

    // �׷��� ���� (�����)
    for (auto& e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next : graph[now]) {
            if (dist[next] == -1) { // ���� �湮 �� �� ���
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }

    int max_dist = *max_element(dist.begin(), dist.end());
    return count(dist.begin(), dist.end(), max_dist);
}