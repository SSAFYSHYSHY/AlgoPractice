#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, e_x, e_y;
bool visited[101][101] = { false, };
int arr[101][101];
int ans = 0;

int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

struct Node {
	int x, y, cnt;
};

void BFS() {
	queue<Node> q;
	q.push({ 1,1,0 });
	visited[1][1] = true;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		if (cx == e_x && cy == e_y) {
			cout << ccnt;
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny]) {
				q.push({ nx,ny,ccnt + 1 });
				visited[nx][ny] = true;
			}
		}
	}

	cout << "NEVAR";
	return;
}

int main() {
	cin >> n >> m >> e_x >> e_y;

	BFS();

}
