#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool visited[1001];
vector<int> v[1001];
int n, m, s;

void BFS() {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = true;

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
	cin >> n >> m >> s;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	BFS();

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			cout << "no";
			return 0;
		}
	}

	cout << "yes";
}