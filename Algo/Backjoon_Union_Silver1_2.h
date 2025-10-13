#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int parent[10001];
int sz[10001];
int n, m;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 0; i < n; i++) cin >> sz[i];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    for (int i = 0; i < n; i++) {
        if (Find(i) == i) {
            if (sz[i] != 0) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    cout << "POSSIBLE\n";
    return 0;
}
