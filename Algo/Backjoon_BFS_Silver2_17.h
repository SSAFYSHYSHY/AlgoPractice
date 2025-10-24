#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[5001];
bool visited[5001];
int parent[5001];  // 경로 추적용

int p, ns, t;

void BFS() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    parent[1] = -1; // 시작점은 부모 없음

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == t) break; // 목적지 도달 시 중단

        for (int next : v[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = curr; // curr → next
                q.push(next);
            }
        }
    }

    // 경로 복원
    if (!visited[t]) {
        cout << -1 << "\n"; // 도달 불가능
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

        // 양방향 그래프 (문제에서 "split" 구조지만, 경로 탐색은 양방향이 필요)
        v[b].push_back(a);
        v[c].push_back(a);
    }

    BFS();
}