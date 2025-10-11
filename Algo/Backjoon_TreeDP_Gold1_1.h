#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
int arr[100001];
vector<int> v[100001];
int dp[100001][2];
vector<int> path[100001][2];
vector<int> ans;
bool visited[100001] = { false, };

void DFS(int node) {
	visited[node] = true;
	dp[node][0] = 0;
	dp[node][1] = arr[node];

	path[node][0].clear();
	path[node][1] = { node };

	for (int next : v[node]) {
		if (!visited[next]) {

			DFS(next);

			//node 선택시.
			if (dp[next][0] > dp[next][1]) {
				dp[node][0] += dp[next][0];
				path[node][0].insert(path[node][0].end(), path[next][0].begin(), path[next][0].end());
			}
			else {
				dp[node][0] += dp[next][1];
				path[node][0].insert(path[node][0].end(), path[next][1].begin(), path[next][1].end());

			}

			//node 비선택
			dp[node][1] += dp[next][0];
			path[node][1].insert(path[node][1].end(), path[next][0].begin(), path[next][0].end());
		}
	}
}

int main() {
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

	if (dp[1][0] > dp[1][1]) {
		cout << dp[1][0] << "\n";
		sort(path[1][0].begin(), path[1][0].end());
		for (auto x : path[1][0]) {
			cout << x << " ";
		}
	}
	else {
		cout << dp[1][1] << "\n";
		sort(path[1][1].begin(), path[1][1].end());
		for (auto x : path[1][1]) {
			cout << x << " ";
		}
	}

}