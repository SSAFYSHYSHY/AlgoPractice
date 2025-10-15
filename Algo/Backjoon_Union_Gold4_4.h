#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	int x, y, r;
};

int parent[100005];
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
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<Node> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i].x >> v[i].y >> v[i].r;
			parent[i] = i;
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				long long dx = v[i].x - v[j].x;
				long long dy = v[i].y - v[j].y;
				long long dist = dx * dx + dy * dy;
				long long dr = v[i].r + v[j].r;

				if (dist <= dr * dr) {
					Union(i, j);
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (Find(i) == i) {
				cnt++;
			}
		}

		cout << cnt << "\n";
	}

}