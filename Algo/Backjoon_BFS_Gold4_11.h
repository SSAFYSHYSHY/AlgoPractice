#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v[1001];
bool visited[1001][1001];
queue<int> q;
int n, m, x, y;

void BFS(int x, int cnt) {
	q.push(x);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			visited[nx][cnt + 1] = true;
		}

	}

}

int main() {
	cin >> n >> m >> x >> y;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	if (!v[x].size()) {
		cout << -1;
		return 0;
	}
	visited[x][0] = true;
	for (int i = 0; i < y; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[j][i]) {
				BFS(j, i);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i][y]) {
			cout << i << '\n';
		}
	}

}
