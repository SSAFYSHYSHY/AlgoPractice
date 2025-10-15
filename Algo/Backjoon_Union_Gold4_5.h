#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int parent[500005];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return false;
	parent[b] = a;
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	int ans = 0;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;

		if (!Union(a, b) && ans == 0) {
			ans = i;
		}
	}

	cout << ans;
}