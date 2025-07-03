#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, x;
vector<int> v[100001];
vector<int> rev_v[100001];

int BFS(vector<int> graph[], int start) {
	bool visited[100001] = { false };
	queue<int> q;
	int cnt = -1;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		cnt++;

		for (int next : graph[curr]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}

	return cnt;
}

int main() {
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		rev_v[b].push_back(a);
	}

	int high = BFS(rev_v, x);
	int low = BFS(v, x);

	cout << high + 1 << " " << n - low;
}