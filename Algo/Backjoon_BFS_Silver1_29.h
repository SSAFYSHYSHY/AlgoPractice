#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int area;
int n, m;
char arr[26][26];
bool visited[26][26] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x,y });

	int cnt = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == arr[x][y]) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	cin >> area >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
		}
	}

	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j] == '.') {
				int num = BFS(i, j);
				v.push_back(num);
			}
		}
	}

	sort(v.begin(), v.end(), greater<>());

	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (area >= v[i]) {
			area -= v[i];
			ans++;
		}
		else break;
	}

	if (ans == 1) {
		cout << ans << " room, " << area << " square metre(s) left over";
	}
	else {
		cout << ans << " rooms, " << area << " square metre(s) left over";
	}
}