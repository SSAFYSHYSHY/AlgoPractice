#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n, m;

char map[182][182], arr[182][182];
int ans[182][182];
bool visited[182][182] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pair<int, int>> v;

void Input() {
	memset(visited, false, sizeof(visited));

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			arr[i][j] = (int)(map[i][j] - '0');
			if (map[i][j] == '1') {
				v.push_back({ i,j });
			}
		}
	}
}

struct Node {
	int x, y, now;
};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS() {
	queue<Node> q;

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		visited[x][y] = true;

		q.push({ x,y,0 });
	}

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cnow = q.front().now;
		q.pop();

		ans[cx][cy] = cnow;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 0) {
				q.push({ nx,ny,cnow + 1 });
				visited[nx][ny] = true;
			}

		}
	}
}

int main() {
	Input();

	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}
