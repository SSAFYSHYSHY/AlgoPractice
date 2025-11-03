#pragma once
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;

int arr[101][101];
bool visited[101][101] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int BFS(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visited[sx][sy] = true;

	int cnt = 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == arr[cx][cy]) {
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
	cin >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				int num = BFS(i, j);

				if (num != k) {
					cout << "Wrong answer";
					return 0;
				}
			}
		}
	}

	cout << "OK";

}