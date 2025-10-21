#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100001] = { false, };
vector<int> v[1000001];

int n;

int BFS(int start, int endi) {
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty()) {
		int curr = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (curr == endi) {
			return cnt;
		}

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, cnt + 1 });
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, c;
		cin >> a >> c;

		for (int j = 0; j < c; j++) {
			int b;
			cin >> b;

			v[a].push_back(b);
		}
	}

	int start, endi;
	cin >> start >> endi;

	cout << start << " " << endi << " " << BFS(start, endi) - 1;
}
