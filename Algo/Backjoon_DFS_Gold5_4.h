#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
const int MOD = 1000000007;

long long ans = 1;
vector<int> v[200001];
bool visited[200001];

long long DFS(int x) {
	long long cnt = 1;
	visited[x] = true;

	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];

		if (!visited[next]) {
			cnt += DFS(next);
		}
	}

	return cnt;
}

int main() {
	int n, m;
	cin >> n >> m;

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		ans = (ans * DFS(i)) % MOD;
	}

	cout << ans;
}