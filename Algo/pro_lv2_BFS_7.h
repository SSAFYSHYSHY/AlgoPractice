#pragma once
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool flag = false;
int sx, sy, ex, ey, lx, ly, answer = 0;
bool visited[101][101] = { false, };

struct Node {
    int x, y, dist;
};

bool InRange(int x, int y, int n, int m) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

pair<int, int> BFS_1(int sx, int sy, int lx, int ly, const vector<string>& maps) {
    memset(visited, false, sizeof(visited));
    queue<Node> q;
    q.push({ sx,sy,0 });
    visited[sx][sy] = true;

    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int cdist = q.front().dist;
        q.pop();

        if (cx == lx && cy == ly) {
            answer += cdist;
            return { cx,cy };
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny, maps.size(), maps[0].size()) && !visited[nx][ny] && maps[nx][ny] == 'O') {
                q.push({ nx,ny, cdist + 1 });
                visited[nx][ny] = true;
            }
        }
    }

    return { -1,-1 };
}

int BFS_2(int sx, int sy, int ex, int ey, const vector<string>& maps) {
    queue<Node> q;
    memset(visited, false, sizeof(visited));
    visited[sx][sy] = true;
    q.push({ sx,sy,0 });

    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int cdist = q.front().dist;
        q.pop();

        if (cx == ex && cy == ey) {
            answer += cdist;
            return answer;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny, maps.size(), maps[0].size()) && !visited[nx][ny] && maps[nx][ny] == 'O') {
                q.push({ nx,ny, cdist + 1 });
                visited[nx][ny] = true;
            }
        }
    }

    return -1;
}

int solution(vector<string> maps) {

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'S') {
                sx = i;
                sy = j;
                maps[i][j] = 'O';
            }
            else if (maps[i][j] == 'E') {
                ex = i;
                ey = j;
                maps[i][j] = 'O';
            }
            else if (maps[i][j] == 'L') {
                lx = i;
                ly = j;
                maps[i][j] = 'O';
            }
        }
    }

    tie(sx, sy) = BFS_1(sx, sy, lx, ly, maps);

    if (sx == -1 && sy == -1) return -1;

    answer = BFS_2(sx, sy, ex, ey, maps);

    return answer;
}