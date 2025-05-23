#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n, m, s_x, s_y, ans;

char arr[101][101];
bool visited[101][101];

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

void Input() {
	cin >> m >> n >> s_y >> s_x;

	s_x = n - s_x;
	s_y -= 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

struct Node {
	int cnt, x, y;
};

void BFS() {
	queue<Node> q;
	visited[s_x][s_y] = true;
	q.push({ 0, s_x, s_y });

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		// 최대 시간 갱신
		ans = max(ans, cur.cnt);

		for (int i = 0; i < 8; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == '.') {
				visited[nx][ny] = true;
				q.push({ cur.cnt + 1, nx, ny });
			}
		}
	}
}

int main() {
	Input();
	BFS();
	cout << ans << '\n';
}
