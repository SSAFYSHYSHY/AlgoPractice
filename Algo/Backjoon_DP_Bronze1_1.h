#pragma once
#include <iostream>

using namespace std;

long long dp[41], n;

int main() {
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];

}