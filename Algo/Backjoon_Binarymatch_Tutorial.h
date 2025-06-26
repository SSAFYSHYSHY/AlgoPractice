#pragma once
///HopKraft-Karf ��� �̺и�Ī ���

//���� �밡���� ����� DFS�� ã�� ���ϸ� ������ Ž���� ���� �� Ž�� ����ؾ� �ϴ� ������ ����.
//�װ� ����ϱ� ���� ���.

//BFS + DFS ����.
//�ð� ���⵵ O(Root(v + E)) <- ����.
//�켱 BFS�� ���ƹ��� ���� ���� ���ñǿ� ���ؼ� ������ ���� �̵��� DFS ����.
//�ڷᰡ 10���� �̻󿡼����� ȿ�������� �Ǵ� ����.

//Ʃ�丮��

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1001;

vector<int> adj[MAX];
int pairU[MAX], pairV[MAX], dist[MAX];
int n, m; // ����, ������ ��� ��

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
                found = true; // �� ���� ��Ī ����
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