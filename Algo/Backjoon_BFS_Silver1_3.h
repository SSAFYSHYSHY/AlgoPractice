#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[] = { -1,-1,0,0,1,1 };
int dy[] = { 0,1,-1,1,0,1 };

int dx2[] = { -1,-1,0,0,1,1 };
int dy2[] = { -1,0,-1,1,-1,0 };

int n, m, k;
int arr[1001][1001];
bool visited[1001][1001] = { false, };

struct Node {
	int x, y, cost;
};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS() {
	queue<Node> q;
	q.push({ 0,0,0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int ccnt = q.front().cost;
		q.pop();

		if (cx == n - 1 && cy == m - 1) {
			cout << ccnt;
			return;
		}

		if (cx % 2 == 1) {
			for (int i = 0; i < 6; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 0) {
					visited[nx][ny] = true;
					q.push({ nx,ny,ccnt + 1 });
				}
			}
		}
		else {
			for (int i = 0; i < 6; i++) {
				int nx = cx + dx2[i];
				int ny = cy + dy2[i];

				if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 0) {
					visited[nx][ny] = true;
					q.push({ nx,ny,ccnt + 1 });
				}
			}
		}

	}


	cout << -1;
}

int main() {
	memset(arr, 0, sizeof(arr));
	memset(visited, false, sizeof(visited));

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;

		arr[x][y] = 1;
	}

	BFS();
}
