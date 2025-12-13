#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
bool visited[10];
vector<pair<int, int>> vec[10];
vector<int> ans;
vector<int> tmp;
int smallest = 5000001;
int cnt = 1;

void func(int pos, int cost) {
    if (visited[1] && pos == 1) {
        if (smallest > cost) {
            ans = tmp;
            smallest = cost;
        }
        return;
    }
    tmp.push_back(pos);
    visited[pos] = true;
    for (auto i : vec[pos]) {
        if (!visited[i.first] || (cnt == n && i.first == 1)) {
            cnt++;
            func(i.first, max(cost, i.second));
            cnt--;
        }
    }
    tmp.pop_back();
    visited[pos] = false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        vec[u].push_back({ v,c });
    }
    func(1, 0);
    if (smallest == 5000001) {
        cout << -1;
    }
    else {
        cout << smallest << "\n";
        for (auto i : ans) {
            cout << i << " ";
        }
    }
}