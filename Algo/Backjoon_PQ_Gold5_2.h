#pragma once
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, ans = 0;
priority_queue<int> pq;

int main() {
	cin >> n >> m;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		pq.push(num);
		sum += num;

		while (sum >= m) {
			ans++;
			sum -= (pq.top() * 2);
			pq.pop();
		}
	}

	cout << ans;
}