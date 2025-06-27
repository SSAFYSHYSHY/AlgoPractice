#pragma once
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[1001];
int match[1001];
bool visited[1001];

bool DFS(int idx) {
	for (int cow : v[idx]) {
		if (visited[cow]) continue;

		visited[cow] = true;

		if (match[cow] == 0 || DFS(match[cow])) {
			match[cow] = idx;
			return true;
		}
	}

	return false;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> cnt;

		for (int j = 0; j < cnt; j++) {
			int x;
			cin >> x;

			v[i].push_back(x);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (DFS(i)) {
			ans++;
		}
	}

	cout << ans;
}