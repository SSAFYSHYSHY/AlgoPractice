#pragma once
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
bool visited[200001] = { false, };
vector<int> v[200001];

int BFS() {
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	visited[1] = true;

	while (!q.empty()) {
		int curr = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (curr == n) {
			return dist;
		}

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, dist + 1 });
			}
		}
	}

	return -1;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	int ans = BFS();

	cout << ans;
}