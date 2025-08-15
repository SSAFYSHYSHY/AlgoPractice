#pragma once
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
bool bad[10001];
bool visited[10001][151];

struct Node {
	int x, v, cnt;
};

bool InRange(int x) {
	return 1 <= x && x <= n && !bad[x];
}

void BFS() {

	queue<Node> q;
	//현 위치, 속도, 횟수.
	q.push({ 1,0,0 });
	visited[1][0] = true;

	while (!q.empty()) {
		int cx = q.front().x;
		int cv = q.front().v;
		int ccnt = q.front().cnt;
		q.pop();

		if (cx == n) {
			cout << ccnt;
			return;
		}

		for (int i = -1; i <= 1; i++) {
			int nv = cv + i;
			if (nv <= 0) continue;

			int nx = cx + nv;

			if (InRange(nx) && !visited[nx][nv]) {
				visited[nx][nv] = true;
				q.push({ nx , nv, ccnt + 1 });
			}
		}
	}

	cout << -1;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(visited, false, sizeof(visited));

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		bad[num] = true;
	}

	BFS();
}