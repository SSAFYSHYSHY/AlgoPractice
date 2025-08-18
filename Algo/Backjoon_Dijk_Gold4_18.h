#pragma once
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

long long n, m;
vector<pair<long long, long long>> v[100001];
long long dist[100001][2];
long long a, b;

void Input() {
	cin >> n >> m;

	for (long long i = 0; i < m; i++) {
		long long  x, y, cost;

		cin >> x >> y >> cost;

		v[x].push_back({ y,cost });
		v[y].push_back({ x,cost });
	}

	for (long long i = 1; i <= n; i++) {
		dist[i][0] = dist[i][1] = INT_MAX;
	}

	cin >> a >> b;
}

struct Node {
	long long  x, flag, cost;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

void Dijk() {
	priority_queue<Node, vector<Node>, greater<>> pq;
	dist[a][0] = 0;
	dist[a][1] = 0;
	pq.push({ a, 0, 0 });
	pq.push({ a,1,0 });

	while (!pq.empty()) {
		long long cx = pq.top().x;
		long long cflag = pq.top().flag;
		long long ccost = pq.top().cost;
		pq.pop();

		for (long long i = 0; i < v[cx].size(); i++) {
			long long nx = v[cx][i].first;
			long long nflag = v[cx][i].second;

			long long ncost = ccost + (cflag != nflag ? 1 : 0);

			if (dist[nx][nflag] > ncost) {
				dist[nx][nflag] = ncost;
				pq.push({ nx, nflag, ncost });
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

	cout << min(dist[b][0], dist[b][1]);
}