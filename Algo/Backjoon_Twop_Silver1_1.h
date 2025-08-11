#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100001];
int ans = 0;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int l = 0, r = n - 1;

	while (l < r) {
		int sum = arr[l] + arr[r];

		if (sum >= m) ans++;

		l++;
		r--;
	}

	cout << ans;
}