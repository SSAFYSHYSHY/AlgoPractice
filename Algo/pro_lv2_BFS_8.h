#pragma once
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>


using namespace std;

int BFS(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < graph[curr].size(); i++) {
            if (!visited[graph[curr][i]]) {
                visited[graph[curr][i]] = true;
                q.push(graph[curr][i]);
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> graph(n + 1);

        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue;

            int a = wires[j][0], b = wires[j][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> visited(n + 1, false);
        int part = BFS(1, graph, visited);
        int diff = abs(n - part - part);
        answer = min(answer, diff);
    }

    return answer;
}