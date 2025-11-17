#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int n, m;
int arr[510][502];
bool visited[501][501] = { false, };

struct Node {
	int x, y, cnt, now_num;
};

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int BFS(int x, int y, int num) {
	queue<Node> q;
	visited[x][y] = true;
	q.push({ x,y,0,num });
	int ans = INT_MAX;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int ccnt = q.front().cnt;
		int cnum = q.front().now_num;
		q.pop();

		if (cx == n - 1 && cy == m - 1) {
			ans = min(ans, ccnt);
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + (dx[i] * cnum);
			int ny = cy + (dy[i] * cnum);

			if (InRange(nx, ny) && !visited[nx][ny]) {
				q.push({ nx,ny,ccnt + 1, arr[nx][ny] });
				visited[nx][ny] = true;
			}
		}
	}

	return ans;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = (int)(s[j] - '0');
		}
	}

	int ans = -1;
	ans = BFS(0, 0, arr[0][0]);

	if (ans == INT_MAX) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << ans;
	}
}