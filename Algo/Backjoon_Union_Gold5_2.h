#pragma once
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int parent[300001];
int n;

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
	cin >> n;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n - 2; i++) {
		int x, y;
		cin >> x >> y;

		Union(x, y);
	}

	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(Find(i));
	}

	for (auto i : s) {
		cout << i << " ";
	}
}