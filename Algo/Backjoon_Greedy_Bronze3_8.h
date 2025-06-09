#pragma once
#include <iostream>

using namespace std;

int main() {
	long long k;
	cin >> k;

	for (long long t = 1; t <= k; t++) {
		long long n, w, e;
		cin >> n >> w >> e;

		long long ans = 0;

		for (long long i = 0; i < n; i++) {
			long long lw_w, lw_e, le_w, le_e;
			cin >> lw_w >> lw_e >> le_w >> le_e;

			long long west = w * lw_w + e * le_w;
			long long east = w * lw_e + e * le_e;

			ans += max(west, east);
		}

		cout << "Data Set " << t << ":\n";
		cout << ans << "\n\n";
	}


}