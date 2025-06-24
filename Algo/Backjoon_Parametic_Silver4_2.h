#pragma once
#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;

	long long total = n * (n - 1) / 2;
	long long half = (total + 1) / 2;

	long long l = 1, h = n, ans = -1;

	while (l <= h) {
		long long mid = (l + h) / 2;

		long long comps = mid * n - mid * (mid + 1) / 2;

		if (comps >= half) {
			ans = mid;
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;
}