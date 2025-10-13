#pragma once
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int parent[10001];

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
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		Union(a, b);
	}

	int ans = 0;
	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(Find(i));
	}

	cout << s.size() - 1;
}