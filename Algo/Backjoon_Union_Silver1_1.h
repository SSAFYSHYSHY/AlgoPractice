#pragma once
#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

int n, m;
int parent[500001];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) parent[b] = a;
}

int main() {

	int cnt = 1;
	while (1) {
		memset(parent, 0, sizeof(parent));

		cin >> n >> m;

		if (n == 0 && m == 0) break;

		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			Union(a, b);
		}

		set<int> ans;
		for (int i = 1; i <= n; i++) {
			ans.insert(Find(i));
		}
		cout << "Case " << cnt << ": " << ans.size() << '\n';
		cnt++;
	}

}
