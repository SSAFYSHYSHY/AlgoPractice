#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int n, m;
bool visited[100001] = { false, };
vector<int> v[100001];
int path[100001];

void BFS() {
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	visited[1] = true;
	path[1] = 1;

	while (!q.empty()) {
		int curr = q.front().first;
		int cnum = q.front().second;
		q.pop();

		path[curr] = cnum;

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, cnum + 1 });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	memset(path, 0, sizeof(path));

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back(b);
		v[a].push_back(c);

		v[c].push_back(a);
		v[b].push_back(b);
	}

	BFS();

	for (int i = 1; i <= n; i++) {
		cout << path[i] << "\n";
	}
}