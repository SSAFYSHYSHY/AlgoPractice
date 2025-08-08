#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

long long n, v, e, ans = 0;
vector<pair<long long, long long>> vv[1001];
long long k, c;
long long arr[1001];
long long dist[1001];

void Input() {
	cin >> n >> v >> e;
	cin >> k >> c;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < e; i++) {
		long long x, y, c;

		cin >> x >> y >> c;

		vv[x].push_back({ y,c });
		vv[y].push_back({ x,c });
	}

}

struct Node {
	long long cost, x;

	bool operator>(const Node& other) {
		return cost > other.cost;
	}
};

void Dijk(int now) {
	for (int i = 1; i <= v; i++) {
		dist[i] = LLONG_MAX;
	}

	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 0, arr[now] });
	dist[arr[now]] = 0;

	while (!pq.empty()) {
		long long ccost = pq.top().cost;
		long long cx = pq.top().x;
		pq.pop();

		for (int i = 0; i < vv[cx].size(); i++) {
			long long ncost = vv[cx][i].second;
			long long nx = vv[cx][i].first;

			if (dist[nx] > dist[cx] + ncost) {
				dist[nx] = dist[cx] + ncost;
				pq.push({ dist[nx] , nx });
			}
		}
	}

	long long k_ans = dist[k];
	long long c_ans = dist[c];

	if (k_ans == LLONG_MAX) {
		k_ans = -1;
	}
	if (c_ans == LLONG_MAX) {
		c_ans = -1;
	}

	ans += (k_ans + c_ans);

}

int main() {
	Input();

	for (int i = 1; i <= n; i++) {
		Dijk(i);
	}

	cout << ans;
}

