#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = 0;

int main() {
	cin >> n;
	vector<int> v(n, 0);
	vector<int> c(10, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int l = 0, r = 0;

	while (r < n) {
		c[v[r++]]++;

		while (10 - count(c.begin(), c.end(), 0) > 2) {
			c[v[l++]]--;
		}

		ans = max(ans, r - l);
	}

	cout << ans;
}

