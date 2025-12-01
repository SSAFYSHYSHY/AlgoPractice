#pragma once
#include <iostream>

using namespace std;

int parent[100001];
int n, m, ans = 0;

int Find(int num) {
	if (parent[num] == num) return num;
	return parent[num] = Find(parent[num]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a > b) {
		swap(a, b);
	}
	parent[b] = a;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		int num;
		cin >> num;

		num = Find(num);

		if (num == 0) break;

		Union(num, num - 1);

		ans++;
	}
	cout << ans;
}