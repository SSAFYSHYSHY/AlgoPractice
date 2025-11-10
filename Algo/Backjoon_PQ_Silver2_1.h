#pragma once
#include <iostream>
#include <queue>

using namespace std;

int arr[100001];
priority_queue<int> pq;
int n, m;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		pq.push(x);
	}

	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++) {
		int k = pq.top();
		pq.pop();

		if (k >= arr[i]) {
			k -= arr[i];
			pq.push(k);
		}
		else {
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}