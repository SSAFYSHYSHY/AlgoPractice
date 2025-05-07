#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[1001], prefix[1001], prefix_double[1001];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		prefix[i] = prefix[i - 1] + arr[i];
		prefix_double[i] = prefix_double[i - 1] + (arr[i] * arr[i]);
	}

	for (int k = 1; k <= n; k++) {
		long long ans = 1;
		long long m = 0;

		for (int i = 1; i + k - 1 <= n; i++) {
			long long a, b, c;

			a = prefix[i + k - 1] - prefix[i - 1];
			b = prefix_double[i + k - 1] - prefix_double[i - 1];

			c = b * k - (a * a);

			if (c > m) {
				ans = i;
				m = c;
			}
		}

		cout << ans << "\n";
	}
}