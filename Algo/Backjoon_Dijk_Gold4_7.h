#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;

int t;
int n, m;
vector<pair<int, int>> v[101];
int dist[101];
int arr[101];

void Input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		v[i].clear();
	}

	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;

		v[x].push_back({ y,c });
		v[y].push_back({ x,c });
	}

	fill(dist, dist + 101, INT_MAX);
}

struct Node {
	int cost, x;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

int Dijk(int start, int endi) {
	fill(dist, dist + 101, INT_MAX);
	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().cost;
		int cx = pq.top().x;
		pq.pop();

		if (cx == endi) {
			return cost;
		}

		for (int i = 0; i < v[cx].size(); i++) {
			int next = v[cx][i].first;
			int next_cost = v[cx][i].second;

			if (cost + next_cost < dist[next]) {
				dist[next] = cost + next_cost;
				pq.push({ dist[next], next });
			}

		}
	}

	return -1;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		Input();

		int num;
		cin >> num;

		for (int i = 0; i < num; i++) {
			cin >> arr[i];
		}

		int ans = INT_MAX, ans_idx = 0;
		for (int i = 1; i <= n; i++) {
			int sum = 0;

			for (int j = 0; j < num; j++) {
				sum += Dijk(arr[j], i);
			}

			if (ans > sum) {
				ans = sum;
				ans_idx = i;
			}
		}

		cout << ans_idx << "\n";
	}
}