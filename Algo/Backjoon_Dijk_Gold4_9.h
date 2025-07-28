#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n, m, ans = 0;
int dist[1001][1001];
int arr[1001][1001];

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			dist[i][j] = INT_MAX;
		}
	}
}

struct Node {
	int cost, x, y;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void Dijk() {
	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ arr[0][0], 0,0 });
	dist[0][0] = arr[0][0];

	while (!pq.empty()) {
		int cost = pq.top().cost;
		int cx = pq.top().x;
		int cy = pq.top().y;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;
			if (arr[nx][ny] == -1) continue;

			if (cost + arr[nx][ny] < dist[nx][ny]) {
				dist[nx][ny] = cost + arr[nx][ny];
				pq.push({ dist[nx][ny] , nx, ny });
			}
		}
	}
}

int main() {
	Input();

	if (arr[0][0] == -1) {
		cout << -1;
		return 0;
	}

	Dijk();

	if (dist[n - 1][m - 1] == INT_MAX) cout << -1;
	else {
		cout << dist[n - 1][m - 1];
	}
}