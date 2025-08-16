#pragma once
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int f, p, c, m;
vector<pair<int, int>> v[70001];
int dist[70001];
vector<int> ans;

void Input() {
	cin >> f >> p >> c >> m;

	for (int i = 0; i < p; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;

		v[x].push_back({ y,cost });
		v[y].push_back({ x,cost });
	}
}

struct Node {
	int x, cost;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

void Dijk() {
	for (int i = 1; i <= f; i++) {
		dist[i] = INT_MAX;

	}

	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 1, 0 });
	dist[1] = 0;

	while (!pq.empty()) {
		int cx = pq.top().x;
		int ccost = pq.top().cost;
		pq.pop();

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();

	Dijk();

	for (int i = 0; i < c; i++) {
		int num;
		cin >> num;

		if (dist[num] <= m) {
			ans.push_back(i + 1);
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}