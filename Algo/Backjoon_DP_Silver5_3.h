#pragma once
#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int t, c, v, l;
long long dp[16];

int main() {
	cin >> t;

	for (int test = 1; test <= t; test++) {
		cin >> c >> v >> l;

		dp[0] = 1;
		dp[1] = v;

		for (int i = 2; i <= l; i++) {
			dp[i] = (dp[i - 1] * v % MOD + dp[i - 2] * c % MOD * v % MOD) % MOD;
		}

		cout << "Case #" << test << ": " << dp[l] << "\n";
	}
}
