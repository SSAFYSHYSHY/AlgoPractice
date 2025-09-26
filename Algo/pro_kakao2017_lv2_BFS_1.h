#pragma once
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int arr[101][101];
bool visited[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int> v;

bool InRange(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({ x,y });

    int cnt = 1;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == arr[x][y]) {
                visited[nx][ny] = true;
                q.push({ nx,ny });
                cnt++;
            }
        }
    }
    v.push_back(cnt);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    N = m; // За
    M = n; // ї­

    memset(arr, 0, sizeof(arr));
    memset(visited, false, sizeof(visited));
    v.clear();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = picture[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && arr[i][j] > 0) {
                BFS(i, j);
            }
        }
    }

    sort(v.begin(), v.end());
    int number_of_area = v.size();
    int max_size_of_one_area = (v.empty() ? 0 : v.back());

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
