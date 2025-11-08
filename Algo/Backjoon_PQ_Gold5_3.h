#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
vector<int> v;
int ans[300001];

int main() {
	priority_queue<pair<int, int>> pq;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		int num;
		cin >> num;

		pq.push({ num,i });
	}

	if (pq.top().first > (n + 1) / 2) {
		cout << -1;
		return 0;
	}

	while (!pq.empty()) {
		const int cnt = pq.top().first;
		const int num = pq.top().second;
		pq.pop();

		for (int i = 0; i < cnt; i++) {
			v.push_back(num);
		}
	}

	int num = 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		ans[num] = v[i];
		num += 2;
	}

	num = 1;
	for (int i = (n + 1) / 2; i < n; i++) {
		ans[num] = v[i];
		num += 2;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}