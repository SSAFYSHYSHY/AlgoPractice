#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int n, k;

string flip(const string& s, int idx, int k) {
    string res = s;
    for (int i = idx; i < idx + k; ++i) {
        res[i] = (res[i] == 'H') ? 'T' : 'H';
    }
    return res;
}

int BFS(const string& start) {
    string target(start.length(), 'T');

    unordered_map<string, int> dist;
    dist[start] = 0;

    queue<string> q;
    q.push(start);

    while (!q.empty()) {
        string curr = q.front(); q.pop();
        int curr_dist = dist[curr];

        if (curr == target) return curr_dist;

        for (int i = 0; i <= n - k; ++i) {
            string next = flip(curr, i, k);
            if (dist.find(next) == dist.end()) {
                dist[next] = curr_dist + 1;
                q.push(next);
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> k;
    string s;
    cin >> s;

    int result = BFS(s);
    cout << result << "\n";
}
