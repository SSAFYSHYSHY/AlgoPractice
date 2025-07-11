#pragma once
#include <iostream>

using namespace std;

long long dp[46];

int main() {
	int t;

	cin >> t;

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 45; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	while (t--) {
		int a;
		cin >> a;

		cout << dp[a] << "\n";
	}


}