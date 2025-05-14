#pragma once
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int n, ans = 0;
int arr[1001][1001];
int dist[1001][1001];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Input() {
	memset(dist, -1, sizeof(dist));
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
}

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void Dijk(int sx, int sy) {
	priority_queue<
		pair<int, pair<int, int>>,
		vector<pair<int, pair<int, int>>>,
		greater<pair<int, pair<int, int>>>
	> pq;

	dist[sx][sy] = 0;
	pq.push({ 0, {sx, sy} });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		pq.pop();

		if (dist[cx][cy] < cost) continue; // 더 나은 경로로 이미 방문했으면 무시

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;

			int diff = abs(arr[nx][ny] - arr[cx][cy]);
			int newCost = max(cost, diff);

			if (dist[nx][ny] == -1 || dist[nx][ny] > newCost) {
				dist[nx][ny] = newCost;
				pq.push({ newCost, {nx, ny} });
			}
		}
	}

	ans = dist[n][n];
}

int main() {
	Input();
	Dijk(1, 1);
	cout << ans;
}
