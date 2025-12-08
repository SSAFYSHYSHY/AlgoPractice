#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

int BFS(int start, int endi, vector<int> v[]) {
    bool visited[21] = { false };

    queue<pair<int, int>> q;
    q.push({ start, 0 });
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (cur == endi) return dist;

        for (int next : v[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push({ next, dist + 1 });
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;

    while (true) {
        vector<int> v[21];

        int x;
        if (!(cin >> x)) break;

        int num = x;
        for (int j = 0; j < num; j++) {
            int to;
            cin >> to;
            v[1].push_back(to);
            v[to].push_back(1);
        }

        for (int i = 2; i <= 19; i++) {
            cin >> num;
            for (int j = 0; j < num; j++) {
                int to;
                cin >> to;
                v[i].push_back(to);
                v[to].push_back(i);
            }
        }

        int m;
        cin >> m;

        cout << "Test Set #" << test << "\n";

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            int ans = BFS(a, b, v);

            cout << setw(2) << a << " to " << setw(2) << b << ": " << ans << "\n";
        }

        cout << "\n";
        test++;
    }

    return 0;
}