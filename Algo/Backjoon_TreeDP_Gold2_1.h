#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10001][2];
int arr[10001];

vector<int> v[10001];
bool visited[10001] = { false, };

void DFS(int now) {

	dp[now][0] = 0;
	dp[now][1] = arr[now];
	visited[now] = true;

	for (auto next : v[now]) {
		if (!visited[next]) {
			DFS(next);
			dp[now][0] += max(dp[next][0], dp[next][1]);
			dp[now][1] += dp[next][0];
		}

	}

}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	DFS(1);

	cout << max(dp[1][0], dp[1][1]);
}