#pragma once
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int N;
map<string, vector<string>> graph;

bool isConnect(const string& x, const string& y) {
    map<string, bool> visited;
    queue<string> q;

    q.push(x);
    visited[x] = true;

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        for (const string& next : graph[cur]) {
            if (visited[next]) continue;
            if (next == y) return true;

            visited[next] = true;
            q.push(next);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    string A, B;
    while (--N) {
        cin >> A >> B;
        graph[B].push_back(A);
    }

    cin >> A >> B;
    cout << (isConnect(B, A) || isConnect(A, B));
    return 0;
}
