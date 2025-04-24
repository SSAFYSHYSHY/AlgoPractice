#pragma once
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool visited[101][101];
int s_x, s_y, e_x, e_y;

struct Node {
    int x, y, dist;
};

bool InRange(int x, int y, int n, int m) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int BFS(int sx, int sy, int ex, int ey, const vector<string>& board) {
    memset(visited, false, sizeof(visited));
    queue<Node> q;
    q.push({ sx,sy,0 });
    visited[sx][sy] = true;

    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int cdist = q.front().dist;
        q.pop();

        if (cx == ex && cy == ey) {
            return cdist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx, ny = cy;

            while (InRange(nx + dx[i], ny + dy[i], board.size(), board[0].size()) && board[nx + dx[i]][ny + dy[i]] != 'D') {
                nx += dx[i];
                ny += dy[i];
            }

            if (!visited[nx][ny]) {
                q.push({ nx,ny,cdist + 1 });
                visited[nx][ny] = true;
            }
        }
    }

    return -1;
}

int solution(vector<string> board) {
    int answer = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'R') { s_x = i, s_y = j; board[s_x][s_y] = '.'; }
            else if (board[i][j] == 'G') { e_x = i, e_y = j; board[e_x][e_y] = '.'; }
        }
    }

    answer = BFS(s_x, s_y, e_x, e_y, board);

    return answer;
}