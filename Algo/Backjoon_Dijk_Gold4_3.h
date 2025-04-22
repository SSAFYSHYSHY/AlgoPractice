#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

int t, n, d, c;
int arr[10001];

void Dijk(vector<pair<int, int>> v[]) {
	arr[c] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,c });

	while (!pq.empty()) {
		int cdir = pq.top().first;
		int cx = pq.top().second;
		pq.pop();

		if (arr[cx] < cdir) continue;

		for (int i = 0; i < v[cx].size(); i++) {
			int nx = v[cx][i].first;
			int ndir = cdir + v[cx][i].second;

			if (ndir < arr[nx]) {
				arr[nx] = ndir;
				pq.push({ ndir, nx });
			}
		}
	}

	int cnt = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] != INF) {
			cnt++;
			ans = max(ans, arr[i]);
		}
	}

	cout << cnt << " " << ans << "\n";
}

int main() {
	cin >> t;

	while (t--) {
		cin >> n >> d >> c;
		vector<pair<int, int>> v[10001];

		for (int i = 0; i < d; i++) {
			int x, y, dir;
			cin >> x >> y >> dir;

			v[y].push_back({ x,dir });
		}

		fill_n(arr, 10001, INF);
		Dijk(v);
	}
}
