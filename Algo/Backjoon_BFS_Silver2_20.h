#pragma once

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int n;
char arr[41][41];
bool visited[41][41] = { false, };

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == '1') {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {

	int t = 1;
	while (cin >> n) {
		memset(arr, '0', sizeof(arr));
		memset(visited, false, sizeof(visited));

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
				if (!visited[i][j] && arr[i][j] == '1') {
					BFS(i, j);
					ans++;
				}
			}
		}

		cout << "Case #" << t << ": " << ans << "\n";
		t++;

	}

}