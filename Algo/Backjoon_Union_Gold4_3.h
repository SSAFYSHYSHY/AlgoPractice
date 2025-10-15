#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int parent[100001];
int sz[100001];
int n, m, limit;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a != b) {
		parent[a] = b;
		sz[b] = min(sz[a], sz[b]);
	}
}

int main() {
	cin >> n >> m >> limit;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> sz[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		Union(a, b);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (Find(i) == i) {
			ans += sz[i];
		}
	}

	if (ans > limit) cout << "Oh no";
	else cout << ans;
}