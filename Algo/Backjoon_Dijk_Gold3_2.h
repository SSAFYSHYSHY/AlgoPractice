#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int N, M, tg, tb, X, B;

char board[1001][1001];
int dist[1001][1001];

struct Node {
    int x, y, cost;

    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

vector<Node> virusArr;

bool InRange(int x, int y) {
    return x >= 0 && x < N&& y >= 0 && y < M;
}

vector<Node> BFS() {
    priority_queue<Node, vector<Node>, greater<>> pq;

    for (const auto& v : virusArr) {
        pq.push({ v.x, v.y, 0 });
        dist[v.x][v.y] = 0;
    }

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (dist[cur.x][cur.y] < cur.cost) continue;

        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (!InRange(nx, ny)) continue;

            //가고자 하는 . 에 대해서 cost + 1 < dist[nx][ny], cost + 1 <= tg 인 경우. 
            if (board[nx][ny] == '.' && dist[nx][ny] > dist[cur.x][cur.y] + 1 && dist[cur.x][cur.y] + 1 <= tg) {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                pq.push({ nx, ny, dist[nx][ny] });
            }
            //가고자 하는 # 위치에 대해서 (tb + 1) + cost 로 그냥 확 증가시켜서 거기서 부터 비교할 수 있도록.
            else if (board[nx][ny] == '#' && dist[nx][ny] > dist[cur.x][cur.y] + (tb + 1) && dist[cur.x][cur.y] + (tb + 1) <= tg) {
                dist[nx][ny] = dist[cur.x][cur.y] + (tb + 1);
                pq.push({ nx, ny, dist[nx][ny] });
            }
        }
    }

    vector<Node> result;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (dist[i][j] == INF) {
                result.push_back({ i + 1, j + 1, 0 });
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cin >> tg >> tb >> X >> B;

    virusArr.resize(X);
    int idx = 0;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < M; ++j) {
            board[i][j] = s[j];
            dist[i][j] = INF;

            if (board[i][j] == '*') {
                virusArr[idx++] = { i, j, 0 };
            }
        }
    }

    auto result = BFS();

    sort(result.begin(), result.end(), [](const Node& a, const Node& b) {
        if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
        });

    if (result.empty()) {
        cout << -1 << '\n';
    }
    else {

        for (const auto& pos : result) {
            cout << pos.x << " " << pos.y << '\n';
        }
    }

    return 0;
}
