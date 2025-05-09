#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long n, k, x;
long long arr[200001];
long long prefix[200001];

bool Calc(long long mid) {

	for (int start = 0; start + mid <= n; start++) {
		long long bonus = prefix[start];
		long long after = prefix[n] - prefix[start + mid];

		long long total = bonus * x + after;

		if (total >= k) return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> x;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		prefix[i] = prefix[i - 1] + arr[i];
	}

	long long l = 1, r = n;
	long long ans = -1;

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