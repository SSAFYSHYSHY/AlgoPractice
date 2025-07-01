#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100001;

int N, M, S;
bool visited[MAX];
bool fanclub[MAX];
vector<int> adj[MAX];

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // 리프 노드인데 팬클럽 아님 → 탈출 가능
        if (adj[curr].empty() && !fanclub[curr]) {
            cout << "yes\n";
            exit(0);
        }

        for (int next : adj[curr]) {
            if (!visited[next] && !fanclub[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cin >> S;
    for (int i = 0; i < S; i++) {
        int s;
        cin >> s;
        fanclub[s] = true;
    }

    if (fanclub[1]) {
        cout << "Yes\n";
        return 0;
    }

    BFS(1);
    // 모든 리프 노드가 팬클럽이라면
    cout << "Yes\n";
    return 0;
}
