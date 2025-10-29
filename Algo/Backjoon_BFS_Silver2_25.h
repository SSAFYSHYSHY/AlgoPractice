#pragma once
#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
#include <vector>

using namespace std;

char arr[11][11];
int n, m, l;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool Forbidden(char c) {
    return (c == 'a' || c == 'c' || c == 'm');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> l;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j];
        }
    }

    vector<string> all_words;
    unordered_set<string> unique_words;

    // 모든 시작 지점에서 BFS 시작
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Forbidden(arr[i][j])) continue; // 금지 알파벳은 시작 불가

            queue<pair<pair<int, int>, string>> q;
            q.push({ {i, j}, string(1, arr[i][j]) });

            while (!q.empty()) {
                auto curr = q.front();
                q.pop();

                int x = curr.first.first;
                int y = curr.first.second;
                string path = curr.second;

                if ((int)path.size() == l) {
                    all_words.push_back(path);
                    unique_words.insert(path);
                    continue; // 더 확장 불가
                }

                // 상하좌우 이동
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (!InRange(nx, ny)) continue;
                    if (Forbidden(arr[nx][ny])) continue;

                    q.push({ {nx, ny}, path + arr[nx][ny] });
                }
            }
        }
    }

    cout << all_words.size() << "\n" << unique_words.size() << "\n";
    return 0;
}