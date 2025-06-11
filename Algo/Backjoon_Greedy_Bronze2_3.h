#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[1001];

	int ans = 0;
	int mini = 1001;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans += arr[i];

		if (arr[i] % 2 == 1) {
			mini = min(mini, arr[i]);
		}
	}

	if (ans % 2 == 0) {
		cout << ans << "\n";
	}
	else if (mini != 1001) {
		cout << ans - mini << "\n";
	}
	else {
		cout << 0 << '\n';
	}
}