#pragma once
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[1000001];

bool InRange(int x) {
    return 1 <= x && x < 1000001;
}

int BFS(int x, int y, int n) {
    visited[x] = true;
    queue<pair<int, int>> q;
    q.push({ x,0 });

    while (!q.empty()) {
        int cx = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cx == y) {
            return cnt;
        }

        for (int i = 0; i < 3; i++) {
            int nx = 0;
            if (i == 0) nx = cx + n;
            else if (i == 1) nx = cx * 2;
            else nx = cx * 3;

            if (InRange(nx) && !visited[nx]) {
                q.push({ nx, cnt + 1 });
                visited[nx] = true;
            }
        }
    }

    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;

    answer = BFS(x, y, n);

    return answer;
}