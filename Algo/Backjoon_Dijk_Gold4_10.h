#pragma once
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <climits>

using namespace std;

int t;
int n, m, d, sx, sy, ex, ey;
char arr[501][501];
int dist[501][501];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Input() {

	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];

			if (arr[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

struct Node {
	int cost, x, y;

	bool operator>(const Node& other) {
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
	pq.push({ 0,sx,sy });
	dist[sx][sy] = 0;

	while (!pq.empty()) {
		int ccost = pq.top().cost;
		int cx = pq.top().x;
		int cy = pq.top().y;
		pq.pop();

		if (cx == 0 || cy == 0 || cx == n - 1 || cy == m - 1) {
			cout << ccost + 1 << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;
			if (arr[nx][ny] == '#') continue;

			int cost = (arr[nx][ny] == '.' ? 1 : (d + 1));

			if (dist[nx][ny] > dist[cx][cy] + cost) {
				dist[nx][ny] = dist[cx][cy] + cost;
				pq.push({ dist[nx][ny], nx,ny });
			}
		}
	}
}

int main() {
	cin >> t;

	while (t--) {
		Input();

		Dijk();
	}
}