#pragma once
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
char arr[401][401];
int dist[401][401];
int sx, sy;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
			dist[i][j] = INT_MAX;
		}
	}

	cin >> sx >> sy;
	sx--;
	sy--;
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
	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 0, sx,sy });
	dist[sx][sy] = 0;

	while (!pq.empty()) {
		int cx = pq.top().x;
		int cy = pq.top().y;
		int ccost = pq.top().cost;
		pq.pop();

		if (cx == 0 || cx == n - 1 || cy == 0 || cy == m - 1) {
			cout << ccost + 1;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;
			if (arr[nx][ny] == '#') continue;

			int cost = (arr[nx][ny] == 'c' ? 1 : 0);

			if (dist[nx][ny] > dist[cx][cy] + cost) {
				dist[nx][ny] = dist[cx][cy] + cost;
				pq.push({ dist[nx][ny], nx,ny });
			}
		}
	}
}

int main() {
	Input();

	Dijk();
}