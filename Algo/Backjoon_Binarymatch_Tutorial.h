#pragma once
///HopKraft-Karf 방식 이분매칭 기법

//기존 헝가리안 기법은 DFS로 찾지 못하면 기존에 탐색된 것을 재 탐색 재귀해야 하는 단점이 있음.
//그걸 고려하기 위한 방안.

//BFS + DFS 응용.
//시간 복잡도 O(Root(v + E)) <- 빠름.
//우선 BFS를 돌아버린 다음 다음 선택권에 대해서 가지지 못한 이들이 DFS 진행.
//자료가 10만인 이상에서부터 효율적으로 판단 가능.

//튜토리얼

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1001;

vector<int> adj[MAX];
int pairU[MAX], pairV[MAX], dist[MAX];
int n, m; // 왼쪽, 오른쪽 노드 수

bool bfs() {
    queue<int> q;
    for (int u = 1; u <= n; ++u) {
        if (pairU[u] == 0) {
            dist[u] = 0;
            q.push(u);
        }
        else {
            dist[u] = -1;
        }
    }

    bool found = false;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (pairV[v] == 0) {
                found = true; // 더 깊은 매칭 가능
            }
            else if (dist[pairV[v]] == -1) {
                dist[pairV[v]] = dist[u] + 1;
                q.push(pairV[v]);
            }
        }
    }
    return found;
}

bool dfs(int u) {
    for (int v : adj[u]) {
        if (pairV[v] == 0 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
            pairU[u] = v;
            pairV[v] = u;
            return true;
        }
    }
    dist[u] = -1;
    return false;
}

int hopcroft_karp() {
    memset(pairU, 0, sizeof(pairU));
    memset(pairV, 0, sizeof(pairV));
    int result = 0;

    while (bfs()) {
        for (int u = 1; u <= n; ++u) {
            if (pairU[u] == 0 && dfs(u)) {
                result++;
            }
        }
    }
    return result;
}

int main() {
    cin >> n >> m;
    int edges;
    cin >> edges;

    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << hopcroft_karp() << "\n";
}