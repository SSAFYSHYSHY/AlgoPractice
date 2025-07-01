#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m, k;
vector<int> v[1001];
bool visited[1001];
int match[1001];

bool DFS(int idx) {
	for (int curr : v[idx]) {
		if (visited[curr]) continue;

		visited[curr] = true;

		if (match[curr] == 0 || DFS(match[curr])) {
			match[curr] = idx;
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		while (num--) {
			int x;
			cin >> x;

			v[i].push_back(x);
		}
	}

	int ans = 1;
	//1명씩.
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (DFS(i)) {
			ans++;
		}
	}

	//k 명만 2 번씩 가능. 노드 n+1 ~ n + k
	for (int i = n + 1; i <= n + k; i++) {
		//가상 노드는 실제 직원과 동일 직군.
		v[i] = v[i - k];
		memset(visited, false, sizeof(visited));
		if (DFS(i)) {
			ans++;
		}

	}

	cout << ans;
}

#pragma once
