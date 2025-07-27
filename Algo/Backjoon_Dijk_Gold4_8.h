#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <climits>
#include <vector>

using namespace std;

int n, m, a, b, c;
vector<pair<int, int>> v[100001];

void Input() {
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;

		v[x].push_back({ y,c });
		v[y].push_back({ x,c });
	}
}

struct Node {
	int cost, x;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

vector<int> Dijk(int starti) {
	vector<int> dist(n + 1, INT_MAX);
	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 0, starti });
	dist[starti] = 0;

	while (!pq.empty()) {
		int cost = pq.top().cost;
		int cx = pq.top().x;
		pq.pop();

		if (cost > dist[cx]) continue;

		for (int i = 0; i < v[cx].size(); i++) {
			int next = v[cx][i].first;
			int next_cost = v[cx][i].second;

			if (cost + next_cost < dist[next]) {
				dist[next] = cost + next_cost;
				pq.push({ dist[next], next });
			}
		}
	}

	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b >> c;
	cin >> m;

	Input();

	vector<int> dA = Dijk(a);
	vector<int> dB = Dijk(b);
	vector<int> dC = Dijk(c);

	int ans = -1, ans_idx = 0;
	for (int i = 1; i <= n; i++) {
		int mini = max({ dA[i], dB[i], dC[i] });
		if (mini == 0) continue;

		if (ans < mini) {
			ans = mini;
			ans_idx = i;
		}
		else if (ans == mini && i < ans_idx) {
			ans_idx = i;
		}
	}

	cout << ans_idx;

}