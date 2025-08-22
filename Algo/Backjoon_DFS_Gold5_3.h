#pragma once
//단절선 개념

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10005;
vector<int> graph[MAX];
vector<pair<int, int>> bridges; // 단절선 저장

int discovered[MAX]; // DFS 방문 순서
bool visited[MAX];
int counter = 0;

int dfs(int u, int parent) {
    discovered[u] = ++counter;
    int low = discovered[u]; // u에서 갈 수 있는 가장 높은 조상(작은 방문 번호)

    for (int v : graph[u]) {
        if (v == parent) continue; // 부모는 무시

        if (!discovered[v]) {
            // v가 아직 방문 안 됨 → DFS 진행
            int low_v = dfs(v, u);
            low = min(low, low_v);

            // (u,v)가 단절선인지 확인
            if (low_v > discovered[u]) {
                bridges.push_back({ min(u,v), max(u,v) });
            }
        }
        else {
            // 이미 방문한 노드 → back edge
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

        // 초기화
        for (int i = 0; i < p; i++) {
            graph[i].clear();
            discovered[i] = 0;
        }
        bridges.clear();
        counter = 0;

        // 간선 입력
        for (int i = 0; i < c; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // DFS 실행
        for (int i = 0; i < p; i++) {
            if (!discovered[i]) {
                dfs(i, -1);
            }
        }

        // 단절선이 하나라도 있으면 Yes
        if (!bridges.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
}
