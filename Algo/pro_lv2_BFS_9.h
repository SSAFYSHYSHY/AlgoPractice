#pragma once
//그룹화 BFS 를 이루고 그 다음 그룹끼리의 조건을 연산하는게 더 빠르다.
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[501][501] = { false, };
vector<vector<int>> temp;
vector<vector<int>> group;
int arr[250001];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
    return (0 <= x && x < temp.size() && 0 <= y && y < temp[0].size());
}

void BFS(int x, int y, int idx) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    group[x][y] = idx;
    int cnt = 1;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny] && temp[nx][ny] == 1) {
                cnt++;
                q.push({ nx,ny });
                group[nx][ny] = idx;
                visited[nx][ny] = true;
            }
        }
    }

    arr[idx] = cnt;
}

void Calc() {
    int idx = 1;
    group = vector<vector<int>>(temp.size(), vector<int>(temp[0].size(), 0)); // 반드시 초기화
    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < temp[0].size(); j++) {
            if (!visited[i][j] && temp[i][j] == 1) {
                BFS(i, j, idx);
                idx++;
            }
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    temp = land;

    Calc(); // 그룹화

    for (int j = 0; j < land[0].size(); j++) {
        int sum = 0;
        int copy_num = -1;  // 그룹 번호 체크

        bool group_checked[250001] = { false, };

        for (int i = 0; i < land.size(); i++) {
            int gid = group[i][j];
            if (gid == 0) continue;

            if (!group_checked[gid]) {
                sum += arr[gid];
                group_checked[gid] = true;
            }
        }

        answer = max(answer, sum);
    }

    return answer;
}
