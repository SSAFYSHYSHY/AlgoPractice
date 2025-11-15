#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

char arr[101][101][101];
bool visited[101][101][101] = { false, };
int n;

int dh[] = { -1,1 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct Node {
	int h, x, y;
};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void BFS(int h, int x, int y) {
	visited[h][x][y] = true;
	queue<Node> q;
	q.push({ h,x,y });

	while (!q.empty()) {
		int ch = q.front().h;
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();

		for (int i = 0; i < 2; i++) {
			int nh = ch + dh[i];

			if ((0 <= nh && nh < n) && !visited[nh][cx][cy] && arr[nh][cx][cy] == '*') {
				q.push({ nh, cx,cy });
				visited[nh][cx][cy] = true;
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[ch][nx][ny] && arr[ch][nx][ny] == '*') {
				q.push({ ch,nx,ny });
				visited[ch][nx][ny] = true;
			}
		}

	}
}

int main() {
	memset(visited, false, sizeof(visited));
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			string s;
			cin >> s;

			for (int k = 0; k < s.length(); k++) {
				arr[i][j][k] = s[k];
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!visited[i][j][k] && arr[i][j][k] == '*') {
					cnt++;
					BFS(i, j, k);
				}
			}
		}
	}

	cout << cnt;


}