#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[10001] = { false, };
bool isEnd[10001];
vector<int> v[10001];
int n;

int BFS(int start) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ start, 1 });
	visited[start] = true;

	int num = 21e8;
	while (!q.empty()) {
		int curr = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (isEnd[curr]) {
			num = min(num, dist);
		}

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, dist + 1 });
			}
		}
	}

	return num;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		if (m == 0) isEnd[i] = true;

		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;

			v[i].push_back(a);
		}
	}


	int ans = BFS(1);

	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			flag = false;
		}
	}

	if (!flag) {
		cout << "N\n";
	}
	else {
		cout << "Y\n";
	}
	cout << ans;
}