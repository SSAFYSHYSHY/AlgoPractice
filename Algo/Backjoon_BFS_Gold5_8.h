#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

long long  n, m, k, cnt = 0;

bool visited[100001] = { false, };
vector<long long > v[100001];

void BFS() {
	queue<long long > q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		long long  cx = q.front();
		q.pop();

		for (long long i = 0; i < v[cx].size(); i++) {
			long long  nx = v[cx][i];

			if (visited[nx]) continue;

			q.push(nx);
			visited[nx] = true;
			cnt++;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(visited, false, sizeof(visited));

	cin >> n >> m >> k;

	for (long long i = 0; i < m; i++) {
		long long  x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (long long i = 0; i < k; i++) {
		long long  num;
		cin >> num;

		visited[num] = true;
	}

	BFS();

	cout << cnt;
}