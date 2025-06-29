#pragma once
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[1001];
bool visited[1001];
int n, maxDepth = 0;

void Input() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int num, x, y;
		cin >> num >> x >> y;

		if (x != 0) {
			v[num].push_back(x);
		}
		if (y != 0) {
			v[num].push_back(y);
		}
	}
}

void BFS(int start) {
	queue<pair<int, int>> q;
	q.push({ start, 1 });
	visited[start] = true;

	while (!q.empty()) {
		int curr = q.front().first;
		int cnt = q.front().second;
		q.pop();

		maxDepth = max(maxDepth, cnt);

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (!visited[next] && v[curr][i] > 0) {
				q.push({ next, cnt + 1 });
				visited[next] = true;
			}
		}
	}

}

int main() {
	Input();

	BFS(1);

	cout << maxDepth;
}