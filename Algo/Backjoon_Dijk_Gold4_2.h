#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1000000000

using namespace std;

int n, m, r, ans;
int arr[101];
int dist[101];
vector<pair<int, int>> v[101];

void Dijk(int idx) {
	int cnt = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
	}
	dist[idx] = 0;
	q.push(idx);

	while (!q.empty()) {
		int cx = q.front();
		int cdist = dist[cx];
		q.pop();

		for (int i = 0; i < v[cx].size(); i++) {
			int nx = v[cx][i].first;
			int ndist = v[cx][i].second;

			if (dist[nx] > cdist + ndist) {
				dist[nx] = cdist + ndist;
				q.push(nx);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] <= m) {
			cnt += arr[i];
		}
	}
	ans = max(ans, cnt);
}

int main() {

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < r; i++) {
		int x, y, l;
		cin >> x >> y >> l;

		v[x].push_back({ y,l });
		v[y].push_back({ x,l });
	}

	for (int i = 1; i <= n; i++) {
		Dijk(i);
	}

	cout << ans;

}