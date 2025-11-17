#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

char dir[] = { 'N','S','W','E' };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

vector<pair<int, int>> v[122][122];
bool visited[122][122] = { false, };

int cx, cy, sx, sy, ex, ey;
int t;

struct Node {
	int x, y, cnt;
};

bool InRange(int x, int y) {
	return 0 <= x && x <= 120 && 0 <= y && y <= 120;
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

		for (int i = 0; i < v[cx][cy].size(); i++) {
			int nx = v[cx][cy][i].first;
			int ny = v[cx][cy][i].second;

			if (InRange(nx, ny) && !visited[nx][ny]) {
				q.push({ nx,ny, ccnt + 1 });
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	cin >> t;

	while (t--) {
		for (int i = 0; i < 122; i++) {
			for (int j = 0; j < 122; j++) {
				v[i][j].clear();
			}
		}

		memset(visited, false, sizeof(visited));

		int num;
		cin >> num;

		sx = 60, sy = 60;
		cx = sx, cy = sy;

		for (int i = 0; i < num; i++) {
			char s;
			cin >> s;
			int idx = 0;

			if (s == 'N') idx = 0;
			else if (s == 'S') idx = 1;
			else if (s == 'W') idx = 2;
			else if (s == 'E') idx = 3;

			int nx = cx + dx[idx];
			int ny = cy + dy[idx];

			v[cx][cy].push_back({ nx,ny });
			v[nx][ny].push_back({ cx,cy });

			cx = nx;
			cy = ny;
		}

		ex = cx, ey = cy;

		int dir = BFS(sx, sy, ex, ey);

		cout << dir << "\n";
	}


}