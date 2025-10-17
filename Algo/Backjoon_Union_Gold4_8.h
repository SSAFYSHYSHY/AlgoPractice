#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, cnt;
int parent[10000000];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	parent[a] = b;
}

int main() {
	cin >> n >> m;
	int cnt = n;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		while (Find(x) != Find(y)) {
			--cnt;

			int next = Find(x) + 1;

			Union(x, y);
			x = next;
		}

	}

	cout << cnt;

}