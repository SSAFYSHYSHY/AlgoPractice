#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		int e, r, n;
		cin >> e >> r >> n;

		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		vector<vector<int>> DP(n + 1, vector<int>(e + 1, 0));

		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j <= e; j++) {
				int best = 0;

				for (int k = 0; k <= j; k++) {
					int gain = k * v[i];
					int new_gain = min(e, j - k + r);

					best = max(best, gain + DP[i + 1][new_gain]);
				}

				DP[i][j] = best;
			}
		}
		cout << "Case #" << t << ": " << DP[0][e] << "\n";
	}


}