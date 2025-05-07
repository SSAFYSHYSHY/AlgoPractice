#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
	cin >> n;

	vector<int> v(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	vector<int> zero(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		zero[i] = zero[i - 1] + (v[i] == 0 ? 1 : 0);
	}

	vector<int> one(n + 2, 0);
	for (int i = n; i >= 1; i--) {
		one[i] = one[i + 1] + (v[i] == 1 ? 1 : 0);
	}

	int ans = n;

	for (int r = 0; r <= n; r++) {
		int cost = zero[r] + one[r + 1];
		ans = min(ans, cost);
	}
	cout << ans;
}