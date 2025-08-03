#pragma once
#include <iostream>
#include <algorithm>

using namespace std;


int n, m, c, ans;
int arr[100001];

bool Calc(int mid) {
	int cnt = 1;

	for (int i = 1, s = 0; i < n; i++) {
		if (i - s < c && arr[i] <= arr[s] + mid) continue;

		cnt++;
		s = i;
	}

	return cnt <= m;
}

int main() {
	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	int l = 0, r = 1000000000;

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
