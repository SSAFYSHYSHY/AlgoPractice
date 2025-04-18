#pragma once
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

// 방향 정보
char dice[] = { 'd','l','r','u' };
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,-1,1,0 };
bool visited[51][51][2501] = { false, };

int N, M;

bool InRange(int x, int y) {
    return 1 <= x && x <= N && 1 <= y && y <= M;
}

struct Node {
    int x, y, d;
    string dist;
};

// BFS로 사전순 가장 빠른 경로 찾기
string BFS(int s_x, int s_y, int e_x, int e_y, int k) {
    queue<Node> q;
    q.push({ s_x, s_y, 0,"" });
    visited[s_x][s_y][0] = true;

    while (!q.empty()) {
        auto [cx, cy, cdir, path] = q.front();
        q.pop();

        int remain = k - cdir;
        int dist = abs(cx - e_x) + abs(cy - e_y);

        // 남은 거리보다 많이 움직이거나, 도착 불가능한 경우 가지치기
        if (remain < dist || (remain - dist) % 2 != 0) continue;

        // 경로가 k 길이일 때 도착했으면 정답
        if (cdir == k) {
            if (cx == e_x && cy == e_y) return path;
            continue;
        }

        // 사전순 우선 탐색
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny][cdir + 1]) {
                visited[nx][ny][cdir + 1] = true;
                q.push({ nx, ny, cdir + 1,path + dice[i] });
            }
        }
    }

    return "impossible";
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n;
    M = m;

    return BFS(x, y, r, c, k);
}
