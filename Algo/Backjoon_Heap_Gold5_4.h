#pragma once
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < min(m, n); i++) {
		pq.push(v[i]);
	}

	for (int i = m; i < n; i++) {
		int top = pq.top();
		pq.pop();
		pq.push(v[i] + top);
	}

	while (pq.size() != 1) {
		pq.pop();
	}

	cout << pq.top() << "\n";
}
