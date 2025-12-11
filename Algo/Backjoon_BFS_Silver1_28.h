#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

char arr[31][31];
bool visited[31][31] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	int cnt = 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == arr[x][y]) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}

	return cnt;
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

	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j] == '.') {
				ans = max(ans, BFS(i, j));
			}
		}
	}

	cout << ans;

}