#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> v[100001];
bool visited[100001];

long long total_dist = 0, max_dist = 0;

void DFS(int node, long long dist) {
	visited[node] = true;
	max_dist = max(max_dist, dist);

	for (auto i : v[node]) {
		int next = i.first;
		int cost = i.second;

		if (!visited[next]) {
			total_dist += cost;
			DFS(next, dist + cost);
		}
	}
}

int main() {
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	DFS(s, 0);

	cout << (total_dist * 2 - max_dist) << "\n";
}