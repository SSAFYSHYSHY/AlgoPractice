#pragma once
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[100001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

bool Merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return false;

	parent[b] = a;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	int cycle = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		//사이클 발생.
		if (!Merge(x, y)) cycle++;
	}

	int comp = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == i) comp++;
	}

	cout << cycle + (comp - 1);
}