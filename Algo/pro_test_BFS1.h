#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

struct Node {
    int rx, ry, bx, by, cnt;
    bool red_done, blue_done;
    bool red_visited[4][4];
    bool blue_visited[4][4];
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int n, m;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int solution(vector<vector<int>> maze) {
    n = maze.size();
    m = maze[0].size();

    int rsx, rsy, rex, rey;
    int bsx, bsy, bex, bey;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 1) rsx = i, rsy = j;
            if (maze[i][j] == 2) bsx = i, bsy = j;
            if (maze[i][j] == 3) rex = i, rey = j;
            if (maze[i][j] == 4) bex = i, bey = j;
        }
    }

    bool visited[4][4][4][4] = { false };
    queue<Node> q;
    Node start;
    start.rx = rsx; start.ry = rsy;
    start.bx = bsx; start.by = bsy;
    start.cnt = 0;
    start.red_done = false;
    start.blue_done = false;
    memset(start.red_visited, 0, sizeof(start.red_visited));
    memset(start.blue_visited, 0, sizeof(start.blue_visited));
    start.red_visited[rsx][rsy] = true;
    start.blue_visited[bsx][bsy] = true;

    q.push(start);
    visited[rsx][rsy][bsx][bsy] = true;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        if (cur.red_done && cur.blue_done) return cur.cnt;

        for (int i = 0; i < 4; i++) {
            int nrx = cur.rx, nry = cur.ry;
            bool red_ok = cur.red_done;

            if (!cur.red_done) {
                int tx = cur.rx + dx[i], ty = cur.ry + dy[i];
                if (InRange(tx, ty) && maze[tx][ty] != 5 && !cur.red_visited[tx][ty]) {
                    nrx = tx; nry = ty;
                    red_ok = (nrx == rex && nry == rey);
                }
                else continue;
            }

            for (int j = 0; j < 4; j++) {
                int nbx = cur.bx, nby = cur.by;
                bool blue_ok = cur.blue_done;

                if (!cur.blue_done) {
                    int tx = cur.bx + dx[j], ty = cur.by + dy[j];
                    if (InRange(tx, ty) && maze[tx][ty] != 5 && !cur.blue_visited[tx][ty]) {
                        nbx = tx; nby = ty;
                        blue_ok = (nbx == bex && nby == bey);
                    }
                    else continue;
                }

                if (nrx == nbx && nry == nby) continue;
                if (nrx == cur.bx && nry == cur.by && nbx == cur.rx && nby == cur.ry) continue;

                if (!visited[nrx][nry][nbx][nby]) {
                    visited[nrx][nry][nbx][nby] = true;
                    Node next;
                    next.rx = nrx; next.ry = nry;
                    next.bx = nbx; next.by = nby;
                    next.cnt = cur.cnt + 1;
                    next.red_done = red_ok;
                    next.blue_done = blue_ok;
                    memcpy(next.red_visited, cur.red_visited, sizeof(next.red_visited));
                    memcpy(next.blue_visited, cur.blue_visited, sizeof(next.blue_visited));
                    next.red_visited[nrx][nry] = true;
                    next.blue_visited[nbx][nby] = true;
                    q.push(next);
                }
            }
        }
    }

    return 0;
}