#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstring>

using namespace std;

int parent[200002];
int sz[200002];

int Find(int num) {
	if (parent[num] == num) return num;
	return parent[num] = Find(parent[num]);
}

int Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) {
		parent[b] = a;
		sz[a] += sz[b];
	}

	return sz[a];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int num;
		cin >> num;

		map<string, int> mp;
		int idx = 0;

		for (int i = 0; i < num * 2; i++) {
			parent[i] = i;
			sz[i] = 1;
		}

		while (num--) {
			string a, b;
			cin >> a >> b;

			if (!mp.count(a)) mp[a] = idx++;
			if (!mp.count(b)) mp[b] = idx++;

			int x = mp[a];
			int y = mp[b];

			cout << Union(x, y) << "\n";
		}
	}

}