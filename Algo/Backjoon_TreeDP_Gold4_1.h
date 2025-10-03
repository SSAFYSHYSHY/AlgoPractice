#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
bool visited[100001] = { false, };
int arr[100001];
vector<int> v[100001];
long long dp[100001];

void DFS(int now) {
	dp[now] = arr[now];
	visited[now] = true;

	for (auto next : v[now]) {
		if (!visited[next]) {
			DFS(next);

			if (dp[next] > 0) {
				dp[now] += dp[next];
			}
		}

	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	DFS(0);

	cout << dp[0] << "\n";
}