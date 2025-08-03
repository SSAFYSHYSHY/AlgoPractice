#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long n, t, ans = 0;
long long arr[100001];

bool Calc(int mid) {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < mid; i++) {
		pq.push(arr[i]);
	}

	for (int i = mid; i < n; i++) {
		int temp = pq.top();
		pq.pop();

		if (temp + arr[i] > t) {
			return false;
		}
		else {
			pq.push(temp + arr[i]);
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int l = 1, r = n;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (Calc(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}

	}

	cout << ans;

}