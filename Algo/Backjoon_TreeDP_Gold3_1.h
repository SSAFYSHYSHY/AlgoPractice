#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

const int MAX = 1000005;
vector<int> tree[MAX];
int dp[MAX][2];
bool visited[MAX];

int n;

void DFS(int now) {
	visited[now] = true;
	dp[now][0] = 0;
	dp[now][1] = 1;

	for (int v : tree[now]) {
		if (!visited[v]) {
			DFS(v);
			dp[now][0] += dp[v][1];
			dp[now][1] += min(dp[v][0], dp[v][1]);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1);

	cout << min(dp[1][0], dp[1][1]);
}