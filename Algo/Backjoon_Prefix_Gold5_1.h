#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, h;

int main() {
	cin >> n >> h;

	vector<int> b(h + 1, 0);
	vector<int> t(h + 1, 0);
	vector<int> ans(h + 1, 0);

	for (int i = 0; i < n / 2; i++) {
		int x, y;
		cin >> x >> y;

		b[x]++;
		t[h + 1 - y]++;
	}

	for (int i = h - 1; i >= 1; i--) {
		b[i] += b[i + 1];
	}

	int mini = 987654321;
	int cnt = 0;

	for (int i = 1; i <= h; i++) {
		t[i] += t[i - 1];
		ans[i] += t[i] + b[i];

		if (mini > ans[i]) {
			cnt = 1;
			mini = ans[i];
		}
		else if (ans[i] == mini) {
			cnt++;
		}
	}

	cout << mini << " " << cnt;
}