#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

int n, m;
char arr[501][501];
int dist[501][501];
int s_x, s_y, e_x, e_y;

int dx[] = { -1,0,1,-1,1,-1,0,1 };
int dy[] = { -1,-1,-1,0,0,1,1,1 };

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
	dist[s_x][s_y] = 0;
	pq.push({ 0, s_x,s_y });

	while (!pq.empty()) {
		int cost = pq.top().cost;
		int cx = pq.top().x;
		int cy = pq.top().y;
		pq.pop();

		if (dist[cx][cy] < cost) {
			continue;
		}

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;
			if (arr[nx][ny] == '#') continue;

			int new_cost = cost;
			if (ny <= cy) new_cost++;

			if (new_cost < dist[nx][ny]) {
				dist[nx][ny] = new_cost;
				pq.push({ new_cost, nx,ny });
			}

		}

	}


}

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];

			if (arr[i][j] == 'K') {
				s_x = i;
				s_y = j;
			}
			else if (arr[i][j] == '*') {
				e_x = i;
				e_y = j;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = INT_MAX;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Input();

	Dijk();

	if (dist[e_x][e_y] == INT_MAX) {
		cout << -1;
	}
	else {
		cout << dist[e_x][e_y];
	}
}