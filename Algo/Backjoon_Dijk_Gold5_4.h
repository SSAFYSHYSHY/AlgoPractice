#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n, e, t, m, ans = 0;
int dist[101];
vector<pair<int, int>> v[101];

void Input() {
	cin >> n >> e >> t >> m;

	for (int i = 0; i < m; i++) {
		int x = 0, y = 0, cost = 0;
		cin >> x >> y >> cost;

		v[x].push_back({ y,cost });
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}
}

struct Node {
	int x, cost;

	bool operator>(const Node& other) {
		return cost > other.cost;
	}
};

bool Dijk(int idx) {
	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}

	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ idx, 0 });
	dist[idx] = 0;

	while (!pq.empty()) {
		int cx = pq.top().x;
		int ccost = pq.top().cost;
		pq.pop();

		if (cx == e) {
			if (ccost <= t) {
				return true;
			}
			return false;
		}

		for (int i = 0; i < v[cx].size(); i++) {
			int nx = v[cx][i].first;
			int ncost = v[cx][i].second;

			if (dist[nx] > dist[cx] + ncost) {
				dist[nx] = dist[cx] + ncost;
				pq.push({ nx, dist[nx] });
			}
		}
	}
}

int main() {
	Input();

	for (int i = 1; i <= n; i++) {
		if (Dijk(i)) {
			ans++;
		}
	}

	cout << ans;
}