#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool visited[1001][1001] = { false, };
char arr[1001][1001];
int n, m, sx, sy, ex, ey;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool BFS(int sx, int sy, char c) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (cx == ex && cy == ey) {
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == c) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}

	return false;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		memset(visited, false, sizeof(visited));
		memset(arr, ' ', sizeof(arr));

		cin >> m >> n >> sy >> sx >> ey >> ex;

		sy--;
		sx--;

		ey--;
		ex--;

		for (int i = n - 1; i >= 0; i--) {
			string s;
			cin >> s;

			for (int j = 0; j < s.length(); j++) {
				arr[i][j] = s[j];
			}
		}

		if (BFS(sx, sy, arr[sx][sy])) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}