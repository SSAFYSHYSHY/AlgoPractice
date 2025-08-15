#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int t, n, m, sx, sy, num, ex, ey;
char arr[101][101];
int dist[101][101];

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

void Input() {
	cin >> n >> m;

	int num = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];

			if ((int)(arr[i][j] - '0') > num) {
				num = (int)(arr[i][j] - '0');
				ex = i;
				ey = j;
			}
		}
	}

	cin >> sx >> sy;
}

struct Node {
	int cost, x, y;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = INT_MAX;
		}
	}

	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 0, sx, sy });
	dist[sx][sy] = 0;

	while (!pq.empty()) {
		int ccost = pq.top().cost;
		int cx = pq.top().x;
		int cy = pq.top().y;
		pq.pop();

		if (cx == ex && cy == ey) {
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;
			if (arr[nx][ny] == '#') continue;

			//같은 높이인 경우.
			if (arr[nx][ny] == arr[cx][cy]) {
				if (dist[nx][ny] > dist[cx][cy] + 1) {
					dist[nx][ny] = dist[cx][cy] + 1;
					pq.push({ dist[nx][ny] , nx, ny });
				}
			}
			//다르면 제곱.
			else {
				int d = abs(arr[nx][ny] - arr[cx][cy]);

				if (dist[nx][ny] > dist[cx][cy] + ((d + 1) * (d + 1))) {
					dist[nx][ny] = dist[cx][cy] + ((d + 1) * (d + 1));
					pq.push({ dist[nx][ny] , nx, ny });
				}
			}
		}
	}

}

int main() {
	cin >> t;

	while (t--) {
		Input();

		BFS();

		if (dist[ex][ey] == INT_MAX) {
			cout << "NO\n";
		}
		else {
			cout << dist[ex][ey] << "\n";
		}
	}

}