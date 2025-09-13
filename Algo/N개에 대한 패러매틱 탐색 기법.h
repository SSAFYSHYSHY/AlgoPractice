#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, c, arr[10000001];

bool Calc(int dist) {
	int num = arr[0];
	int cnt = c - 1;

	for (int i = 1; i < n; i++) {
		if (arr[i] - num >= dist) {
			num = arr[i];
			cnt--;

			if (cnt == 0) {
				return true;
			}
		}
	}

	return cnt == 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int left = 1, right = arr[n - 1];

	while (left <= right) {
		int mid = (left + right) / 2;

		if (Calc(mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << right;
}