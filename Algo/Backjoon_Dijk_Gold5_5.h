#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

long long n, m, s, c;
vector<pair<long long, long long>> v[100001];
long long dist[100001];

void Input() {

	for (long long i = 0; i < m; i++) {
		long long x, y, cost;
		cin >> x >> y >> cost;

		v[x].push_back({ y,cost });
	}

	for (long long i = 1; i <= n; i++) {
		dist[i] = LLONG_MAX;
	}
}

struct Node {
	long long x, cost;

	bool operator>(const Node& other) {
		return cost > other.cost;
	}
};

void Dijk() {
	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ s,0 });
	dist[s] = 0;

	while (!pq.empty()) {
		long long cx = pq.top().x;
		long long ccost = pq.top().cost;
		pq.pop();

		if (cx == c) {
			cout << ccost << "\n";
			return;
		}

		for (long long i = 0; i < v[cx].size(); i++) {
			long long nx = v[cx][i].first;
			long long ncost = v[cx][i].second;

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

	while (1) {
		cin >> n >> m >> s >> c;

		if (n + m + s + c == 0) break;

		Input();
		Dijk();

		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}
	}

}