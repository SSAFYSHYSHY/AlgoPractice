#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int n, m, ans = 0;
char arr[101][101];
bool visited[101][101] = { false, };

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;
			if (visited[nx][ny]) continue;

			if (arr[nx][ny] == '#') {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j] == '#') {
				BFS(i, j);
				ans++;
			}
		}
	}

	cout << ans << "\n";

}