#pragma once
//������ ����

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10005;
vector<int> graph[MAX];
vector<pair<int, int>> bridges; // ������ ����

int discovered[MAX]; // DFS �湮 ����
bool visited[MAX];
int counter = 0;

int dfs(int u, int parent) {
    discovered[u] = ++counter;
    int low = discovered[u]; // u���� �� �� �ִ� ���� ���� ����(���� �湮 ��ȣ)

    for (int v : graph[u]) {
        if (v == parent) continue; // �θ�� ����

        if (!discovered[v]) {
            // v�� ���� �湮 �� �� �� DFS ����
            int low_v = dfs(v, u);
            low = min(low, low_v);

            // (u,v)�� ���������� Ȯ��
            if (low_v > discovered[u]) {
                bridges.push_back({ min(u,v), max(u,v) });
            }
        }
        else {
            // �̹� �湮�� ��� �� back edge
            low = min(low, discovered[v]);
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p, c;
    while (true) {
        cin >> p >> c;
        if (p == 0 && c == 0) break;

        // �ʱ�ȭ
        for (int i = 0; i < p; i++) {
            graph[i].clear();
            discovered[i] = 0;
        }
        bridges.clear();
        counter = 0;

        // ���� �Է�
        for (int i = 0; i < c; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // DFS ����
        for (int i = 0; i < p; i++) {
            if (!discovered[i]) {
                dfs(i, -1);
            }
        }

        // �������� �ϳ��� ������ Yes
        if (!bridges.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
}
