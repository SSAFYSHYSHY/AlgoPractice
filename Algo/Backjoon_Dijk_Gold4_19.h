#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

#define MAX 1000000000

using namespace std;

int n, m, ans = 0;
int arr[1001][1001];
int dist[1001][1001];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

struct Node {
	int x, y, cost;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool Calc(int mid) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = INT_MAX;
		}
	}

	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ 0,0,0 });
	dist[0][0] = 0;

	while (!pq.empty()) {
		int cx = pq.top().x;
		int cy = pq.top().y;
		int ccost = pq.top().cost;
		pq.pop();

		if (cx == n - 1 && cy == m - 1) {
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			//높이차.
			int diff = (arr[nx][ny] - arr[cx][cy]);

			//범위 외 그리고 차이가 mid 보다 큰 경우 이동 불가 높이.
			if (!InRange(nx, ny)) continue;
			if (diff > mid) continue;

			if (dist[nx][ny] > ccost + 1) {
				dist[nx][ny] = ccost + 1;
				pq.push({ nx,ny, dist[nx][ny] });
			}


		}

	}

	return false;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	Input();

	int l = 0, r = MAX;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (Calc(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans << "\n";
}