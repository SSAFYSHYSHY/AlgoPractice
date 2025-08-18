#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int n, s, m;
int dist[10001];
vector<pair<int, int>> ans;
vector<pair<int, int>> v[10001];

struct Node {
	int x, cost;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

void Dijk() {
	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 1,0 });
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

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;

	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}

	for (int i = 0; i < s; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;

		v[x].push_back({ y, cost });
		v[y].push_back({ x,cost });
	}

	Dijk();

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		ans.push_back({ num, dist[num] });
	}

	sort(ans.begin(), ans.end(), cmp);

	cout << ans[0].first << " " << ans[0].second << "\n";


}
