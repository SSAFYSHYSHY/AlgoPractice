#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int main() {
	cin >> n >> m;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;

			v.push_back({ num,i });
		}
	}
	sort(v.begin(), v.end());

	vector<int> cnt(n, 0);
	int total = 0, r = 0, l = 0, ans = 21e8;

	while (r < v.size()) {
		if (cnt[v[r].second]++ == 0) total++;
		r++;

		while (total == n) {
			ans = min(ans, v[r - 1].first - v[l].first);
			if (--cnt[v[l].second] == 0) total--;
			l++;
		}
	}

	cout << ans;


}
