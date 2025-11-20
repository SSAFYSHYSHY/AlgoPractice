#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring> // memset을 쓰려면 필요함

using namespace std;

int n, m; // n: 높이(행), m: 너비(열) -> 문제 입력 순서 주의!
char arr[51][51];
bool visited[51][51];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int sx, sy, ans = 0;

// 범위 체크 함수
bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS() {
    queue<pair<int, int>> q;
    q.push({ sx,sy });
    visited[sx][sy] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 1. 현재 위치에 금이 있으면 획득
        if (arr[cx][cy] == 'G') ans++;

        // [수정된 부분 1] 외풍(Draft) 감지 단계
        // 큐에 넣기 전에, 내 주변에 T가 하나라도 있는지 '먼저' 확인해야 함
        bool is_drafty = false;
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny)) {
                if (arr[nx][ny] == 'T') {
                    is_drafty = true; // 함정 발견!
                    break; // 더 볼 것도 없이 외풍 확정
                }
            }
        }

        // [수정된 부분 2] 외풍이 불면 여기서 멈춤 (이웃 탐색 안 함)
        if (is_drafty) continue;


        // [수정된 부분 3] 안전한 경우에만 이동(확장)
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (arr[nx][ny] == '#') continue;

            // 이미 위에서 draft 체크를 통과했으므로, 
            // 인접한 칸은 T가 아님이 보장됨. 안심하고 이동.

            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
}

int main() {
    // 빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받기
    cin >> m >> n; // 문제 조건: W(너비,열), H(높이,행) 순서 입력

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) { // 행(높이) 반복
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) { // 열(너비) 반복
            arr[i][j] = s[j];
            if (arr[i][j] == 'P') {
                sx = i;
                sy = j;
            }
        }
    }

    BFS();

    cout << ans;

    return 0;
}