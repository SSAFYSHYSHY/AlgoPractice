#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, L;
vector<int> v;

void Input() {
	cin >> n >> m >> L;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}
	sort(v.begin(), v.end());
}

bool Calc(int mid, int cut) {
	int cutcnt = 0;
	int cutidx = 0;

	for (int i = 0; i < m && cutcnt < cut; i++) {
		if (v[i] - cutidx >= mid) {
			cutcnt++;
			cutidx = v[i];
		}
	}

	if (cutcnt == cut && L - cutidx >= mid) {
		return true;
	}
	return false;
}

int main() {

	Input();

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		int l = 1, r = L, ans = L;

		while (l <= r) {
			int mid = (l + r) / 2;

			if (Calc(mid, num)) {
				ans = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		cout << ans << "\n";
	}
}