#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int parent[100006];

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {

		int n, k;
		memset(parent, 0, sizeof(parent));
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;

			Union(a, b);
		}

		int q;
		cin >> q;
		cout << "Scenario " << tc << ":\n";

		for (int i = 0; i < q; i++) {
			int a, b;
			cin >> a >> b;

			if (Find(a) != Find(b)) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
		}

		cout << "\n";
	}

}