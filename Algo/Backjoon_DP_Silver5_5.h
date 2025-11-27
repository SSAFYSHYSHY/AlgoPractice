#pragma once
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, t;
int dp[51];
int arr[51];

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int lis = 0;
		for (int i = 0; i < n; i++) {
			dp[i] = 1;

			for (int j = 0; j < i; j++) {
				if (arr[j] < arr[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}

			lis = max(lis, dp[i]);
		}

		int ans = n - lis;

		cout << "Case #" << tc << ": " << ans << "\n";
	}

}
