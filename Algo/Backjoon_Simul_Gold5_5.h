#pragma once
#include <iostream>

using namespace std;

int n, dp[10001], t;

int main() {
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		for (int j = t; j >= x; j--) {
			dp[j] = max(dp[j], dp[j - x] + y);
		}
	}

	cout << dp[t];
}