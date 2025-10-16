#pragma once
#include <iostream>
#include <vector>
using namespace std;

int parent[1001];

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 1; i <= N; i++)
            parent[i] = i;

        bool cycle = false;

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            if (!Union(a, b)) cycle = true;
        }

        int root = Find(1);
        bool connected = true;
        for (int i = 2; i <= N; i++) {
            if (Find(i) != root) {
                connected = false;
                break;
            }
        }

        if (!cycle && connected && M == N - 1)
            cout << "tree\n";
        else
            cout << "graph\n";
    }

    return 0;
}
