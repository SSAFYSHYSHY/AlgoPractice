#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, k, ans = INT_MAX;
int arr[51][51];
int dist[51][51];

struct Node {
    int x, y;
    int num;
    int cost;

    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int Dijk() {
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + n, INT_MAX);

    priority_queue<Node, vector<Node>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                pq.push({ i,j,1,0 });
                dist[i][j] = 0;
            }
        }
    }


    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int cx = cur.x, cy = cur.y, cnum = cur.num, ccost = cur.cost;

        if (cnum == k) return ccost;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == cnum + 1) {
                    int ncost = abs(cx - i) + abs(cy - j);
                    if (dist[i][j] > ccost + ncost) {
                        dist[i][j] = ccost + ncost;
                        pq.push({ i, j, cnum + 1, dist[i][j] });
                    }
                }
            }
        }
    }

    return INT_MAX;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    ans = Dijk();

    cout << (ans == INT_MAX ? -1 : ans);
}
