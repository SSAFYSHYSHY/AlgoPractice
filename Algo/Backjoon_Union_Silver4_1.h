#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int parent[106];

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
	int n;
	cin >> n;

	map<string, int> id;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;

		id[name] = i;
		parent[i] = i;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;

		Union(id[a], id[b]);
	}

	int g = 0;
	for (int i = 0; i < n; i++) {
		if (parent[i] == i) g++;
	}

	cout << g;
}