#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int arr[9][9];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int answer = 0;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

// 그룹 크기 구하기
int BFS_count(int board[9][9], int x, int y, int num, bool visited[9][9]) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;

    int cnt = 1;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == num) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
                cnt++;
            }
        }
    }
    return cnt;
}

// 그룹 제거
void BFS_remove(int board[9][9], int x, int y) {
    int target = board[x][y];
    bool visited[9][9];
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        board[cx][cy] = 0; // 제거

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == target) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
}

// 중력 적용
void AxisDrop(int board[9][9]) {
    int new_arr[9][9];
    memset(new_arr, 0, sizeof(new_arr));

    for (int j = 0; j < m; j++) {
        int idx = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (board[i][j] != 0) {
                new_arr[idx][j] = board[i][j];
                idx--;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = new_arr[i][j];
}

// DFS: 3번 선택
void DFS(int board[9][9], int depth, int score) {
    if (depth == 3) {
        answer = max(answer, score);
        return;
    }

    bool visited[9][9];
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || visited[i][j]) continue;

            int cnt = BFS_count(board, i, j, board[i][j], visited);
            if (cnt == 0) continue;

            int new_board[9][9];
            memcpy(new_board, board, sizeof(new_board));

            BFS_remove(new_board, i, j);
            AxisDrop(new_board);

            DFS(new_board, depth + 1, score + cnt * cnt);
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    DFS(arr, 0, 0);
    cout << answer << "\n";
    return 0;
}
