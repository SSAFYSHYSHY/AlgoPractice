#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m;

// 간선 목록
pair<int, int> edge[30];

// 각 노드에 연결된 간선 ID 저장 (당신의 v 배열을 이런 구조로 사용)
vector<int> v[27];

// 간선 방문 여부
bool used[30];

int DFS(int idx) {
    int ret = 0;

    for (int e : v[idx]) {
        if (!used[e]) {
            used[e] = true;

            int a = edge[e].first;
            int b = edge[e].second;
            int next = (idx == a ? b : a);

            ret = max(ret, 1 + DFS(next));

            used[e] = false;
        }
    }

    return ret;
}

int main() {
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++) v[i].clear();

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;

            edge[i] = { x, y };

            // 간선 ID(i)를 각 노드에 저장
            v[x].push_back(i);
            v[y].push_back(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            memset(used, false, sizeof(used));
            ans = max(ans, DFS(i));
        }

        cout << ans << "\n";
    }
}
