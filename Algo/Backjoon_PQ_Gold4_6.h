#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	priority_queue<long long, vector<long long>, greater<long long>> pq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;

		pq.push(a);
	}

	long long ans = 0;
	while (pq.size() > 1) {
		long long a = pq.top();
		pq.pop();

		long long b = pq.top();
		pq.pop();

		long long sum = a + b;
		ans += sum;

		pq.push(sum);
	}

	cout << ans;

}