#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int t;
bool visited[1001];
vector<int> v[10001];

void BFS(int idx) {
	queue<int> q;
	visited[idx] = true;
	q.push(idx);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}

	}
}

int main() {
	cin >> t;

	while (t--) {
		memset(visited, false, sizeof(visited));

		int n, k;
		cin >> n >> k;

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		//BFS üũ.
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				BFS(i);
				cnt++;
			}
		}

		if (cnt > 1) {
			cout << "Not connected.\n";
		}
		else {
			cout << "Connected.\n";
		}

		for (int i = 0; i < n; i++) {
			v[i].clear();
		}
	}

}