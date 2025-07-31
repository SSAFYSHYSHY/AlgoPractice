#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, cnt = 0;
vector<int> v[500001];
bool visited[500001] = { false, };

void BFS(int now) {
	queue<int> q;
	visited[now] = true;
	q.push(now);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (visited[next]) {
				if (v[curr].size() == 1) cnt++;
				continue;
			}

			visited[next] = true;
			q.push(next);
		}
	}
}

int main() {
	cin >> n >> m;

	cout << fixed;
	cout.precision(10);

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	visited[1] = true;
	BFS(1);

	cout << (double)(m / (double)cnt);
}