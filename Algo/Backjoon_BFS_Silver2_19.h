#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

char arr[1001][1001];
bool visited[1001][1001] = {};

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y, int n) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		memset(visited, false, sizeof(visited));
		memset(arr, '.', sizeof(arr));
		queue<pair<int, int>> q;

		int n;

		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			for (int j = 0; j < s.length(); j++) {
				arr[i][j] = s[j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j : {0, n - 1}) {
				if (arr[i][j] == '.' && !visited[i][j]) {
					visited[i][j] = true;
					q.push({ i,j });
				}
			}
		}

		for (int j = 0; j < n; j++) {
			for (int i : {0, n - 1}) {
				if (arr[i][j] == '.' && !visited[i][j]) {
					visited[i][j] = true;
					q.push({ i,j });
				}
			}
		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (!InRange(nx, ny, n)) continue;
				if (arr[nx][ny] == '.' && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}

		int area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == '#') area++;
				else  if (!visited[i][j] && arr[i][j] == '.') area++;
			}
		}

		cout << area << "\n";
	}

}
