#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int arr[9][9];
bool visited[9][9] = { false, };
string a, b;
int sx, sy, ex, ey;

int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };

bool InRange(int x, int y) {
	return 1 <= x && x <= 8 && 1 <= y && y <= 8;
}

struct Node {
	int x, y, cnt;
};

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

			if (InRange(nx, ny) && !visited[nx][ny]) {
				q.push({ nx,ny, ccnt + 1 });
				visited[nx][ny] = true;
			}
		}
	}

	return -1;
}

int main() {


	while (cin >> a >> b) {
		memset(visited, false, sizeof(visited));

		int sx = (a[0] - 'a') + 1;
		int sy = a[1] - '0';

		int ex = (b[0] - 'a') + 1;
		int ey = b[1] - '0';

		int ans = -1;
		ans = BFS(sx, sy, ex, ey);

		cout << "To get from " << a << " to " << b << " takes " << ans << " knight moves.\n";

	}

}