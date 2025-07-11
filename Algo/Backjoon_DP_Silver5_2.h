#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];
int l[1000001];
int r[1000001];
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	l[0] = arr[0];
	for (int i = 1; i < n; i++) {
		l[i] = max(l[i - 1], arr[i]);
	}

	r[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i], arr[i]);
	}

	for (int i = 0; i < n; i++) {
		int left = (i == 0 ? arr[i] : l[i - 1]);
		int right = (i == n - 1 ? arr[i] : r[i + 1]);

		cout << max(arr[i], left) << " " << max(arr[i], right) << "\n";
	}
}