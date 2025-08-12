#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
long long arr[2000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (long long i = 0; i < m; i++) {
		long long x;
		cin >> x;

		long long idx = lower_bound(arr, arr + n, x) - arr;

		if (idx < n && arr[idx] == x) {
			cout << idx << "\n";
		}
		else {
			cout << -1 << "\n";
		}

	}

}