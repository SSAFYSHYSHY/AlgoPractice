#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

struct Node {
    int x, y;
    double time; // 누적 시간
    double water; // 현재 수위
    bool operator>(const Node& other) const {
        return time > other.time;
    }
};

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ceiling[101][101], floorHeight[101][101];
double dist[101][101];
int n, m, h;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void Solve(int tc) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = 1e18;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({ 0,0,0.0,(double)h });
    dist[0][0] = 0.0;

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        int x = cur.x, y = cur.y;
        double t = cur.time, w = cur.water;

        if (dist[x][y] < t) continue;
        if (x == n - 1 && y == m - 1) {
            cout << "Case #" << tc << ": " << fixed << setprecision(6) << t << "\n";
            return;
        }

        int cf = floorHeight[x][y];
        int cc = ceiling[x][y];

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!InRange(nx, ny)) continue;

            int nf = floorHeight[nx][ny];
            int nc = ceiling[nx][ny];

            // 이동 가능 조건
            if (nc - nf < 50) continue;
            if (nc - cf < 50) continue;
            if (cc - nf < 50) continue;

            // 현재 이동 시작 시 수위와 다음 칸 천장과 비교
            double wait = 0.0;
            double curWater = w;
            if (curWater > nc - 50) {
                wait = (curWater - (nc - 50)) / 10.0;
                curWater = nc - 50;
            }

            // 이동 시간 계산
            double depth = curWater - cf; // 현재 칸에서의 수심
            double moveTime;
            if (t == 0.0 && wait == 0.0) moveTime = 0.0;
            else moveTime = (depth >= 20.0) ? 1.0 : 10.0;

            double newTime = t + wait + moveTime;
            double newWater = curWater - moveTime * 10.0; // 이동 후 수위 감소

            if (dist[nx][ny] > newTime) {
                dist[nx][ny] = newTime;
                pq.push({ nx, ny, newTime, newWater });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> h >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> ceiling[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> floorHeight[i][j];

        Solve(tc);
    }
}