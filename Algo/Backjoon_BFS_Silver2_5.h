#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

long long n, m, r;
vector<long long> v[100001];
long long visited[100001] = { -1, };
long long arr[100001] = { 0, };

void BFS() {
	memset(visited, -1, sizeof(visited));
	queue<long long> q;
	visited[r] = 0;
	arr[r] = 1;
	long long num = 1;

	q.push(r);

	while (!q.empty()) {
		long long now = q.front();
		arr[now] = num++;
		q.pop();

		for (long long i = 0; i < v[now].size(); i++) {
			long long next = v[now][i];
			if (visited[next] == -1) {
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> m >> r;

	for (long long i = 0; i < m; i++) {
		long long x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (long long i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	BFS();

	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		ans += visited[i] * arr[i];
	}
	cout << ans;
}