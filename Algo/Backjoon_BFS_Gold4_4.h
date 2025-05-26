#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
vector<int> v[27];
int visited[27];
int Index = 'A' - 1;

bool Root[27];
int root;

void bfs(int num) {
	queue<int>q;
	q.push(num);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : v[now]) {
			if (visited[next] != 0) continue;
			visited[next] = 1;
			q.push(next);
		}
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		char a, b;
		cin >> a >> b;

		v[a - Index].push_back(b - Index);
		Root[b - Index] = 1;
	}

	int k = 0;
	cin >> k;
	vector<int> del;

	for (int i = 0; i < k; i++) {
		char h;
		cin >> h;

		v[h - Index].clear();
		del.push_back(h - Index);
	}

	for (int i = 1; i <= n; i++) {
		if (Root[i] == 0) {
			root = i;
			visited[i] = 2;
			bfs(i);
		}
	}

	int ans = 0;
	for (auto num : del) {
		visited[num] = 0;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}