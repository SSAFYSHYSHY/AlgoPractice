#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#define MAX 1000001

using namespace std;

int parent[1000001];
int sz[1000001];
int t;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) {
		parent[b] = a;
		sz[a] += sz[b];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	for (int i = 1; i <= MAX; i++) {
		parent[i] = i;
		sz[i] = 1;
	}

	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		if (s == "I") {
			int a, b;
			cin >> a >> b;

			Union(a, b);
		}
		else {
			int a;
			cin >> a;

			int root = Find(a);
			cout << sz[root] << "\n";
		}
	}

}