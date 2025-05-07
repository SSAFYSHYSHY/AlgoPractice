#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		int n, p;
		cin >> n >> p;

		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());

		vector<long long> prefix(n + 1, 0);
		for (int i = 0; i < n; i++) {
			prefix[i + 1] = prefix[i] + v[i];
		}

		long long ans = 1e18;
		for (int i = p - 1; i < n; i++) {
			int high = v[i];
			long long sum = prefix[i + 1] - prefix[i + 1 - p];
			long long cost = (long long)high * p - sum;

			ans = min(ans, cost);
		}

		cout << "Case #" << tc << ": " << ans << "\n";
	}
}