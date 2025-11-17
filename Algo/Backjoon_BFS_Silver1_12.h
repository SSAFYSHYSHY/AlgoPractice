#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
char arr[101][101];
bool visited[101][101] = { false, };

int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };

int sx, sy, ex, ey;

struct Node {
	int x, y, cnt;
};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int BFS(int sx, int sy, int ex, int ey) {
	queue<Node> q;
	q.push({ sx,sy,0 });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		if (cx == ex && cy == ey) {
			return ccnt;
		}

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == '.') {
				q.push({ nx,ny, ccnt + 1 });
				visited[nx][ny] = true;
			}
		}
	}

	return -1;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];

			if (arr[i][j] == 'K') {
				sx = i;
				sy = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'X') {
				ex = i;
				ey = j;
				arr[i][j] = '.';
			}
		}
	}

	int ans = BFS(sx, sy, ex, ey);

	if (ans == -1) {
		cout << "-1";
	}
	else {
		cout << ans;
	}
}