#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

char arr[101][101];
bool visited[101][101] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int sx, sy;
int n, m;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}


int BFS(int x, int y) {
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x,y });
	int cnt = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == '#') {
				cnt++;
				q.push({ nx,ny });
				visited[nx][ny] = true;
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

			if (arr[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	}

	int ans = BFS(sx, sy);

	cout << ans;
}