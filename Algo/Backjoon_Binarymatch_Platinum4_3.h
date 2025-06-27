#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[1001];
bool visited[1001];
int match[1001];
int n, m;

bool DFS(int idx) {
	for (int curr : v[idx]) {
		if (visited[curr]) continue;

		visited[curr] = true;

		if (match[curr] == 0 || DFS(match[curr])) {
			match[curr] = idx;
			return true;
		}

	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

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
		for (int k = 0; k < 2; k++) {
			memset(visited, false, sizeof(visited));
			if (DFS(i)) {
				ans++;
			}
		}
	}

	cout << ans;
}