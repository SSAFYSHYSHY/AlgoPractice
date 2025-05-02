#pragma once
#pragma once
#include <iostream>
#include <vector>

using namespace std;

int n, k;

int main() {
	cin >> n >> k;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int l = 0, r = 0, cnt = 0, ans = 0;

	while (r < n) {
		if (cnt > k) {
			if (v[l] % 2 == 1) cnt--;
			l++;
		}
		else {
			if (v[r] % 2 == 1) cnt++;
			r++;
		}

		if (cnt <= k) {
			ans = max(ans, r - l - cnt);
		}
	}

	cout << ans;
}