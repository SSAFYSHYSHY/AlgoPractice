#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, q;
int parent[1001];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		Union(a, b);
	}

	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;

		if (Find(x) == Find(y)) {
			cout << "Y\n";
		}
		else {
			cout << "N\n";
		}
	}
}