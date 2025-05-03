#pragma once
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long n, k;
long long arr[1000001];

bool Calc(long long mid) {
	long long sum = (mid * (mid + 1)) / 2;

	for (int i = 0; i < n - 1; i++) {
		long long temp = arr[i + 1] - arr[i];
		long long diff = min(mid, temp);

		sum += mid * diff - (diff - 1) * diff / 2;
	}

	if (sum >= k) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long l = 1, r = 1500000000;
	long long ans = LLONG_MAX;
	while (l <= r) {
		long long mid = (l + r) / 2;

		if (Calc(mid)) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans;
}