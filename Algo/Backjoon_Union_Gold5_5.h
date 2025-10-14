#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

struct Node {
	int x1, y1, x2, y2;
};

int parent[206];

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

bool Range(Node& a, Node& b) {
	return !(a.x2 < b.x1 || b.x2 < a.x1 || a.y2 < b.y1 || b.y2 < a.y1);
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<Node> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
			parent[i] = i;
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (Range(v[i], v[j])) {
					Union(i, j);
				}
			}
		}

		set<int> s;
		for (int i = 0; i < n; i++) {
			s.insert(Find(i));
		}

		cout << s.size() << "\n";
	}
}