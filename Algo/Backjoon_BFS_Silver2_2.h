#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int n, m, ans = 0;
char arr[1001][81];
bool visited[1001][81];

void Input() {
	memset(visited, false, sizeof(visited));
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	visited[x][y] = true;
	int cnt = 1;
	q.push({ x,y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == '*') {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				cnt++;
			}
		}

	}

	return cnt;
}

int main() {
	Input();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j] == '*') {
				visited[i][j] = true;
				int num = BFS(i, j);
				ans = max(num, ans);
			}
		}
	}

	cout << ans;
}