#pragma once
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 501; // 문제 제한: n ≤ 500

vector<int> v[MAX];
bool visited[MAX];

void reset(int n) {
    for (int i = 1; i <= n; i++) {
        v[i].clear();
    }
    memset(visited, false, sizeof(visited));
}

bool DFS(int node, int parent) {
    visited[node] = true;

    for (int next : v[node]) {
        if (next == parent) continue;

        if (visited[next]) return false;
        if (!DFS(next, node)) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int caseNum = 1;

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        reset(n);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int treeCount = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (DFS(i, 0)) treeCount++;
            }
        }

        cout << "Case " << caseNum++ << ": ";
        if (treeCount == 0) {
            cout << "No trees.\n";
        }
        else if (treeCount == 1) {
            cout << "There is one tree.\n";
        }
        else {
            cout << "A forest of " << treeCount << " trees.\n";
        }
    }

    return 0;
}