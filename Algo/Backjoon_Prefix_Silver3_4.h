#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

long long n, l, ans = 0;
long long arr[200002];

int main() {
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n - 1, cnt = 1; i > 0; i--, cnt++) {
		ans += arr[i];

		if (abs(arr[i - 1] * cnt - ans) >= l * cnt) {
			cout << "unstable";
			return 0;
		}
	}

	cout << "stable";
}