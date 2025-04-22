#pragma once
#include <iostream>
#include <algorithm>
#define MAX 10000000002

using namespace std;

int n, k, ans = 0;
int arr[5000001];

bool Calc(int mid) {
	int i = 0, cnt = 0;

	while (cnt < k && i < n) {
		i = upper_bound(arr, arr + n, arr[i] + mid) - arr;
		cnt++;
	}

	return i == n ? true : false;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int l = 1, r = arr[n - 1];


	while (l <= r) {
		int mid = (l + r) / 2;

		if (Calc(mid)) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << (l % 2 ? l / 2 + 1 : l / 2) << "\n";

}
