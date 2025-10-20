#pragma once
#include <iostream>
#include <queue>

using namespace std;

int dx[2];
int n, tar;
bool visited[2001] = { false, };

void BFS(int num) {
	queue<pair<int, int>> q;
	q.push({ num,0 });
	visited[num + 1000] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == tar) {
			cout << cnt;
			return;
		}

		for (int i = 0; i < 2; i++) {
			int nx = cur + dx[i];

			if (nx < -1000 || nx > 1000) continue;
			if (!visited[nx + 1000]) {
				visited[nx + 1000] = true;
				q.push({ nx, cnt + 1 });
			}
		}
	}

	cout << -1;
	return;
}

int main() {
	cin >> n >> tar;

	for (int i = 0; i < n; i++) {
		cin >> dx[i];
	}

	BFS(0);

}