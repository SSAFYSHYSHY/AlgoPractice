#pragma once
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[11][11];
bool visited[11][11];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = 21e8;

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Calc(int x, int y) {
	int cx = 0, cy = 0;

	for (int i = 0; i < 4; i++) {
		if (0 <= i && i <= 1) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && arr[nx][ny] == 0) {
				cx++;
			}
		}
		else {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && arr[nx][ny] == 0) {
				cy++;
			}
		}
	}

	if (1 <= cx && 1 <= cy) {
		arr[x][y] = -1;
	}
}

struct Node {
	int x, y, dist;
};

void BFS() {
	memset(visited, false, sizeof(visited));

	queue<Node> q;
	visited[0][0] = true;
	q.push({ 0,0,0 });

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cdist = q.front().dist;
		q.pop();

		if (cx == n - 1 && cy == n - 1) {
			ans = min(ans, cdist);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny]) {
				if (arr[nx][ny] == 1) {
					visited[nx][ny] = true;
					q.push({ nx,ny,cdist + 1 });
				}

				else if (arr[nx][ny] > 1) {
					if (((cdist + 1) % arr[nx][ny]) == 0) {
						if (arr[cx][cy] == 1) {
							visited[nx][ny] = true;
							q.push({ nx,ny,cdist + 1 });
						}
					}
					else {
						q.push({ cx,cy,cdist + 1 });
					}
				}
			}
		}
	}
}

int main() {
	Input();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				Calc(i, j);
			}
		}
	}

	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = m;
				BFS();
				arr[i][j] = 0;
			}
		}
	}

	cout << ans;
}
