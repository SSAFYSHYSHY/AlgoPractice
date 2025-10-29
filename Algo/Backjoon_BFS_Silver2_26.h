#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

int t;
int n;

char arr[101][101];
bool visited[101][101] = { false, };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int BFS(int x, int y) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	int cnt = 0;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;
			if (visited[nx][ny]) continue;

			if (arr[nx][ny] == '-') {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	cin >> t;

	while (t--) {
		memset(arr, '.', sizeof(arr));
		memset(visited, false, sizeof(visited));

		cin >> n;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			for (int j = 0; j < s.length(); j++) {
				arr[i][j] = s[j];
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && arr[i][j] == 'w') {
					ans = max(ans, BFS(i, j));
				}
			}
		}

		cout << ans << "\n";

	}

}