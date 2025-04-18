#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int n, ans = 21e8;
int MAX = 98765432;

vector<pair<int, int>> v[802];
int dist[802];

void BFS(int idx) {
	memset(dist, MAX, sizeof(dist));
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, idx });
	dist[idx] = 0;

	while (!pq.empty()) {
		int c_dist = pq.top().first;
		int c_idx = pq.top().second;
		pq.pop();

		if (dist[c_idx] < c_dist) continue;

		for (int i = 0; i < v[c_idx].size(); i++) {
			int nx = v[c_idx][i].first;
			int ncost = c_dist + v[c_idx][i].second;

			if (dist[nx] > ncost) {
				pq.push({ ncost,nx });
				dist[nx] = ncost;
			}
		}
	}
}

int Calc(int a, int b) {
	if (a < b) return a;
	return b;
}

int main() {
	int n, e;
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int x, y;
	cin >> x >> y;

	BFS(1);
	int x1 = dist[x];
	int y1 = dist[y];

	BFS(x);
	int x1_y1 = dist[y];
	int x1_n = dist[n];

	BFS(y);
	int y1_n = dist[n];
	int ans;

	ans = Calc(MAX, x1 + x1_y1 + y1_n);
	ans = Calc(ans, y1 + x1_y1 + x1_n);

	if (ans >= MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}