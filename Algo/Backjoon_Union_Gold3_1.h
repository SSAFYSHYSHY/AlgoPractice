#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m;
vector<string> grid;
vector<int> parent;

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

	cin >> n >> m;
	grid.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	parent.resize(n * m);
	for (int i = 0; i < n * m; i++) {
		parent[i] = i;
	}

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };
	char dir[] = { 'N','S','W','E' };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cur = i * m + j;
			int nx = i;
			int ny = j;

			if (grid[i][j] == 'N') nx--;
			else if (grid[i][j] == 'S') nx++;
			else if (grid[i][j] == 'W') ny--;
			else if (grid[i][j] == 'E') ny++;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			int next = nx * m + ny;
			Union(cur, next);
		}
	}

	unordered_set<int> s;
	for (int i = 0; i < n * m; i++) {
		s.insert(Find(i));
	}

	cout << s.size() << "\n";
}