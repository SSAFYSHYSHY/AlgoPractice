#pragma once
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int parent[200005];
int sz[200005];
int n, m;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a != b) {
		parent[b] = a;
		sz[a] += sz[b];
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}

	for (int j = 0; j < m; j++) {
		int a, b;
		cin >> a >> b;

		Union(a, b);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (Find(i) == i) {
			ans = max(ans, sz[i]);
		}
	}

	cout << ans;
}