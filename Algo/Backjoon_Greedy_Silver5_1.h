#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ans = 0;
int arr[51];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + arr[i] > m) {
			ans++;
			sum = 0;
		}
		sum += arr[i];
	}

	if (sum > 0) {
		ans++;
	}

	cout << ans;
}