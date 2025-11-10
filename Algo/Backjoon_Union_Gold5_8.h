#pragma once
#include <iostream>
#include <algorithm>

using namespace std;


int n, m;
int arr[1000001];
int parent[1000001];


int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb) return false;
	parent[pb] = pa;
	return true;
}

int main() {
	cin >> n >> m;

	if (n == 1) { cout << 0; return 0; }

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	int num = n;
	int ans = -1;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;

		if (Union(a, b)) {
			num--;
			if (num == 1 && ans == -1) {
				ans = i;
			}
		}
	}

	cout << ans;
}