#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, q;
vector<int> adj[100001];     // ������
vector<int> rev[100001];     // ������
bool canReachN[100001];      // i���� N���� �� �� �ִ°�
bool visited[100001];        // ���� 1���� ���� �����Ѱ�

void dfsFromN(int curr) {
    canReachN[curr] = true;
    for (int prev : rev[curr]) {
        if (!canReachN[prev]) dfsFromN(prev);
    }
}

void bfsFrom1() {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int next : adj[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    // Step 1: ���� N���� ������ DFS�� ���� ������ ���� ���ϱ�
    dfsFromN(n);

    // Step 2: ���� 1���� ������ BFS�� ���� ������ ���� ���ϱ�
    bfsFrom1();

    // Step 3: ���� ó��
    int cnt;
    cin >> cnt;
    while (cnt--) {
        int tar;
        cin >> tar;

        if (visited[tar] && canReachN[tar]) {
            cout << "Defend the CTP\n";
        }
        else {
            cout << "Destroyed the CTP\n";
        }
    }

    return 0;
}
