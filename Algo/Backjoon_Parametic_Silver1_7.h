#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long n;
long long arr[50001];

bool Calc(long long mid) {
	long long cnt = 0;
	for (long long i = 0; i < n; i++) {
		if (mid * (i + 1) > arr[i]) {
			return false;
		}
	}

	return true;
}

int main() {
	cin >> n;

	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	long long l = 1, r = 1000000000;
	long long ans = 0;

	while (l <= r) {
		long long mid = (l + r) / 2;

		if (Calc(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ans;
}