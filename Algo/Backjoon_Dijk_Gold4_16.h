#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX 100001
#define INF 1e9

using namespace std;

int N, M, X, Y, Z;
vector<pair<int, int>> v[MAX];
int dist[3][MAX];

void Input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        dist[0][i] = INF;
        dist[1][i] = INF;
        dist[2][i] = INF;
    }
    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        v[U].push_back({ V, W });
    }
    cin >> X >> Y >> Z;
}

void Dijk(int I, int S, int ban) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[I][S] = 0;
    pq.push({ 0, S });

    while (!pq.empty()) {
        int ccost = pq.top().first;
        int cx = pq.top().second;
        pq.pop();

        if (dist[I][cx] < ccost) continue;

        for (auto& e : v[cx]) {
            int nx = e.first;
            int ncost = e.second;
            if (nx == ban) continue; // 금지된 정점 제외
            if (dist[I][nx] > ccost + ncost) {
                dist[I][nx] = ccost + ncost;
                pq.push({ dist[I][nx], nx });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Input();

    Dijk(0, X, -1); // X → Y
    Dijk(1, Y, -1); // Y → Z
    Dijk(2, X, Y);  // X → Z (Y 제외)

    if (dist[0][Y] != INF && dist[1][Z] != INF) cout << dist[0][Y] + dist[1][Z] << " ";
    else cout << -1 << " ";

    if (dist[2][Z] != INF) cout << dist[2][Z];
    else cout << -1;

    return 0;
}
