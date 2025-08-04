#pragma once
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n, k, r, ans = 0;
int arr[101][101][4];
bool visited[101][101];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pair<int, int >> v;

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void BFS(int sx, int sy) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;
			if (arr[cx][cy][i] == 1) continue;
			if (visited[nx][ny]) continue;

			q.push({ nx,ny });
			visited[nx][ny] = true;
		}

	}
}

int main() {
	cin >> n >> k >> r;

	for (int i = 0; i < r; i++) {
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;

		int dir = -1;
		for (int d = 0; d < 4; d++) {
			if (x + dx[d] == x1 && y + dy[d] == y1) {
				dir = d;
				break;
			}
		}
		if (dir != -1) {
			arr[x][y][dir] = 1;
			arr[x1][y1][dir ^ 1] = 1;
		}
	}

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 0; i < k; i++) {
		BFS(v[i].first, v[i].second);

		for (int j = i + 1; j < k; j++) {
			if (!visited[v[j].first][v[j].second]) {
				ans++;
			}
		}
	}

	cout << ans;
}