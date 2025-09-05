#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        unordered_map<string, vector<string>> adj;
        vector<string> order; // 입력 순서 기억

        for (int i = 0; i < n; i++) {
            string line;
            cin >> line; // 예: "icpc:weissblume,sisobus."
            string group, member;
            int pos = line.find(':');
            group = line.substr(0, pos);
            order.push_back(group);

            string rest = line.substr(pos + 1);
            // 마지막 '.' 제거
            if (rest.back() == '.') rest.pop_back();

            stringstream ss(rest);
            while (getline(ss, member, ',')) {
                adj[group].push_back(member);
            }
        }

        string start = order[0];
        unordered_set<string> visited;
        int ans = 0;

        queue<string> q;
        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            string cur = q.front(); q.pop();

            // 만약 cur가 adj에 없으면 "사람" 노드
            if (adj.find(cur) == adj.end()) {
                ans++;
                continue;
            }

            for (auto& nxt : adj[cur]) {
                if (!visited.count(nxt)) {
                    visited.insert(nxt);
                    q.push(nxt);
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}