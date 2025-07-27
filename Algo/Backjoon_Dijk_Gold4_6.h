#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int v, e, p;
vector<pair<int, int>> arr[5001];
int dist[5001];

void Input() {
	cin >> v >> e >> p;

	for (int i = 0; i < e; i++) {
		int x, y, c;
		cin >> x >> y >> c;

		arr[x].push_back({ y,c });
		arr[y].push_back({ x,c });
	}
}

struct Node {
	int cost, now;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

int Dijk(int start, int endi) {
	fill(dist, dist + 5001, INT_MAX);
	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().cost;
		int cnow = pq.top().now;
		pq.pop();

		if (cnow == endi) {
			return cost;
		}

		for (int i = 0; i < arr[cnow].size(); i++) {
			int cnext = arr[cnow][i].first;
			int cnext_cost = arr[cnow][i].second;

			if (cost + cnext_cost < dist[cnext]) {
				dist[cnext] = cost + cnext_cost;
				pq.push({ dist[cnext], cnext });
			}
		}
	}

	return -1;
}

int main() {
	Input();

	int direct = Dijk(1, v);
	int via_p = Dijk(1, p) + Dijk(p, v);

	if (direct >= via_p) {
		cout << "SAVE HIM";
	}
	else {
		cout << "GOOD BYE";
	}

}