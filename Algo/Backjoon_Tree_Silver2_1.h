#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[100001];
bool visited[100001] = { false, };
int cost[100001];

int n, k, ans = 0;

void DFS(int now, int depth) {
	if (depth > k) return;

	ans += cost[now];

	for (int next : v[now]) {
		if (!visited[next]) {
			visited[next] = true;
			DFS(next, depth + 1);
			visited[next] = false;
		}
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	visited[0] = true;
	DFS(0, 0);

	cout << ans;
}