#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

int t, n, m, ans = 0;
char arr[103][103];
int dist[3][103][103];

int s_x, s_y, e_x, e_y;

void Input() {
	cin >> n >> m;

	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			arr[i][j] = '.';
		}
	}

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;

		for (int j = 1; j <= m; j++) {
			arr[i][j] = s[j - 1];

			if (arr[i][j] == '$') {
				if (!flag) {
					s_x = i;
					s_y = j;
					flag = true;
				}
				else {
					e_x = i;
					e_y = j;
				}
				arr[i][j] = '.';
			}

		}
	}
}

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct Node {
	int cost, x, y;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

bool InRange(int x, int y) {
	return 0 <= x && x <= n + 1 && 0 <= y && y <= m + 1;
}

void Dijk(int idx, int x, int y) {
	priority_queue<Node, vector<Node>, greater<>> pq;

	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			dist[idx][i][j] = INT_MAX;
		}
	}

	pq.push({ 0,x,y });
	dist[idx][x][y] = 0;

	while (!pq.empty()) {
		int cx = pq.top().x;
		int cy = pq.top().y;
		int ccost = pq.top().cost;
		pq.pop();

		if (dist[idx][cx][cy] < ccost) continue;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!InRange(nx, ny)) continue;
			if (arr[nx][ny] == '*') continue;

			int ncost = ccost + (arr[nx][ny] == '#' ? 1 : 0);
			if (dist[idx][nx][ny] > ncost) {
				dist[idx][nx][ny] = ncost;
				pq.push({ ncost, nx,ny });
			}
		}
	}
}

int main() {

	cin >> t;

	while (t--) {
		Input();

		Dijk(0, 0, 0);
		Dijk(1, s_x, s_y);
		Dijk(2, e_x, e_y);

		int ans = INT_MAX;

		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				if (arr[i][j] == '*') continue;

				int sum = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];

				if (arr[i][j] == '#') {
					sum -= 2;
				}

				ans = min(ans, sum);
			}
		}


		cout << ans << "\n";
	}


}