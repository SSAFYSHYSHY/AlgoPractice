#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n, m;
int sx, sy, ex, ey;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

char arr[51][51];
int dist[51][51];

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void Calc() {
	memset(dist, -1, sizeof(dist));
	priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>>pq;
	pq.push({ {0,0}, {sx,sy} });

	int cnt = 0;
	int trash_cnt = 0;

	dist[sx][sy] = 0;

	while (!pq.empty()) {
		int flag = false;
		int cnt2 = pq.top().first.first;
		int trash_cnt2 = pq.top().first.second;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx == ex && ny == ey) {
				cnt = cnt2;
				trash_cnt = trash_cnt2;
				flag = true;
				break;
			}

			if (!InRange(nx, ny)) continue;
			if (dist[nx][ny] != -1) continue;

			if (arr[nx][ny] == 'g') {
				pq.push({ {cnt2 + 1, trash_cnt2}, {nx,ny} });
			}
			else if (arr[nx][ny] == '.') {
				bool flag2 = false;
				for (int j = 0; j < 4; j++) {
					if (arr[nx + dx[j]][ny + dy[j]] == 'g') {
						flag2 = true;
						break;
					}
				}

				if (flag2) {
					pq.push({ {cnt2, trash_cnt2 + 1},{nx,ny} });
				}
				else {
					pq.push({ {cnt2, trash_cnt2},{nx,ny} });
				}
			}

			dist[nx][ny] = dist[x][y] + 1;
		}
		if (flag) break;
	}

	cout << cnt << " " << trash_cnt;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (arr[i][j] == 'F') {
				ex = i;
				ey = j;
			}
		}
	}

	Calc();
}
