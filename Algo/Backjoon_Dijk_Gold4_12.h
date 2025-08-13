#pragma once
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int arr[1001][1001];
int dist[1001][1001];
int s_x, s_y;
int enemy[26];
int t, k, n, m;

void Input() {
	cin >> k >> m >> n;

	for (int i = 0; i < 26; i++) {
		enemy[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i < k; i++) {
		char a;
		int b;
		cin >> a >> b;

		enemy[(int)(a - 'A')] = b;
	}

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = (int)(s[j] - 'A');

			if (s[j] == 'E') {
				s_x = i;
				s_y = j;
			}
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct Node {
	int cost, x, y;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

void BFS() {
	priority_queue<Node, vector<Node>, greater<>> q;
	dist[s_x][s_y] = 0;
	q.push({ 0 , s_x, s_y });

	while (!q.empty()) {
		int ccost = q.top().cost;
		int cx = q.top().x;
		int cy = q.top().y;
		q.pop();

		if (cx == 0 || cx == n - 1 || cy == 0 || cy == m - 1) {
			cout << ccost << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;
			if (dist[nx][ny] != INT_MAX) continue;

			if (dist[nx][ny] > dist[cx][cy] + enemy[arr[nx][ny]]) {
				dist[nx][ny] = dist[cx][cy] + enemy[arr[nx][ny]];
				q.push({ dist[nx][ny] , nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		Input();
		BFS();
	}

}
