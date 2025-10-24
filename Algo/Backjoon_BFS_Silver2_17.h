#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[5001];
bool visited[5001];
int parent[5001];  // ��� ������

int p, ns, t;

void BFS() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    parent[1] = -1; // �������� �θ� ����

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == t) break; // ������ ���� �� �ߴ�

        for (int next : v[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = curr; // curr �� next
                q.push(next);
            }
        }
    }

    // ��� ����
    if (!visited[t]) {
        cout << -1 << "\n"; // ���� �Ұ���
        return;
    }

    vector<int> path;
    for (int node = t; node != -1; node = parent[node])
        path.push_back(node);

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int x : path)
        cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> p >> ns >> t;

    for (int i = 0; i < ns; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back(b);
        v[a].push_back(c);

        // ����� �׷��� (�������� "split" ��������, ��� Ž���� ������� �ʿ�)
        v[b].push_back(a);
        v[c].push_back(a);
    }

    BFS();
}