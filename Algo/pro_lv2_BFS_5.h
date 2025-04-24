#pragma once
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[101][101] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int> answer;

bool InRange(int x, int y, int n, int m) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS(int x, int y, vector<string> maps) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    int sum = (int)(maps[x][y] - '0');

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny, maps.size(), maps[0].size()) && !visited[nx][ny] && maps[nx][ny] != 'X') {
                q.push({ nx,ny });
                visited[nx][ny] = true;
                sum += (int)(maps[nx][ny] - '0');
            }
        }
    }

    answer.push_back(sum);
}

vector<int> solution(vector<string> maps) {

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (!visited[i][j] && maps[i][j] != 'X') {
                BFS(i, j, maps);
            }
        }
    }
    sort(answer.begin(), answer.end());

    if (answer.empty()) {
        return { -1 };
    }

    return answer;
}