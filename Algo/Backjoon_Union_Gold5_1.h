#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int find(int x) {
	if (v[x] != x) {
		v[x] = find(v[x]);
	}

	return v[x];
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		v[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	v.resize(n + 1);

	for (int i = 0; i <= n; i++) {
		v[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 0) {
			Union(a, b);
		}
		else {
			if (find(a) == find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
}