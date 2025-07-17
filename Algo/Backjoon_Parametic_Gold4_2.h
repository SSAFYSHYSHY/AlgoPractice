#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int h, w, m, k;
vector<pair<int, int>> v;

bool Calc(int num) {
	int cnt = 1;
	//¿ŞÂÊ x ÁÂÇ¥.
	int left = v[0].second;

	for (int i = 1; i < k; i++) {
		if (v[i].first > num) {
			return false;
		}
		if (left + num - 1 < v[i].second) {
			left = v[i].second;
			cnt++;
		}
	}

	if (cnt > m) {
		return false;
	}

	return true;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	cin >> h >> w >> m >> k;

	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		v.push_back({ r,c });
	}
	sort(v.begin(), v.end(), cmp);

	int l = 1, r = max(h, w);
	int ans = r;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (Calc(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;
}