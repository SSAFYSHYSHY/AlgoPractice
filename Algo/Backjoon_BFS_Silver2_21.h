#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

int BFS(int start, vector<vector<int>>& v) {
    vector<bool> visited(v.size(), false);
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    visited[start] = true;

    int cnt = 0;

    while (!q.empty()) {
        int curr = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (dist == 2) continue; // 2단계까지만 허용

        for (int next : v[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                cnt++;
                q.push({ next, dist + 1 });
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        int n, m;
        cin >> n >> m;

        unordered_map<string, int> idx;
        vector<vector<int>> v(n + 1);
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;

            if (idx.find(a) == idx.end()) idx[a] = cnt++;
            if (idx.find(b) == idx.end()) idx[b] = cnt++;

            int x = idx[a];
            int y = idx[b];

            v[x].push_back(y);
            v[y].push_back(x);
        }

        string s;
        cin >> s;
        int num = idx[s];

        int ans = BFS(num, v);

        cout << "The number of supervillains in 2-hop neighborhood of " << s << " is " << ans << "\n";
    }

    return 0;
}