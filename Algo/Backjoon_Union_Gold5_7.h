#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int parent[100001];
int arr[100001];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa != pb) {
		parent[pb] = pa;
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

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int cnt = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int a = Find(v[i]);
		int b = Find(v[i + 1]);

		if (a != b) cnt++;
	}

	cout << cnt;

}