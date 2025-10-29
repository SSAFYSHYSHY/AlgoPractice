#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
bool visited[41][41] = { false, };
char arr[41][41];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int s_x, s_y;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int BFS() {
	queue<pair<int, int>> q;
	q.push({ s_x, s_y });
	visited[s_x][s_y] = true;

	int cnt = 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (arr[nx][ny] == '#') continue;
			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == '.') {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	while (1) {
		memset(visited, false, sizeof(visited));
		memset(arr, '.', sizeof(arr));

		cin >> m >> n;

		if (n == 0 && m == 0) break;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			for (int j = 0; j < s.length(); j++) {
				arr[i][j] = s[j];

				if (arr[i][j] == 'A') {
					s_x = i;
					s_y = j;
					arr[i][j] = '.';
				}
			}
		}

		int ans = BFS();

		cout << ans << "\n";
	}

}