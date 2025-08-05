#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n, p, k;
vector<pair<int, int>> v[1001];

void Input() {
	cin >> n >> p >> k;

	for (int i = 0; i < p; i++) {
		int x, y, c;
		cin >> x >> y >> c;

		v[x].push_back({ y,c });
		v[y].push_back({ x,c });
	}
}

bool Calc(int mid) {
	int dist[1001];
	for (int i = 0; i <= n; i++) {
		dist[i] = INT_MAX;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0 , 1 });
	dist[1] = 0;

	while (!pq.empty()) {
		int cnt = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cnt) continue;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int cost = v[now][i].second;

			int ncnt = cnt;

			if (cost > mid) ncnt += 1;
			if (ncnt < dist[next]) {
				dist[next] = ncnt;
				pq.push({ ncnt, next });
			}
		}
	}

	return dist[n] <= k;
}

int main() {
	Input();

	int l = 0, r = 1000000;
	int ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (Calc(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;
}