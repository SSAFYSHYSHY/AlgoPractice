#pragma once
//최적 경로 관리 및 그 경로 제외하는 방법에 대한 솔루션.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, s, e, sum = 0;
bool visited[100000] = { false, };
bool check[100000] = { false, };
int parent[100000];
vector<int> v[100000];

void Input() {
	memset(parent, -1, sizeof(parent));

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	cin >> s >> e;

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
}

int BFS(int start, int endi) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	visited[start] = true;
	q.push({ start, 0 });

	while (!q.empty()) {
		int curr = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (curr == endi) {
			return dist;
		}

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (!visited[next]) {
				visited[next] = true;
				parent[next] = curr;
				q.push({ next, dist + 1 });
			}
		}
	}

	return -1;
}

int BFS2(int endi, int start) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	visited[endi] = true;
	q.push({ endi, 0 });

	while (!q.empty()) {
		int curr = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (curr == start) {
			return dist;
		}

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (!visited[next] && !check[next]) {
				visited[next] = true;
				q.push({ next, dist + 1 });
			}
		}
	}

	return -1;
}

int main() {
	Input();

	int first = BFS(s, e);

	int curr = e;
	while (curr != -1) {
		check[curr] = true;
		curr = parent[curr];
	}
	check[s] = false;
	check[e] = false;

	int second = BFS2(e, s);

	cout << first + second;
}