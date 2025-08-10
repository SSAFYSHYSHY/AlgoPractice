#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[5001];

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int l = 0, r = n - 1;
	bool flag = false;

	while (l < r) {
		if (flag) break;

		for (int i = 0; i < n; i++) {
			if (i == l || i == r) continue;

			if (arr[l] == k || arr[r] == k || arr[i] == k) flag = true;
			else if (arr[l] + arr[r] == k) flag = true;
			else if (arr[l] + arr[r] + arr[i] == k) flag = true;
		}

		if (arr[l] + arr[r] < k) {
			l++;
		}
		else if (arr[l] + arr[r] > k) {
			r--;
		}
	}

	if (!flag) {
		cout << 0;
	}
	else {
		cout << 1;
	}
}