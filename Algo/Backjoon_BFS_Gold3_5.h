#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, a, b;

//턴 수로 나눈다.
int visited[500001][2] = { 0, };

bool InRange(int x) {
	return 1 <= x && x <= 500000;
}

void BFS(int start, int idx) {
	queue<pair<int, int>> q;
	q.push({ start , 0 });
	visited[start][idx] = 0;

	while (!q.empty()) {
		int pos = q.front().first;
		int turn = q.front().second;
		q.pop();

		int move = 1 << turn;

		for (int dir : {-1, 1}) {
			int next = pos + (dir * move);

			if (InRange(next) && visited[next][idx] == -1) {
				visited[next][idx] = turn + 1;
				q.push({ next, turn + 1 });
			}
		}
	}
}

int main() {
	memset(visited, -1, sizeof(visited));

	cin >> n >> a >> b;

	BFS(a, 0);
	BFS(b, 1);

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			cout << visited[j][i] << " ";
		}
		cout << "\n\n";
	}

	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (visited[i][0] != -1 && visited[i][1] != -1 && visited[i][0] == visited[i][1]) {
			if (ans == -1 || visited[i][0] < ans) {
				ans = visited[i][0];
			}
		}
	}

	cout << ans;

}