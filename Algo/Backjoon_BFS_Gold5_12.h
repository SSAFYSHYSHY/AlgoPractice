#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int w, h, n, d, b, sx, sy, ans = 1;
int arr[101][101];
bool visited[101][101] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 1 <= x && x <= w && 1 <= y && y <= h;
}

void BFS() {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			for (int j = 1; j <= d; j++) {
				int nx = cx + dx[i] * j;
				int ny = cy + dy[i] * j;

				if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 1) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
					ans++;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		memset(visited, false, sizeof(visited));
		memset(arr, 0, sizeof(arr));

		cin >> w >> h;
		cin >> n;
		cin >> d >> b;

		if (w == 0 && h == 0 && n == 0 && d == 0 && b == 0) break;

		for (int i = 1; i <= n; i++) {
			int x, y;
			cin >> x >> y;

			arr[x][y] = 1;

			if (i == b) {
				sx = x;
				sy = y;
			}
		}

		BFS();
		cout << ans << '\n';
		ans = 1;
	}
}