#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[1001];
int match[1001];
bool visited[1001] = { false, };
int n, m;

bool DFS(int idx) {
	for (int job : v[idx]) {
		if (visited[job]) continue;

		visited[job] = true;

		if (match[job] == 0 || DFS(match[job])) {
			match[job] = idx;
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
	for (int worker = 1; worker <= n; worker++) {
		memset(visited, false, sizeof(visited));
		if (DFS(worker)) {
			ans++;
		}
	}

	cout << ans;

}