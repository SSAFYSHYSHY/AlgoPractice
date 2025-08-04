#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <cstring>

using namespace std;

int n;
char arr[51][51];
int dist[51][51];
bool visited[51][51];

int total_k = 0;
int s_x, s_y;

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Input() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j];

            if (arr[i][j] == 'P') {
                s_x = i;
                s_y = j;
            }
            if (arr[i][j] == 'K') {
                total_k++;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];
}

bool BFS(int left, int right) {
    if (dist[s_x][s_y] < left || dist[s_x][s_y] > right)
        return false;

    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({ s_x, s_y });
    visited[s_x][s_y] = true;
    int cnt = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (arr[cx][cy] == 'K') cnt++;

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;

            int h = dist[nx][ny];
            if (h < left || h > right) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }

    return cnt == total_k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    vector<int> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            v.push_back(dist[i][j]);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int ans = 1e9;
    int l = 0, r = 0;

    while (l < v.size() && r < v.size()) {
        if (BFS(v[l], v[r])) {
            ans = min(ans, v[r] - v[l]);
            l++;
        }
        else {
            r++;
        }
    }

    cout << ans;
}
