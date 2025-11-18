#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int Y, X, N, H;
        cin >> Y >> X >> N >> H;

        vector<vector<int>> arr(Y, vector<int>(X));

        // 초기 모래 상태 입력
        for (int i = 0; i < Y; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < X; j++) {
                arr[i][j] = s[j] - '0';
            }
        }

        // n번 낙하 처리
        while (N--) {
            int r, c;
            cin >> r >> c;
            r--, c--;

            queue<pair<int, int>> q;

            arr[r][c]++;
            if (arr[r][c] > H) q.push({ r,c });

            // 연쇄 Toppling
            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                if (arr[y][x] <= H) continue;

                arr[y][x] -= 4;

                for (int d = 0; d < 4; d++) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];

                    if (0 <= ny && ny < Y && 0 <= nx && nx < X) {
                        arr[ny][nx]++;
                        if (arr[ny][nx] > H)
                            q.push({ ny, nx });
                    }
                }
            }
        }

        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }
}