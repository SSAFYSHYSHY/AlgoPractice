#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
vector<vector<int>> v(100001);
int n, m;

int main() {
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;

		arr[y]++;
		v[x].push_back(y);
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			pq.push(i);
			arr[i] -= 1;
		}
	}

	while (!pq.empty()) {
		int curr = pq.top();
		pq.pop();

		cout << curr << " ";

		for (int i = 0; i < v[curr].size(); i++) {
			if (--arr[v[curr][i]] == 0) {
				pq.push(v[curr][i]);
				arr[v[curr][i]] = -1;
			}
		}
	}
}