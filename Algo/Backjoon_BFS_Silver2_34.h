#pragma once
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <tuple>

using namespace std;

char arr[1001][1001];
bool visited[1001][1001] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = 0;
int n, m, sx, sy;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

tuple<int, int, int> BFS() {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	visited[sx][sy] = true;
	q.push({ sx,sy });

	int small = 0;
	int medium = 0;
	int large = 0;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (arr[cx][cy] == 'S') small++;
		else if (arr[cx][cy] == 'M') medium++;
		else if (arr[cx][cy] == 'L') large++;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] != '*') {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

	return { small, medium, large };
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
		}
	}
	cin >> sx >> sy;

	tuple<int, int, int> num = BFS();
	int first = get<0>(num);
	int second = get<1>(num);
	int third = get<2>(num);

	int ans = (first * 1) + (second * 5) + (third * 10);
	cout << ans;

}