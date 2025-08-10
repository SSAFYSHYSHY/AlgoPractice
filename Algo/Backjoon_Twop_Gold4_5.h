#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, ans = 0;
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int l = 1, r = n;
	while (l < r) {

		int num = (r - l - 1) * (min(arr[l], arr[r]));
		ans = max(ans, num);

		if (arr[l] < arr[r]) {
			l++;
		}
		else {
			r--;
		}

	}


	cout << ans;
}