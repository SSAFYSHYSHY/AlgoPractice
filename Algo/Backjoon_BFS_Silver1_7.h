#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int arr[101][101];
bool visited[101][101] = { false, };
int n, m, sx, sy, ex, ey;

int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

struct Node {
	int x, y, cnt;
};

int BFS() {
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

			if (InRange(nx, ny) && !visited[nx][ny]) {
				q.push({ nx,ny, ccnt + 1 });
				visited[nx][ny] = true;
			}
		}
	}

	return -1;
}

int main() {


	while (cin >> n >> m >> sx >> sy >> ex >> ey) {
		memset(visited, false, sizeof(visited));

		int ans = -1;
		ans = BFS();

		if (ans == -1) {
			cout << "impossible\n";
		}
		else {
			cout << ans << "\n";
		}

	}

}