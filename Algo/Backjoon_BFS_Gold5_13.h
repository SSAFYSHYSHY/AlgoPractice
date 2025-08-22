#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

char arr[11][11];
bool visited[11][11] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int sx, sy;

void Input() {
	for (int i = 0; i < 10; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];

			if (arr[i][j] == 'B') {
				sx = i;
				sy = j;
			}
		}
	}

	memset(visited, false, sizeof(visited));
}

bool InRange(int x, int y) {
	return 0 <= x && x < 10 && 0 <= y && y < 10;
}

void BFS() {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == '-') {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}

}

int main() {
	Input();

	string s;
	while (cin >> s) {
		int x = (int)(s[3] - '0');
		int y = (int)(s[1] - '0');

		arr[x][y] = 'X';
	}

	BFS();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (!visited[i][j] && (arr[i][j] == '-' || arr[i][j] == 'X')) {
				cout << "(" << j << "," << i << ")\n";
			}
		}
	}

}
