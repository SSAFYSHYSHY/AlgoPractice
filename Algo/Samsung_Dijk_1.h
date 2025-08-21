#pragma once
//다익스트라 최적화 기법 필요
//해당 정답에서는 다익스트라를 전역으로 설정해서 관리했다고 함.

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

int q;
int n, m, s = 0;          // 시작점
int dist[2001];
vector<pair<int, int>> v[2001];

struct Node {
    int revenue, dest;
};

unordered_map<int, Node> pack; // id → (revenue, dest)

struct Node2 {
    int x, cost;

    bool operator>(const Node2& other) const {
        return cost > other.cost;
    }
};

void Dijk(int sx) {
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;

    priority_queue<Node2, vector<Node2>, greater<>> pq;
    pq.push({ sx,0 });
    dist[sx] = 0;

    while (!pq.empty()) {
        int cx = pq.top().x;
        int ccost = pq.top().cost;
        pq.pop();

        if (ccost > dist[cx]) continue;

        for (auto& edge : v[cx]) {
            int nx = edge.first;
            int ncost = edge.second;

            if (dist[nx] > dist[cx] + ncost) {
                dist[nx] = dist[cx] + ncost;
                pq.push({ nx, dist[nx] });
            }
        }
    }
}

void Input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        v[i].clear();
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        v[x].push_back({ y,cost });
        v[y].push_back({ x,cost });
    }

    // 지도 입력 끝났으니 다익스트라 실행
    Dijk(s);
}

void Input2() {
    int id, reven, dest;
    cin >> id >> reven >> dest;
    pack[id] = { reven ,dest };
}

void Del() {
    int x;
    cin >> x;
    pack.erase(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--) {
        int x;
        cin >> x;

        if (x == 100) {
            Input();
        }
        else if (x == 200) {
            Input2();
        }
        else if (x == 300) {
            Del();
        }
        else if (x == 400) {
            int ans = -1, ans_idx = -1;

            for (auto& it : pack) {
                int id = it.first;
                auto& info = it.second;

                int reven = info.revenue;
                int dest = info.dest;

                if (dist[dest] == INT_MAX) continue; // 도달 불가
                if (dist[dest] > reven) continue;    // 적자

                int profit = reven - dist[dest];

                if ((profit > ans) || (profit == ans && id < ans_idx)) {
                    ans = profit;
                    ans_idx = id;
                }
            }

            if (ans_idx == -1) {
                cout << -1 << "\n";
            }
            else {
                cout << ans_idx << "\n";
                pack.erase(ans_idx);
            }
        }
        else if (x == 500) {
            int new_s;
            cin >> new_s;
            s = new_s;
            Dijk(s); // 출발지가 바뀌었으니 다시 다익스트라
        }
    }
}
