#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int n;
string start;
vector<int> adj[10001];
unordered_map<string, int> str_to_idx;
unordered_map<int, string> idx_to_str;

int BFS(int starti, int node_count) {
    queue<pair<int, int>> q;
    vector<bool> visited(node_count, false);
    q.push({ starti, 0 });
    visited[starti] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (next == starti) return dist + 1; // µ¹¾Æ¿È
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

    cin >> n >> start;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if (str_to_idx.find(a) == str_to_idx.end()) {
            str_to_idx[a] = cnt;
            idx_to_str[cnt] = a;
            cnt++;
        }
        if (str_to_idx.find(b) == str_to_idx.end()) {
            str_to_idx[b] = cnt;
            idx_to_str[cnt] = b;
            cnt++;
        }

        adj[str_to_idx[a]].push_back(str_to_idx[b]);
    }

    int starti = str_to_idx[start];
    int ans = BFS(starti, cnt);

    if (ans == -1) cout << "NO BLACK HOLE\n";
    else cout << ans << "\n";

    return 0;
}