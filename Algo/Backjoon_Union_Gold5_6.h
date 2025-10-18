#pragma once
#include <iostream>
#include <vector>
using namespace std;

int findParent(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent) {
    int pa = findParent(a, parent);
    int pb = findParent(b, parent);
    if (pa != pb) parent[pb] = pa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<vector<int>> graph(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> graph[i][j];
            }
        }

        vector<int> parent(N);
        for (int i = 0; i < N; i++) parent[i] = i;

        // ���Ͽ� ���ε�� ���� ���� ����
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (graph[i][j] == 1) {
                    unite(i, j, parent);
                }
            }
        }

        // ������ ��ǥ(parent)�� �� ������ ����
        vector<int> visited(N, 0);
        int component_count = 0;
        for (int i = 0; i < N; i++) {
            int p = findParent(i, parent);
            if (visited[p] == 0) {
                visited[p] = 1;
                component_count++;
            }
        }

        // �ּ� ���� �� = N - component_count
        cout << (N - component_count) << "\n";
    }
    return 0;
}
