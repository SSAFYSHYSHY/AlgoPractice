#pragma once
#include <iostream>

using namespace std;

int n, k, p;
int arr[2501];

int main() {
	cin >> n >> k >> p;
	int m = n * k;

	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	for (int i = 0; i < m; i += k) {

		int one = 0;

		for (int j = i; j < i + k; j++) {
			if (arr[j] == 0) one++;
		}

		if (one < p) {
			ans++;
		}
	}

	cout << ans;
}