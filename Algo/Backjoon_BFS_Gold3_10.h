#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[200001];
int a, b, c, n;
int visited[200001][3];
vector<int> leaf;

void Input() {
	memset(visited, -1, sizeof(visited));

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= 200000; i++) {
		if (v[i].size() == 1) {
			leaf.push_back(i);
		}
	}

	cin >> a >> b >> c;
}

bool InRange(int x) {
	return 1 <= x && x <= n;
}

void BFS(int start, int idx) {
	queue<pair<int, int>> q;
	q.push({ start , 0 });
	visited[start][idx] = 0;

	while (!q.empty()) {
		int cx = q.front().first;
		int ccost = q.front().second;
		q.pop();

		for (int i = 0; i < v[cx].size(); i++) {
			int nx = v[cx][i];

			if (visited[nx][idx] != -1) continue;
			if (!InRange(nx)) continue;

			q.push({ nx, ccost + 1 });
			visited[nx][idx] = ccost + 1;
		}
	}
}

int main() {
	cin >> n;

	Input();
	BFS(a, 0);
	BFS(b, 1);
	BFS(c, 2);

	for (int i = 0; i < leaf.size(); i++) {
		int idx = leaf[i];

		if (visited[idx][0] < min(visited[idx][1], visited[idx][2])) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

}