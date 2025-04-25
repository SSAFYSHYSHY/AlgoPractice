#pragma once
#include <iostream>
#define MOD 1000000009

using namespace std;

int n;
long long dp[1000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;

	cin >> n;

	while (n--) {
		int num;
		cin >> num;

		for (int i = 3; i < num; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
		}

		cout << dp[num - 1] % MOD << "\n";
	}

}