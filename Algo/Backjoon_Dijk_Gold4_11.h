#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;

int n, m, t;
int sx, sy, ex, ey;

int arr[1001][1001];
int dist[1001][1001];

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = (int)(s[j] - '0');
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

struct Node {
	int cost, x, y;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

void Dijk() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = INT_MAX;
		}
	}

	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 0, sx,sy });
	dist[sx][sy] = 0;

	while (!pq.empty()) {
		int cx = pq.top().x;
		int cy = pq.top().y;
		int ccost = pq.top().cost;
		pq.pop();

		if (ccost > dist[cx][cy]) continue;
		if (cx == ex && cy == ey) {
			cout << ccost << "\n";
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;

			int cost = (i == arr[cx][cy] ? 0 : 1);

			if (dist[nx][ny] > dist[cx][cy] + cost) {
				dist[nx][ny] = dist[cx][cy] + cost;
				pq.push({ dist[nx][ny] , nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();

	cin >> t;

	while (t--) {
		cin >> sx >> sy >> ex >> ey;
		sx--;
		sy--;
		ex--;
		ey--;

		Dijk();
	}
}
