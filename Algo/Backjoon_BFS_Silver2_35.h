#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
bool visited[1001] = { false, };
vector<int> v[1001];
vector<int> start;

int BFS(int sx) {
	visited[sx] = true;
	queue<int> q;
	q.push(sx);

	int cnt = 1;
	while (!q.empty()) {
		int cx = q.front();
		q.pop();

		for (int i = 0; i < v[cx].size(); i++) {
			int nx = v[cx][i];

			if (!visited[nx]) {
				visited[nx] = true;
				q.push(nx);
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		start.push_back(a);
	}

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	int ans = 0;
	for (int i = 0; i < start.size(); i++) {
		if (!visited[start[i]]) {
			ans += BFS(start[i]);
		}
	}

	cout << ans << "\n";

}