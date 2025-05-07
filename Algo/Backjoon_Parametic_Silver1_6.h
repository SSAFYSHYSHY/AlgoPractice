#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double EPS = 1e-9;

bool Calc(int idx, double percent, const vector<int>& v, double total) {
	double score = v[idx] + total * percent;
	double remain = 1.0 - percent;

	for (int i = 0; i < v.size(); i++) {
		if (i == idx) {
			continue;
		}

		double need = max(0.0, (score - v[i]) / total);
		remain -= need;

		if (remain < -EPS) return false;
	}
	return true;
}

int main() {
	cout << fixed;
	cout.precision(6);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		double sum = 0.0;

		vector<int> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
			sum += v[i];
		}

		cout << "Case #" << tc << ":";
		for (int i = 0; i < n; i++) {
			double l = 0.0;
			double r = 1.0;
			double ans = 1.0;

			for (int j = 0; j < 100; j++) {
				double mid = (l + r) / 2;

				if (Calc(i, mid, v, sum)) {
					ans = mid;
					r = mid;
				}
				else {
					l = mid;
				}

			}

			cout << " " << ans * 100.0;
		}
		cout << "\n";
	}
}