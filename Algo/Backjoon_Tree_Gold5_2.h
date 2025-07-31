#pragma once
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, ans = 0;
int arr[200001];
vector<int> v[200001];

void DFS(int now, int num) {
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];

		if (next == num) continue;

		if (arr[now] != arr[next]) {
			ans++;
		}
		DFS(next, now);
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < (n - 1); i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	if (arr[1] != 0) ans++;
	DFS(1, 0);

	cout << ans;
}