#pragma once
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, ans = -INT_MAX;
int arr[301][301];
int prefix[301][301];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			prefix[i][j] = arr[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num = min(n - i, n - j);

			for (int k = 0; k <= num; k++) {
				int sum = prefix[i + k][j + k] - prefix[i - 1][j + k] - prefix[i + k][j - 1] + prefix[i - 1][j - 1];
				ans = max(ans, sum);
			}
		}
	}

	cout << ans;
}